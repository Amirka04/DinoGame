#include "Animate.hpp"


#include <iostream>
#include <fstream>

using namespace std;




Animate::Animate(){
    cout << "Загрузка текстур: " << endl;
}


Animate::Animate(const char* folder, float uSpeedAnimate):SpeedAnimate(uSpeedAnimate){
    cout << "Загрузка текстур: " << endl;

    // потребуется для открытия файла
    string path = folder;
    string name_init = "animate.dat";

    ifstream AnimateFiles(path + name_init);
    if(!AnimateFiles.is_open()){
        cout << "Файл не получилось открыть, проверь, есть ли файл в каталоге или проверь правильность пути" << endl;
    }
    

    char a[20][100];
    SizeTextureArray = 0;
    for(int i = 0; i < 20; i++){
        AnimateFiles.getline(a[i], 100, '\n');
        if(a[i][0] != '\0'){
            SizeTextureArray++;
        }
    }

    cout << "Количество изображений: " << SizeTextureArray << endl;

    AnimateIndex = new uint[SizeTextureArray];
    for(int i = 0; i < SizeTextureArray; i++){
        string namefile = a[i];
        cout << path + namefile << endl;
        AnimateIndex[i] = TexturesInit( (path + namefile).c_str() );
    }
}



void Animate::RunAnimation(){
    Init();

    ( (int)NowIndex < SizeTextureArray) ? NowIndex += SpeedAnimate : NowIndex = 0;
    if(NowIndex >= SizeTextureArray){
        NowIndex = 0;
    }
    // cout << "Now index: " << (int)NowIndex << " - " << "Texture array: " << AnimateIndex[(int)NowIndex] << endl;
}