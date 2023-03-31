#include "Animate.hpp"


#include <iostream>
#include <fstream>

using namespace std;




Animate::Animate(){
    cout << "Texture load: " << endl;
}

Animate::~Animate(){
}

Animate::Animate(char* folder, float uSpeedAnimate):SpeedAnimate(uSpeedAnimate){
    cout << "Texture load: " << endl;

    // потребуется для открытия файла
    string path = folder;

    ifstream AnimateFiles(path + "animate.dat");
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

    cout << "Size image: " << SizeTextureArray << endl;

    AnimateIndex = new uint[SizeTextureArray];
    for(int i = 0; i < SizeTextureArray; i++){
        string namefile = a[i];
        cout << path + namefile << endl;
        AnimateIndex[i] = TexturesInit( (path + namefile).c_str() );

        }

}



void Animate::RunAnimation(){
    Init();

    if(NowIndex == 4){
        NowIndex = 0;
    }
    ( (int)NowIndex < SizeTextureArray) ? NowIndex += SpeedAnimate : NowIndex = 0;
    // cout << "Now index: " << (int)NowIndex << " - " << "Texture array: " << AnimateIndex[(int)NowIndex] << endl;

}