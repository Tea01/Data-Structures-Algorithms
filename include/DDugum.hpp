

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
