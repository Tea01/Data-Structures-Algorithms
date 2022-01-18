/** 
* @file                         B191210555
* @description                  .txt dosyadan verileri okuyup istenilen indisten ekleme ve silme işlemi yaparak ekrana verileri yazdırır(iki yönlü bağlı liste kullanarak)
* @course                       1. Öğretim C Grubu
* @assignment                   1. Ödev
* @date                         12/11/2021
* @author                       Tea Shkurti | E-posta: tea.shkurti@ogr.sakarya.edu.tr
*/

#ifndef DDugum_hpp
#define DDugum_hpp
#include <iostream>
#include <string>

using namespace std;

class DDugum
{
public:
    DDugum(string veri);                  //kurucu fonskiyon
    string veri;                          //girilecek veri değerini tutacak
    DDugum* sonraki;                      //duğumelerde sonraki ve onceki adrelseri tutmak için
    DDugum* onceki;
};

#endif