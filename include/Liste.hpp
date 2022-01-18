/** 
* @file                         B191210555
* @description                  .txt dosyadan verileri okuyup istenilen indisten ekleme ve silme işlemi yaparak ekrana verileri yazdırır(iki yönlü bağlı liste kullanarak)
* @course                       1. Öğretim C Grubu
* @assignment                   1. Ödev
* @date                         12/11/2021
* @author                       Tea Shkurti | E-posta: tea.shkurti@ogr.sakarya.edu.tr
*/

#ifndef Liste_hpp
#define Liste_hpp
#include "DDugum.hpp"
#include <string>

class Liste
{
private:
    DDugum* ilk;
public:
    Liste();                              //kurucu fonksiyon
    ~Liste();                             //yok edici fonksiyon
    void ekle(string veri,int sira);      //duğume ekleniyor
    void cikar(int sira);                 //istenilen indise düğümeyi çıkartıyor
    void yazdir();                        //sonuçları yazdırıyor
    int dugumSayisi ();                   //Düğüm sayısını tutuyor
    DDugum* dugumeGetir(int sira);        //istenilen indisten düğüme getiriliyor
};

#endif