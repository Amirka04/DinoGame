#include "Animate.hpp"

#include <iostream>
#include <fstream>

using namespace std;


// конструктор без параметров
Animate::Animate(){
    cout << "Загрузка текстур: " << endl;
}

Animate::Animate(const char* folder, float uSpeedAnimate):SpeedAnimate(uSpeedAnimate){
    cout << "Загрузка текстур: " << endl;

    // потребуется для открытия файла
    string path = folder;
    string name_init = "animate.dat";
    
    // Открываю файл содержащий информацию для анимации
    ifstream AnimateFiles(path + name_init);
    if(!AnimateFiles.is_open()){
        cout << "Файл не получилось открыть, проверь, есть ли файл в каталоге или проверь правильность пути, файл в директории должен называться \"animate.dat\"" << endl;
    }
    
    // Массив для хранения названий файлов для анимации
    char a[20][100];
    SizeTextureArray = 0;
    for(int i = 0; i < 20; i++){
        AnimateFiles.getline(a[i], 100, '\n');
        if(a[i][0] != '\0'){
            SizeTextureArray++;
        }
    }

    cout << "Количество изображений: " << SizeTextureArray << endl;

    // выведем все изображения и загрузим каждую в видеокарту, где потом будем использовать индексы этих изображений
    AnimateIndex = new uint[SizeTextureArray];
    for(int i = 0; i < SizeTextureArray; i++){
        string namefile = a[i];
        cout << path + namefile << endl;
        AnimateIndex[i] = TexturesInit( (path + namefile).c_str() );
    }
}

// Запуск анимации
void Animate::RunAnimation(){
    Init();

//  Будем гонять индекс с начала до конца, что и позволит достичь нам анимации, индекс будет типа float,
    if( NowIndex < SizeTextureArray - 0.01)
        NowIndex += SpeedAnimate;
    else
        NowIndex = 0.1;

    // Тут мы меняем скорость воспроизведения анимации
    if(SpeedAnimate < Animate::MaxSpeedAnimate){
        if(!isLocallInit)
            SpeedAnimate += Animate::A;
        else
            SpeedAnimate += LocalA;
    }
}


// инициализация глобальных членов класса
// глобальных в том смысле, что они будут действовать для всей анимации в игре
float Animate::MaxSpeedAnimate = 0;
float Animate::A = 0;
void Animate::SetGlobalInit(float u_MaxSpeedAnimate, float u_A){
    MaxSpeedAnimate = u_MaxSpeedAnimate;
    A = u_A;
}


// Установка начальных настроек для локальной анимации, то есть анимации скорость которой будет не зависеть от скорости других
void Animate::LocalInit(float LocalMaxSpeedAnimate, float LocalA){
    // даём знать, что мы инициализировали скорость и ускорение анимации локально
    isLocallInit = 1;

    this->LocalMaxSpeedAnimate = LocalMaxSpeedAnimate;
    this->LocalA = LocalA;
}



