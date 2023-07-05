#include <iostream> 
#include <locale.h> //Türkçe karakterler kullanabilmek için eklediðim kütüphane
#include <time.h> // time ifadesini kullanabilmek için kullandýðým kütüphane
#include <string>
#include <cmath> // matematiksel iþlemler için
using namespace std;
const int uye = 30;
float notCevirme(string oku, float notu); // 100'lük deðerdeki notu harf notuna çevirmek için yazdým. Fonksiyonun içeriðini mainin altýnda girdim
float notKontrol(string s, float min, float max); // notun 0-100 arasýnda olup olmadýðýný kontrol eden fonksiyon. Fonksiyonun içeriðini mainin altýnda girdim

struct Tarih
{			// doðum tarihi için struct tarih veri tipi oluþturdum
	int gun, ay, yil;
};

struct ogrenci
{		// öðrencilerin isim, soyisim ve puanlarý için struct ogrenci veri tipi oluþturdum
	string isim[100], soyisim[100];
	float ogrenciNo[100], kisaSinav1[100], kisaSinav2[100], odev1[100], odev2[100], proje[100], vize[100], final[100], basariNotu[100];
};


int main() {
	srand(time(NULL)); // her çalýþtýrýldýðýnda ayný diziyi oluþturmamasý için ekledim

	setlocale(LC_ALL, "Turkish"); //Türkçe karakterleri kullanmak için

	string isimler[uye] = { "Özgür", "Kaan", "Erhan", "Emir", "Emre", "Eser", "Furkan", "Güray", "Fýrat", "Fatih", "Tunahan", "Selin", "Elif", "Ceyda", "Mehmet", "Yunus", "Mert", "Mete", "Merve", "Eren", "Ceren", "Yasemin", "Seda", "Sýla", "Melisa", "Pýnar", "Ahmet", "Gökhan", "Oðuz","Baþak" };
	string soyisimler[uye] = { "Özdemir", "Selimoðlu", "Aksoy", "Aydýn", "Akbey", "Kaya", "Balkaya", "Okutay", "Sepetci", "Yalmancý", "Çakýr", "Þahin", "Gökdemir", "Odabaþý", "Yýldýz", "Girgin", "Balcýbaþý", "Ayaz", "Sarýtaþ","Þiþman", "Türkmen", "Sarýsoy", "Göken", "Aydýn", "Kurtuluþ", "Ersoy", "Koçak", "Yýlmaz","Keskin","Altunýþýk" };
	ogrenci ogrenciler;
	char secim1, secim2;
	bool kontrol = 1;
	while (kontrol)
	{
		cout << "1.Seçenek: Öðrenci bilgileri rastgele atansýn.[1]\n2.Seçenek: Öðrenci bilgileri manuel girilsin.[2]" << endl << " Tercih: ";
		cin >> secim1;

		if (!(secim1 == '1' || secim1 == '2'))
			cout << "Hatalý giriþ yaptýnýz. Tekrar Deneyiniz." << endl;
		else
			kontrol = 0;
	}

	if (secim1 == '1') // öðrenci bilgilerinin rastgele atanmasýný isterse bu koþul saðlanacak
	{

		system("cls");		// önceki menü ekranýnýn silinmesi için

		for (int i = 0; i < 100; i++) //random bir þekilde öðrenci bilgilerinin daðýtýlmasý için for döngüsü kullandým
		{
			int gecici1, gecici2;
			gecici1 = rand() % 30;					      // gecici bir int deðeri tanýmlayýp içine rastgele 0-30 arasýnda sayý atanmasý için yazdým
			gecici2 = rand() % 30;						  // gecici bir int deðeri tanýmlayýp içine rastgele 0-30 arasýnda sayý atanmasý için yazdým
			ogrenciler.isim[i] = isimler[gecici1];        // içine rastgele sayý atanan gecici deðerinin isimler dizisinde karþýlýk gelen isim, ogrenciler struct veri tipindeki isim dizisine girildi
			ogrenciler.soyisim[i] = soyisimler[gecici2];  // içine rastgele sayý atanan gecici deðerinin soyisimler dizisinde karþýlýk gelen soyisim, ogrenciler struct veri tipindeki soyisim dizisine girildi
			ogrenciler.ogrenciNo[i] = i + 1;			  // 100 öðrenciye 1-100 arasýnda öðrenci numarasý atandý


			if (i >= 0 && i < 10)
			{						  // öðrencilerin %10'unun notlarýnýn 0-40 arasýnda olmasýný saðlar
				ogrenciler.final[i] = rand() % 40;
				ogrenciler.vize[i] = rand() % 40;
				ogrenciler.kisaSinav1[i] = rand() % 40;
				ogrenciler.kisaSinav2[i] = rand() % 40;
				ogrenciler.odev1[i] = rand() % 40;
				ogrenciler.odev2[i] = rand() % 40;
				ogrenciler.proje[i] = rand() % 40;
			}

			else if (i >= 10 && i < 60) {					// öðrencilerin %50'sinin notlarýnýn 40-70 arasýnda olmasýný saðlar
				ogrenciler.final[i] = rand() % (70 - 41 + 1) + 41;
				ogrenciler.vize[i] = rand() % (70 - 41 + 1) + 41;
				ogrenciler.kisaSinav1[i] = rand() % (70 - 41 + 1) + 41;
				ogrenciler.kisaSinav2[i] = rand() % (70 - 41 + 1) + 41;
				ogrenciler.odev1[i] = rand() % (70 - 41 + 1) + 41;
				ogrenciler.odev2[i] = rand() % (70 - 41 + 1) + 41;
				ogrenciler.proje[i] = rand() % (70 - 41 + 1) + 41;
			}

			else if (i >= 60 && i < 75) {			     // öðrencilerin %15'inin notlarýnýn 70-80 arasýnda olmasýný saðlar
				ogrenciler.final[i] = rand() % (80 - 71 + 1) + 71;
				ogrenciler.vize[i] = rand() % (80 - 71 + 1) + 71;
				ogrenciler.kisaSinav1[i] = rand() % (80 - 71 + 1) + 71;
				ogrenciler.kisaSinav2[i] = rand() % (80 - 71 + 1) + 71;
				ogrenciler.odev1[i] = rand() % (80 - 71 + 1) + 71;
				ogrenciler.odev2[i] = rand() % (80 - 71 + 1) + 71;
				ogrenciler.proje[i] = rand() % (80 - 71 + 1) + 71;
			}

			else if (i >= 75 && i < 100) {				// öðrencilerin %25'inin notlarýnýn 80-100 arasýnda olmasýný saðlar
				ogrenciler.final[i] = rand() % (100 - 81 + 1) + 81;
				ogrenciler.vize[i] = rand() % (100 - 81 + 1) + 81;
				ogrenciler.kisaSinav1[i] = rand() % (100 - 81 + 1) + 81;
				ogrenciler.kisaSinav2[i] = rand() % (100 - 81 + 1) + 81;
				ogrenciler.odev1[i] = rand() % (100 - 81 + 1) + 81;
				ogrenciler.odev2[i] = rand() % (100 - 81 + 1) + 81;
				ogrenciler.proje[i] = rand() % (100 - 81 + 1) + 81;
			}
		}

		for (int i = 0; i < 100; i++) // öðrencilerin baþarý notlarýný hesaplamak için for döngüsü ekledim
		{
			float yil_iciNot = ogrenciler.vize[i] * 0.5
				+ ogrenciler.kisaSinav1[i] * 0.07
				+ ogrenciler.kisaSinav2[i] * 0.07
				+ ogrenciler.odev1[i] * 0.1
				+ ogrenciler.odev2[i] * 0.1
				+ ogrenciler.proje[i] * 0.16;

			ogrenciler.basariNotu[i] = yil_iciNot * 0.55 + ogrenciler.final[i] * 0.45;
		}

		while (1) //kullanýcý çýkmak isteyene kadar menüye döndürsün diye sonsuz döngü ekledim
		{
			float enYuksek = ogrenciler.basariNotu[0];
			float enDusuk = ogrenciler.basariNotu[0];

			cout << "[1] Sýnýf listesi yazdýrýlsýn\n[2] Sýnýfýn en yüksek notu hesaplansýn\n[3] Sýnýfýn en düþük notu hesaplansýn\n[4] Sýnýf ortalamasý hesaplansýn";
			cout << "\n[5] Sýnýfýn standart sapmasý hesaplansýn\n[6] Baþarý notu belirli aralýkta olan öðrencileri sýralamak için";
			cout << "\n[7] Baþarý notu belirtilen deðerin altýnda olan öðrencilerin sýralanmasý için\n[8] Baþarý notu belirtilen deðerin üstünde olan öðrencilerin sýralanmasý için";
			cout << "\n[Q] Çýkýþ yapmak için" << endl;

			cin >> secim2;

			if (secim2 == 'Q' || secim2 == 'q') // kullanýcý Q veya q harfini girerse çýkýþ yapar
				break;

			else if (secim2 == '1') // kullanýcý 1'e basarsa sýnýf listesini bastýrýr
			{
				system("cls");
				for (int i = 0; i < 100; i++)
				{
					cout << ogrenciler.ogrenciNo[i] << " " << ogrenciler.isim[i] << " " << ogrenciler.soyisim[i] << " Baþarý notu: " << ogrenciler.basariNotu[i] << endl;

					if (i == 19) {			// 20 öðrenci basýldýðýnda program durur ve kullanýcýnýn herhangi bir tuþa basmasýný ister
						system("pause");
						system("cls");
					}
					if (i == 39) {		// 20 öðrenci basýldýðýnda program durur ve kullanýcýnýn herhangi bir tuþa basmasýný ister
						system("pause");
						system("cls");
					}
					if (i == 59) {			// 20 öðrenci basýldýðýnda program durur ve kullanýcýnýn herhangi bir tuþa basmasýný ister
						system("pause");
						system("cls");
					}
					if (i == 79) {			// 20 öðrenci basýldýðýnda program durur ve kullanýcýnýn herhangi bir tuþa basmasýný ister
						system("pause");
						system("cls");
					}
					if (i == 99) {			// 20 öðrenci basýldýðýnda program durur ve kullanýcýnýn herhangi bir tuþa basmasýný ister
						system("pause");
						system("cls");
					}


				}
			}


			else if (secim2 == '2')
			{
				int d; // hangi öðrencinin en yüksek nota sahip olduðunu belirtebilmek için tanýmladým
				system("cls");

				for (int i = 0; i < 100; i++) /*döngü basariNotu dizisinin tüm elemanlarýndan geçecek eðer basariNotu[i], enYuksek'ten büyükse
											  enYuksek'in yeni deðeri basariNotu[i] olacak. Bu þekilde en yüksek baþarý notu bulunmuþ olunacak*/
				{
					if (ogrenciler.basariNotu[i] > enYuksek)  //döngü basariNotu dizi elemanlarý içinde geçerken eðer eleman enYuksek deðerinden büyükse yeni enYuksek deðeri o eleman olur
					{
						enYuksek = ogrenciler.basariNotu[i];
						d = i;
					}
				}
				cout << "En yüksek baþarý puan, " << enYuksek << " puan ile " << ogrenciler.ogrenciNo[d] << " Nolu " << ogrenciler.isim[d] << " " << ogrenciler.soyisim[d] << " adlý öðrenciye aittir. " << endl;
				system("pause");
				system("cls");
			}
			else if (secim2 == '3')  /*Döngü basariNotu dizisinin tüm elemanlarýndan geçecek eðer basariNotu[i], enuDusuk'ten kucukse enDusuk'un yeni deðeri basariNotu[i] olur*/
			{
				int a = 0;
				system("cls");

				for (int i = 99; i >= 0; i--)
				{
					if (ogrenciler.basariNotu[i] < enDusuk) {	//eðer basariNotu[i], enuDusuk'ten kucukse enDusuk'un yeni deðeri basariNotu[i] olur 
						enDusuk = ogrenciler.basariNotu[i];
						a = i;
					}
				}
				cout << "En düþük baþarý puan, " << enDusuk << " puan ile " << ogrenciler.ogrenciNo[a] << " Nolu " << ogrenciler.isim[a] << " " << ogrenciler.soyisim[a] << " adlý öðrenciye aittir. " << endl;
				system("pause");
				system("cls");
			}

			else if (secim2 == '4') // Sýnýf ortalamasýný bulmak için
			{
				system("cls");
				float ortalama = 0;
				for (int i = 0; i < 100; i++) //i arttýkça basariNotu'nun yeni deðerini ortalama isimli deðiþkene ekleyecek
					ortalama += ogrenciler.basariNotu[i];

				cout << "Sýnýfýn Not ortalamasý: " << ortalama / 100 << endl;
				system("pause");
				system("cls");
			}

			else if (secim2 == '5') // eðer kullanýcý 5 deðerini girerse sýnýfýn standart sapmasýný hesaplayacak
			{
				system("cls");
				float toplam = 0, ort, islem, sonuc = 0;
				for (int i = 0; i < 100; i++)  // i arttýkça basariNotu'nun yeni deðerini toplam adlý deðiþkene atayacak
					toplam += ogrenciler.basariNotu[i];
				ort = toplam / 100;

				for (int j = 0; j < 100; j++)   // her öðrencinin basariNotu'nu aritmetik ortalamadan çýkarýp karesini alýnacak ve sonuc adlý deðiþkene ekleyecek
				{
					islem = (ogrenciler.basariNotu[j] - ort) * (ogrenciler.basariNotu[j] - ort);
					sonuc += islem;
				}
				cout << "Sýnýfýn standart sapmasý: " << sqrt(sonuc / 99) << endl;   // sonuc öðrenci sayýsýnýn 1 eksiðine bölünüp karekökünü alýnacak
				system("pause");
				system("cls");
			}

			else if (secim2 == '6') // secim2'de 6 deðeri girilirse kullanýcýýn belirlediði 2 sayý arasýndaki notlara sahip öðrenciler ekrana bastýrýlacak
			{
				system("cls");
				float sayi1 = 0, sayi2 = 0;
				cout << "Aralýðýn baþlangýç deðeri: "; cin >> sayi1;
				cout << "Aralýðýn bitiþ deðeri: "; cin >> sayi2;
				system("cls");

				for (int i = 0; i < 100; i++) {
					if (ogrenciler.basariNotu[i] >= sayi1 && ogrenciler.basariNotu[i] <= sayi2)  // döngü tüm basariNotlarý dizisini gezecek ve eðer sayý kullanýcýnýn belirlediði aralýktaysa ekrana bastýracak
						cout << ogrenciler.ogrenciNo[i] << " " << ogrenciler.isim[i] << " " << ogrenciler.soyisim[i] << " " << ogrenciler.basariNotu[i] << endl;
				}
				system("pause");
				system("cls");
			}

			else if (secim2 == '7')  //secim2'de 7 deðeri girilirse kullanýcýnýn belirlediði sayýnýn altýndaki notlara sahip öðrenciler ekrana basýlacak
			{
				system("cls");
				float sayi;
				cout << "Hangi deðerin altýndaki sayýlarý ekrana yazýlsýn: "; cin >> sayi;

				for (int i = 0; i < 100; i++) {
					if (sayi > ogrenciler.basariNotu[i])  // döngü basariNotu dizisini gezecek eðer sayý kullanýcýnýn belirlediði deðerin altýndaysa ekrana bastýrýr
						cout << ogrenciler.ogrenciNo[i] << " " << ogrenciler.isim[i] << " " << ogrenciler.soyisim[i] << " " << ogrenciler.basariNotu[i] << endl;
				}
				system("pause");
				system("cls");
			}

			else if (secim2 == '8') // secim2'de 8 deðeri girilirse kullanýcýnýn belirlediði sayýnýn üstündeki notlara sahip öðrenciler ekrana basýlacak
			{
				system("cls");
				float sayi3;
				cout << "Hangi deðerin üstündeki sayýlar ekrana yazýlsýn: "; cin >> sayi3;

				for (int i = 0; i < 100; i++) {
					if (sayi3 < ogrenciler.basariNotu[i]) // döngü basariNotu dizisini gezecek eðer sayý kullanýcýnýn belirlediði deðerin üstündeyse ekrana bastýrýr
						cout << ogrenciler.ogrenciNo[i] << " " << ogrenciler.isim[i] << " " << ogrenciler.soyisim[i] << " " << ogrenciler.basariNotu[i] << endl;
				}
				system("pause");
				system("cls");
			}

		}


	}

	else if (secim1 == '2') // kullanýcý secim1'de 2 deðerini girerse 2.Seçenek (öðrenci bilgilerini kullanýcýnýn kendisi girdiði seçenek) devreye girecek
	{
		system("cls");
		for (int i = 0; i < 100; i++)
		{

			string isim, soyisim;
			cout << i + 1 << ". Öðrencinin Adý: " << endl;
			cin >> ogrenciler.isim[i];
			cout << i + 1 << ". Öðrencinin Soyadý: " << endl;
			cin >> ogrenciler.soyisim[i];


			ogrenciler.ogrenciNo[i] = i + 1;

			while (1) {			// kullanýcý 0-100 arasýnda bir sayý girene kadar döngüden çýkamaz
				cout << "1.Kýsa sýnav notu: ";
				cin >> ogrenciler.kisaSinav1[i];
				if (ogrenciler.kisaSinav1[i] >= 0 && ogrenciler.kisaSinav1[i] <= 100)
					break;
			}
			while (1) {		// kullanýcý 0-100 arasýnda bir sayý girene kadar döngüden çýkamaz
				cout << "2.Kýsa sýnav notu: ";
				cin >> ogrenciler.kisaSinav2[i];
				if (ogrenciler.kisaSinav2[i] >= 0 && ogrenciler.kisaSinav2[i] <= 100)
					break;
			}
			while (1) {		// kullanýcý 0-100 arasýnda bir sayý girene kadar döngüden çýkamaz
				cout << "Vize notu: ";
				cin >> ogrenciler.vize[i];
				if (ogrenciler.vize[i] >= 0 && ogrenciler.vize[i] <= 100)
					break;
			}
			while (1) {		// kullanýcý 0-100 arasýnda bir sayý girene kadar döngüden çýkamaz
				cout << "Proje notu: ";
				cin >> ogrenciler.proje[i];
				if (ogrenciler.proje[i] >= 0 && ogrenciler.proje[i] <= 100)
					break;
			}
			while (1) {		// kullanýcý 0-100 arasýnda bir sayý girene kadar döngüden çýkamaz
				cout << "1.Ödev notu: ";
				cin >> ogrenciler.odev1[i];
				if (ogrenciler.odev1[i] >= 0 && ogrenciler.odev1[i] <= 100)
					break;
			}
			while (1) {		// kullanýcý 0-100 arasýnda bir sayý girene kadar döngüden çýkamaz
				cout << "2.Ödev notu: ";
				cin >> ogrenciler.odev2[i];
				if (ogrenciler.odev2[i] >= 0 && ogrenciler.odev2[i] <= 100)
					break;
			}
			while (1) 		// kullanýcý 0-100 arasýnda bir sayý girene kadar döngüden çýkamaz
				cout << "Final notu: ";
			cin >> ogrenciler.final[i];
			if (ogrenciler.final[i] >= 0 && ogrenciler.final[i] <= 100)
				break;
		}
		system("pause");
		system("cls");
	}
	for (int i = 0; i < 100; i++) // öðrencilerin baþarý notlarýný hesaplamak için for döngüsü ekledim
	{
		float yil_iciNot = ogrenciler.vize[i] * 0.5
			+ ogrenciler.kisaSinav1[i] * 0.07
			+ ogrenciler.kisaSinav2[i] * 0.07
			+ ogrenciler.odev1[i] * 0.1
			+ ogrenciler.odev2[i] * 0.1
			+ ogrenciler.proje[i] * 0.16;

		ogrenciler.basariNotu[i] = yil_iciNot * 0.55 + ogrenciler.final[i] * 0.45;
	}

	while (1)	//kullanýcý çýkmak isteyene kadar menüye döndürsün diye sonsuz döngü ekledim
	{
		float enYuksek = ogrenciler.basariNotu[0];
		float enDusuk = ogrenciler.basariNotu[0];

		cout << "[1] Sýnýf listesi yazdýrýlsýn\n[2] Sýnýfýn en yüksek notu hesaplansýn\n[3] Sýnýfýn en düþük notu hesaplansýn\n[4] Sýnýf ortalamasý hesaplansýn";
		cout << "\n[5] Sýnýfýn standart sapmasý hesaplansýn\n[6] Baþarý notu belirli aralýkta olan öðrencileri sýralamak için";
		cout << "\n[7] Baþarý notu belirtilen deðerin altýnda olan öðrencilerin sýralanmasý için\n[8] Baþarý notu belirtilen deðerin üstünde olan öðrencilerin sýralanmasý için";
		cout << "\n[Q] Çýkýþ yapmak için" << endl;

		cin >> secim2;

		if (secim2 == 'Q' || secim2 == 'q') // kullanýcý q veya Q girerse programdan çýkar
			break;

		else if (secim2 == '1') // kullanýcý secim2de 1 deðerini girerse sýnýf listesini bastýrýr
		{
			system("cls");
			for (int i = 0; i < 100; i++)
			{
				cout << ogrenciler.ogrenciNo[i] << " " << ogrenciler.isim[i] << " " << ogrenciler.soyisim[i] << " Baþarý notu: " << ogrenciler.basariNotu[i] << endl;

				if (i == 19) {		// 20 öðrenci basýldýðýnda program durur ve kullanýcýnýn herhangi bir tuþa basmasýný ister
					system("pause");
					system("cls");
				}
				if (i == 39) {		// 20 öðrenci basýldýðýnda program durur ve kullanýcýnýn herhangi bir tuþa basmasýný ister
					system("pause");
					system("cls");
				}
				if (i == 59) {		// 20 öðrenci basýldýðýnda program durur ve kullanýcýnýn herhangi bir tuþa basmasýný ister
					system("pause");
					system("cls");
				}
				if (i == 79) {		// 20 öðrenci basýldýðýnda program durur ve kullanýcýnýn herhangi bir tuþa basmasýný ister
					system("pause");
					system("cls");
				}
				if (i == 99) {		// 20 öðrenci basýldýðýnda program durur ve kullanýcýnýn herhangi bir tuþa basmasýný ister
					system("pause");
					system("cls");
				}
			}
			system("pause");
			system("cls");
		}


		else if (secim2 == '2') // kullanýcý 2 deðerini girerse en yüksek nota sahip olan öðrenciyi ekrana bastýrýr
		{
			int d; // hangi öðrencinin en yüksek nota sahip olduðunu belirtebilmek için tanýmladým
			system("cls");

			for (int i = 0; i < 100; i++) /*döngü basariNotu dizisinin tüm elemanlarýndan geçecek eðer basariNotu[i], enYuksek'ten büyükse
										  enYuksek'in yeni deðeri basariNotu[i] olacak. Bu þekilde en yüksek baþarý notu bulunmuþ olunacak*/
			{
				if (ogrenciler.basariNotu[i] > enYuksek) // eðer ogrenciler.basariNotu[i] enYuksek'ten büyükse enYuksek'in yeni deðeri ogrenciler.basariNotu[i] olur
				{
					enYuksek = ogrenciler.basariNotu[i];
					d = i;
				}
			}
			cout << "En yüksek baþarý puan, " << enYuksek << " puan ile " << ogrenciler.ogrenciNo[d] << " Nolu " << ogrenciler.isim[d] << " " << ogrenciler.soyisim[d] << " adlý öðrenciye aittir. " << endl;
			system("pause");
			system("cls");
		}
		else if (secim2 == '3')  // kullanýcý 3 deðerini girerse en düþük nota sahip olan öðrenciyi ekrana bastýrýr
		{
			int a = 0;
			system("cls");

			for (int i = 99; i >= 0; i--)
			{
				if (ogrenciler.basariNotu[i] < enDusuk) { // eðer ogrenciler.basariNotu[i] enDusuk'ten küçükse enDusuk'ün yeni deðeri ogrenciler.basariNotu[i] olur
					enDusuk = ogrenciler.basariNotu[i];
					a = i;
				}
			}
			cout << "En düþük baþarý puan, " << enDusuk << " puan ile " << ogrenciler.ogrenciNo[a] << " Nolu " << ogrenciler.isim[a] << " " << ogrenciler.soyisim[a] << " adlý öðrenciye aittir. " << endl;
			system("pause");
			system("cls");
		}

		else if (secim2 == '4') // kullanýcý 4 deðerini girerse sýnýf ortalamasýný ekrana bastýrýr
		{
			system("cls");
			float ortalama = 0;
			for (int i = 0; i < 100; i++) // i arttýkça basariNotu dizisinin yeni elemanýný ortalamaya ekler
				ortalama += ogrenciler.basariNotu[i];

			cout << "Sýnýfýn Not ortalamasý: " << ortalama / 100 << endl;
			system("pause");
			system("cls");
		}

		else if (secim2 == '5')  // kullanýcý 5 deðerini girerse sýnýfýn standart sapmasýný ekrana yazdýrýr
		{
			system("cls");
			float toplam = 0, ort, islem, sonuc = 0;
			for (int i = 0; i < 100; i++)  // i arttýkça basariNotu'nun yeni elemanýný toplama ekler
				toplam += ogrenciler.basariNotu[i];
			ort = toplam / 100;

			for (int j = 0; j < 100; j++)   // sýrayla her öðreninin notunu sýnýf ortalamasýndan çýkarýp karesini alýr ve sonuca ekler
			{
				islem = (ogrenciler.basariNotu[j] - ort) * (ogrenciler.basariNotu[j] - ort);
				sonuc += islem;
			}
			cout << "Sýnýfýn standart sapmasý: " << sqrt(sonuc / 99) << endl;  // sonucu total öðrenci sayýnýn bir eksiðine bölüp karekökünü alýr ve ekrana yazdýrýr
			system("pause");
			system("cls");
		}

		else if (secim2 == '6')  // Kullanýcýnýn belirlediði 2 deðer arasýndaki notlara sahip öðrencileri ekrana yazdýrýr
		{
			system("cls");
			float sayi1 = 0, sayi2 = 0;
			cout << "Aralýðýn baþlangýç deðeri: "; cin >> sayi1;
			cout << "Aralýðýn bitiþ deðeri: "; cin >> sayi2;
			system("cls");

			for (int i = 0; i < 100; i++) {
				if (ogrenciler.basariNotu[i] >= sayi1 && ogrenciler.basariNotu[i] <= sayi2)  // eðer basariNotu'nun i. elemaný kullanýcýnýn belirlediði aralýktaysa ekrana yazar
					cout << ogrenciler.ogrenciNo[i] << " " << ogrenciler.isim[i] << " " << ogrenciler.soyisim[i] << " " << ogrenciler.basariNotu[i] << endl;
			}
			system("pause");
			system("cls");
		}

		else if (secim2 == '7') // kullanýcýnýn belirlediði deðerin altýndaki notlara sahip olan öðrencileri ekrana yazdýrýr
		{
			system("cls");
			float sayi;
			cout << "Hangi deðerin altýndaki sayýlarý ekrana yazýlsýn: "; cin >> sayi;

			for (int i = 0; i < 100; i++) {
				if (sayi > ogrenciler.basariNotu[i])  // eðer basariNotu'nun i. elemaný kullanýcýnýn girdiði sayýdan düþükse ekrana yazdýrýr
					cout << ogrenciler.ogrenciNo[i] << " " << ogrenciler.isim[i] << " " << ogrenciler.soyisim[i] << " " << ogrenciler.basariNotu[i] << endl;
			}
			system("pause");
			system("cls");
		}

		else if (secim2 == '8') // kullanýcýnýn belirlediði deðerin üstündeki notlara sahip olan öðrencileri ekrana yazdýrýr
		{
			system("cls");
			float sayi3;
			cout << "Hangi deðerin üstündeki sayýlar ekrana yazýlsýn: "; cin >> sayi3;

			for (int i = 0; i < 100; i++) {
				if (sayi3 < ogrenciler.basariNotu[i])  // eðer basariNotu'nun i.elemaný kullanýcýnýn belirlediði sayýdan büyükse ekrana yazdýrýr
					cout << ogrenciler.ogrenciNo[i] << " " << ogrenciler.isim[i] << " " << ogrenciler.soyisim[i] << " " << ogrenciler.basariNotu[i] << endl;
			}
			system("pause");
			system("cls");
		}

	}


	return 0;
}



