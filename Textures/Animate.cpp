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

    ( (int)NowIndex < SizeTextureArray) ? NowIndex += SpeedAnimate : NowIndex = 0;
    if(NowIndex >= SizeTextureArray){
        NowIndex = 0;
    }
    // cout << "Now index: " << (int)NowIndex << " - " << "Texture array: " << AnimateIndex[(int)NowIndex] << endl;
}




