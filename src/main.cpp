/** 
* @file                         B191210555
* @description                  .txt dosyadan verileri okuyup istenilen indisten ekleme ve silme işlemi yaparak ekrana verileri yazdırır(iki yönlü bağlı liste kullanarak)
* @course                       1. Öğretim C Grubu
* @assignment                   1. Ödev
* @date                         12/11/2021
* @author                       Tea Shkurti | E-posta: tea.shkurti@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <Windows.h>                                             //Türkçe harfler yazdırmak için
#include <string>
#include <fstream>                                               //dosyalama yapabilmek için kütüphanesi
#include "Liste.hpp"
#include "DDugum.hpp"

using namespace std;

int main()
{
	SetConsoleOutputCP(65001);                                //Türkçe karakterler yazdırmak için

	Liste* liste=new Liste;						              //Liste sınıfından bir nesne oluşturuldu

    ifstream dosyadanOku("doc/Veri.txt");                     //Veri dosyayı açar

	string satir="";
  
	while (!dosyadanOku.eof())                   			  //Eğer dosya'nın sonu değilse döngüye gir
	{
		getline(dosyadanOku, satir);             			  //dosyadan satır satır verileri okuyor

		//Dosyada "("  "#"  ")" karakterleri bulunuyor
        unsigned first = satir.find("(");       
		unsigned middle = satir.find("#");
		unsigned last = satir.find(")");

        string harf = satir.substr(0, first);                              //İlk harfi buluyor

		string indes = satir.substr(first + 1, (middle - first - 1));     //eklenecek indis değerini buluyor
        string veri = satir.substr(middle + 1, (last - middle - 1));      //istenilen veriyi buluyor

		string silIndeks = satir.substr(first + 1, last - 2);             //Silinecek indis değerini buluyor

		if (harf=="E" || harf=="e")
		{

            liste->ekle(veri,stoi(indes));					//Ekle Fonksiyonu çağırıldı

		}
		else if(harf=="S" || harf=="s")
		{

            liste->cikar(stoi(silIndeks));                 //Cikar Fonksiyonu çağırıldı
		}
		else
			cout << "Girilen veriler bulunamadı!" << endl;         //Eğer "E"/ "e" veya "S"/"s" harfleri yazılmamışsa bu komut ekrana yazdırılacak
	}
	
		
	if (!dosyadanOku.is_open())                             //Eğer dosya açık değilse fonksiyonu
	{
		cout << "Dosya açılamadı!" << endl;
		exit(-1);
	}


	dosyadanOku.close();                               //Dosyayı kapatılıyor

	liste->yazdir();                                   //Ekrana yazdir fonksiyonu çıkartıyor.

	delete liste;                                     //Yok edici fonksiyonu çağırayarak bellekte tuttuğumuz yeri siliyoruz. 

	//cin.get();      //to pause the program

}