float notKontrol(string s, float min, float max) {
	float sayi;

	do {		// kullanýcý min ile max arasýnda deðer girene kadar s'yi ekrana bastýrýp deðer girmesini ister
		cout << s; cin >> sayi;
	} while (!(sayi >= min && sayi <= max));

	return sayi;
}

float notCevirme(string oku, float notu) {
	if (notu >= 90)  //  eðer notu 90'dan büyük veya eþitse oku deðiþkeni ve AA ekrana yazýlýr
		cout << oku << "AA";
	else if (notu >= 85)     // eðer notu 85 ile 90 arasýndaysa oku deðiþkeni ve BA ekrana yazýlýr
		cout << oku << "BA";
	else if (notu >= 80)  // eðer notu 80 ile 90 aralýðýndaysa oku deðiþkeni ve BB ekrana yazýlýr
		cout << oku << "BB";
	else if (notu >= 75)    // eðer notu 75 ile 80 aralýðýndaysa oku deðiþkeni ve CB ekrana yazýlýr
		cout << oku << "CB";
	else if (notu >= 65)	// eðer notu 65 ile 70 aralýðýndaysa oku deðiþkeni ve CC ekrana yazýlýr
		cout << oku << "CC";
	else if (notu >= 58)	// eðer notu 58 ile 65 aralýðýndaysa oku deðiþkeni ve DC ekrana yazýlýr
		cout << oku << "DC";
	else if (notu >= 50)	// eðer notu 50 ile 58 aralýðýndaysa oku deðiþkeni ve DD ekrana yazýlýr
		cout << oku << "DD";
	else if (notu >= 40)	// eðer notu 40 ile 50 aralýðýndaysa oku deðiþkeni ve DF ekrana yazýlýr
		cout << oku << "DF";
	else                    // diðer koþullarda (notu 40'ýn altýndaysa) oku deðiþkeni ve FF ekrana yazýlýr  
		cout << oku << "FF";
	return notu;
}