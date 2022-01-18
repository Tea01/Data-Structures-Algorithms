/** 
* @file                         B191210555
* @description                  .txt dosyadan verileri okuyup istenilen indisten ekleme ve silme işlemi yaparak ekrana verileri yazdırır(iki yönlü bağlı liste kullanarak)
* @course                       1. Öğretim C Grubu
* @assignment                   1. Ödev
* @date                         12/11/2021
* @author                       Tea Shkurti | E-posta: tea.shkurti@ogr.sakarya.edu.tr
*/

#include "DDugum.hpp"

DDugum::DDugum(string veri)
{
    this->veri=veri;
    onceki=sonraki=0;                 //düğüm kimseyi göstermiyor. pointerlar=0
}