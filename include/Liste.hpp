
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
