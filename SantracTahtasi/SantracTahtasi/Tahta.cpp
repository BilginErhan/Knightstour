#include <iostream>
#include <vector>//Vekt�r S�n�f� ile yatay,dikey ve ChessBoard Vekt�rlerini olu�turmak i�in.
//Vekt�rler indisli eri�ime izin verirler.
using namespace std;
int main()
{

	vector <vector<int>> ChessBoard;//ChessBoard (Satran� Tahtas�)ad�nda bir Vekt�r olu�turduk.
	vector <int> SutunVektoru;//SutunVektoru ad�nda vekt�r tan�mlad�k.
	vector <int> yatay; //yatay adl� vekt�r.
	vector <int> dikey;//dikey adl� vekt�r.

	dikey.push_back(-1), dikey.push_back(-2), dikey.push_back(-2), dikey.push_back(-1);//dikey vekt�r�n�n sonuna -1,-2,-2,-1 de�erlerini ekle.
	dikey.push_back(1), dikey.push_back(2), dikey.push_back(2), dikey.push_back(1);//dikey vekt�r�n�n sonuna 1,2,2,1 de�erlerini ekle.

	yatay.push_back(2), yatay.push_back(1), yatay.push_back(-1), yatay.push_back(-2);// yatay vekt�r�n�n sonuna 2,1,-1,2 de�erlerini ekle.
	yatay.push_back(-2), yatay.push_back(-1), yatay.push_back(1), yatay.push_back(2);//yatay vekt�r�n�n sonuna -2,-1,1,2 de�erlerini ekle.

	for (int i = 0; i < 8; i++)
	{
		SutunVektoru.clear();//Ba�lang��ta b�t�n s�tunlar� clear komutu ile temizle.
		for (int j = 0; j < 8; j++)
		{
			SutunVektoru.push_back(0);//B�t�n sutunlar�n sonuna 0 say�s�n� ekle.Sutunlar�n tamam�n� 0 yap.
		}
		ChessBoard.push_back(SutunVektoru);
	}//At�n ba�layaca�� yeri 1 yap.

	int BulunanSatir = -1, BulunanSutun = -1;//Zorunlu de�i�kenler.
	int moveCount = 1, hamle;	//yap�lacak hamleler moveCount de�i�keninde tutulur.

	while (BulunanSutun >= 8 || BulunanSutun < 0 || BulunanSatir >= 8 || BulunanSatir < 0)
	{
		cout << endl << " Lutfen Satir Sayisini Giriniz :";//Kullan�c�dan hangi sat�rda ba�lamak istedi�i al�n�r.
		cin >> BulunanSatir;

		cout << endl << " Lutfen Sutun Sayisini Giriniz :";//Kullan�c�dan hangi s�tunda ba�lamak istedi�i al�n�r.
		cin >> BulunanSutun;

		if (BulunanSutun >= 8 || BulunanSutun < 0 || BulunanSatir >= 8 || BulunanSatir < 0)

		{//Girilen sat�r ve s�tun say�s� bu if blo�unun i�erisinde kontrol edilir.E�er 0 ile 7 aras�nda (0 ve 7 ye e�it olabilir.)
		 //bir de�er girilmez ise kullan�c�ya uyar� mesaj� verilir.
			cout << " Lutfen Gecerli Bir Sayi Giriniz.!!!";
			system("pause");
		}

		ChessBoard[BulunanSatir][BulunanSutun] = 1;
	}
	for (;;)//Sonsuz d�ng�  while(true)
	{
		cout << "\n Hamle Sayisi:" << moveCount << endl << endl;

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cout << " " << ChessBoard[i][j] << " ";
			}
			cout << "\n";
		}

		cout << endl;

		if (moveCount == 64)//moveCount de�i�keninde  ka� hamle yapaca��m�z�  sakl�yorduk.
							//E�er moveCount(yap�lan hamle say�s�) 64 e e�it ise kullan�c�ya mesaj verilip programdan ��k�l�r.
		{
			cout << " Satranc Tahtasinin Butun Karelerine Ulasildi.\n Programdan Cikmak Icin Herhangi Bir Tusa Basin.\n";
			break;
		}
		int hamleDizisi[8] = { 0, 0, 0, 0, 0, 0, 0, 0 }, KucukHamle = 0, kucukIndex = 0,
			moveNumbers[8] = { -64, -64, -64, -64, -64, -64, -64, -64 };

		for (int i = 0; i < 8; i++)
		{
			if (BulunanSatir + dikey[i] >= 0 && BulunanSatir + dikey[i] < 8 && BulunanSutun + yatay[i] >= 0 && BulunanSutun + yatay[i] < 8)
			{//  if blo�una devam edebilmesi i�in santran� tahtas�n�n  i�inde olmas� laz�m.
				if (ChessBoard[BulunanSatir + dikey[i]][BulunanSutun + yatay[i]] == 0)
				{//Buradaki if blo�u oynanma ihtimali olan yerlerin oynan�p oynanmad���n� kontrol eder.
				 //E�er oynanmam��sa if blo�una devam eder.
					hamleDizisi[i] = 1;//Daha sonra oynad��� indisin de�erini 1 say�s�na e�itler.
				}
			}
		}
		for (int j = 0; j < 8; j++)
		{
			if (hamleDizisi[j] == 1)
			{
				int hamleSayisi = 0;
				for (int i = 0; i < 8; i++)
				{
					if (BulunanSatir + dikey[j] + dikey[i] >= 0 && BulunanSatir + dikey[j] + dikey[i] < 8 && BulunanSutun + yatay[j] + yatay[i] >= 0 && BulunanSutun + yatay[j] + yatay[i] < 8)
					{//Buradaki if blo�u  yap�lan  2. hamlenin Satran� tahtas�nda olup olmad��� kontrol  edilir.
						if (ChessBoard[BulunanSatir + dikey[j] + dikey[i]][BulunanSutun + yatay[j] + yatay[i]] == 0)
						{// Buradaki if blo�unda ise at�n daha �nce buray� ziyaret edip etmedi�i kontrol edilir.
							hamleSayisi++;
						}
					}
				}
				moveNumbers[j] = hamleSayisi;//hamleSayisi  moveNumbers[j] de�i�kenine at�l�r.
			}
		}
		for (int i = 0; i < 8; i++)
		{
			if (moveNumbers[i] != -64)
			{
				KucukHamle = moveNumbers[i];
				break;
			}
		}
		for (int i = 0; i < 8; i++)
		{//Hamle Dizisin deki  en dusuk hamle bulunur. bulunur.
			if (KucukHamle >= moveNumbers[i] && moveNumbers[i] != -64)
			{
				KucukHamle = moveNumbers[i];
				kucukIndex = i; //Bulunan indis kucukIndex de�i�kenine yollan�r.
			}
		}//en d���k  hamlenin bulundu�u indis de�eri d�nd�r�l�r.
		hamle = kucukIndex;
		if ((BulunanSatir + dikey[hamle]) >= 0 && (BulunanSatir + dikey[hamle]) < 8 && (BulunanSutun + yatay[hamle]) >= 0 && (BulunanSutun + yatay[hamle]) < 8)
		{//Bu if blo�unda at�n oynamak istedi�i karenin daha �nceden oynan�p oynanmad��� kontrole tabi tutulur.
			if (ChessBoard[BulunanSatir + dikey[hamle]][BulunanSutun + yatay[hamle]] == 0)
			{// ChessBoard dizisindeki oynayaca�� hamlenin bulundu�u indisteki de�eri 1 e e�itlenir
				ChessBoard[BulunanSatir + dikey[hamle]][BulunanSutun + yatay[hamle]] = 1;
				BulunanSatir = BulunanSatir + dikey[hamle];//bulunan satir dikey adl� vekt�rdeki de�eri ile toplan�r.
				BulunanSutun = BulunanSutun + yatay[hamle];//bulunan s�tun yatay adl� vekt�rdeki de�eri ile toplan�r.
				moveCount++;
			}
		}
		cout << " Bir Sonraki Hamle Icin Herhangi Bir Tusa Basin.\n\n";
		system("pause");
	}
}