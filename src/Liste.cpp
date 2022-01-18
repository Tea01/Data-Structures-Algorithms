/** 
* @file                         B191210555
* @description                  .txt dosyadan verileri okuyup istenilen indisten ekleme ve silme işlemi yaparak ekrana verileri yazdırır(iki yönlü bağlı liste kullanarak)
* @course                       1. Öğretim C Grubu
* @assignment                   1. Ödev
* @date                         12/11/2021
* @author                       Tea Shkurti | E-posta: tea.shkurti@ogr.sakarya.edu.tr
*/

#include "Liste.hpp"
#include <iostream>

using namespace std;

//Liste sınıfın kurucusu
Liste::Liste()                             
{
    ilk=0;                                       //listem oluşturulduğu an ilk pointer'in 0 atıyorum
}

//Liste sınıfın yok edici fonksiyonu
Liste::~Liste()
{
    DDugum* gec=ilk;                            //ilk düğümü kaybetmemek için

    while (gec!=0)
    {
        DDugum* sil = gec;                    
        gec=gec->sonraki;

        delete sil;
    } 
}

//Ekleme Fonksiyonu
void Liste::ekle(string veri, int sira)
{
    DDugum* yeniDugum=new DDugum(veri);            //yeni bir duğum oluşturuldu

    if(ilk==0)                                     //Eğer düğüm yoksa hemen yeni bir düğüm oluşturulur
    {
        ilk=yeniDugum;
        return;
    }

    int dugumSayisiTut = dugumSayisi();           //Düğüm sayısını bir değişkene tutuyorum 

    DDugum* gec= ilk;                             //İlk düğümü kaybetmemek için

    while(gec->sonraki!=0)                       //Döngü sonuna en son düğümü erişebiliriz
    {
        gec=gec->sonraki;
    }

//Sonunda eklenen yeni düğüm ile bağlantıyı kuruyoruz
    gec->sonraki = yeniDugum;                    //son düğümün sonraki adresinde yeni düğümün adresi atıyorum
    yeniDugum->onceki = gec;                     //yeni düğümün önceki adresinde önceki düğümün adresini atıyorum

//Eğer girilen sıra, bulunan düğüm sayısından büyük ise veya sıfırdan küçük ise fonksiyondan çık
    if (sira > dugumSayisiTut || sira < 0 )      
    {
        return;
    }
//Eğer değilse o zaman istenilen indesten tek tek sağa doğru en son düğümeye kadar verileri kaydırıyorum ve istenilen indese yeni verileri yazarım.
    else                                        
    {
        DDugum* eklenecekDugum= dugumeGetir(sira);           

        gec=yeniDugum;

        while (gec!=eklenecekDugum)
        {
            gec->veri=gec->onceki->veri;

            gec=gec->onceki;            
        }
        gec->veri = veri;        
    }   
}
//Silme fonksiyonu
void Liste::cikar(int sira)
{
    if(ilk==0)              //eğer hiç düğüme yoksa fonksiyondan çık        
    {
        return;
    }

    int dugumSayisiTut = dugumSayisi();         //düğümelerin sayısını tutan bir değişken tanımladım
    
    if(ilk->sonraki==0)                         //eğer tek bir düğüme varsa o düğümeyi siliyorum
    {
        delete ilk;
        ilk=0;                                 //listem boş olduğunu belirtiyor
        return;
    }

    DDugum* gec= ilk;                    //ilk düğümün kaybolmamak için

    while (gec->sonraki!=0)              //son düğümeyi erişiyorum
    {
        gec=gec->sonraki;
    }
//Eğer girilen sıra, bulunan düğüm sayısından büyük eşit ise veya sıfırdan küçük ise o zaman sondan bir önceki düğümenin sonraki adresi 0 yapıyorum ve son düğümeyi siliyorum
    if(sira >= dugumSayisiTut || sira < 0)      
    {
        gec->onceki->sonraki=0;
        delete gec;   
        return;
    }
//Eğer değilse o zaman son düğümeden tek tek sola doğru istenilen indiseye kadar verileri kaydırıyorum ve son düğümeyi siliyorum.
    else
    {
        DDugum* silinecekIndex = dugumeGetir(sira);

        while (silinecekIndex != gec)
        {
            silinecekIndex->veri = silinecekIndex->sonraki->veri;
            silinecekIndex = silinecekIndex->sonraki;   
        }   

        silinecekIndex->onceki->sonraki = 0;                           //sondan bir önceki düğümün sonraki adresi 0 yazar

        delete silinecekIndex;
    }
}
//Düğüm sayısını tutan bir fonksiyon
int Liste:: dugumSayisi ()                       
{
    DDugum* gec = ilk;

    int sayac = 0;

    while (gec != 0)
    {
        gec = gec->sonraki;
        sayac++;
    }
    return sayac;
}
//Istenilen indisten, düğüm getiren bir fonksiyondur
DDugum* Liste::dugumeGetir(int index)                     //istenilen sıradan düğüm getirir
{
    DDugum* gec = ilk;
    
    while(index >=0 && gec!=0)
    {
        if(index==0)
        {
            return gec;
        }
        gec=gec->sonraki;
        index--;
    }
    return 0;
}
//Ekrana verileri yazdıran fonksiyondur
void Liste:: yazdir()
{
    DDugum* gec=ilk;

    cout<<endl<<"Listede Bulunan Veriler:"<<endl;

    while(gec!=0)
    {
        if(gec->onceki==0)
        {
           cout << gec->veri;
        }
        else
        {
        cout<<"<--->"<< gec->veri;
        }

        gec=gec->sonraki;
    }
    cout<<endl<<endl<<endl;
}