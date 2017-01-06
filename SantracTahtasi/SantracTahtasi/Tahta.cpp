#include <iostream>
#include <vector>//Vektör Sýnýfý ile yatay,dikey ve ChessBoard Vektörlerini oluþturmak için.
//Vektörler indisli eriþime izin verirler.
using namespace std;
int main()
{

	vector <vector<int>> ChessBoard;//ChessBoard (Satranç Tahtasý)adýnda bir Vektör oluþturduk.
	vector <int> SutunVektoru;//SutunVektoru adýnda vektör tanýmladýk.
	vector <int> yatay; //yatay adlý vektör.
	vector <int> dikey;//dikey adlý vektör.

	dikey.push_back(-1), dikey.push_back(-2), dikey.push_back(-2), dikey.push_back(-1);//dikey vektörünün sonuna -1,-2,-2,-1 deðerlerini ekle.
	dikey.push_back(1), dikey.push_back(2), dikey.push_back(2), dikey.push_back(1);//dikey vektörünün sonuna 1,2,2,1 deðerlerini ekle.

	yatay.push_back(2), yatay.push_back(1), yatay.push_back(-1), yatay.push_back(-2);// yatay vektörünün sonuna 2,1,-1,2 deðerlerini ekle.
	yatay.push_back(-2), yatay.push_back(-1), yatay.push_back(1), yatay.push_back(2);//yatay vektörünün sonuna -2,-1,1,2 deðerlerini ekle.

	for (int i = 0; i < 8; i++)
	{
		SutunVektoru.clear();//Baþlangýçta bütün sütunlarý clear komutu ile temizle.
		for (int j = 0; j < 8; j++)
		{
			SutunVektoru.push_back(0);//Bütün sutunlarýn sonuna 0 sayýsýný ekle.Sutunlarýn tamamýný 0 yap.
		}
		ChessBoard.push_back(SutunVektoru);
	}//Atýn baþlayacaðý yeri 1 yap.

	int BulunanSatir = -1, BulunanSutun = -1;//Zorunlu deðiþkenler.
	int moveCount = 1, hamle;	//yapýlacak hamleler moveCount deðiþkeninde tutulur.

	while (BulunanSutun >= 8 || BulunanSutun < 0 || BulunanSatir >= 8 || BulunanSatir < 0)
	{
		cout << endl << " Lutfen Satir Sayisini Giriniz :";//Kullanýcýdan hangi satýrda baþlamak istediði alýnýr.
		cin >> BulunanSatir;

		cout << endl << " Lutfen Sutun Sayisini Giriniz :";//Kullanýcýdan hangi sütunda baþlamak istediði alýnýr.
		cin >> BulunanSutun;

		if (BulunanSutun >= 8 || BulunanSutun < 0 || BulunanSatir >= 8 || BulunanSatir < 0)

		{//Girilen satýr ve sütun sayýsý bu if bloðunun içerisinde kontrol edilir.Eðer 0 ile 7 arasýnda (0 ve 7 ye eþit olabilir.)
		 //bir deðer girilmez ise kullanýcýya uyarý mesajý verilir.
			cout << " Lutfen Gecerli Bir Sayi Giriniz.!!!";
			system("pause");
		}

		ChessBoard[BulunanSatir][BulunanSutun] = 1;
	}
	for (;;)//Sonsuz döngü  while(true)
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

		if (moveCount == 64)//moveCount deðiþkeninde  kaç hamle yapacaðýmýzý  saklýyorduk.
							//Eðer moveCount(yapýlan hamle sayýsý) 64 e eþit ise kullanýcýya mesaj verilip programdan çýkýlýr.
		{
			cout << " Satranc Tahtasinin Butun Karelerine Ulasildi.\n Programdan Cikmak Icin Herhangi Bir Tusa Basin.\n";
			break;
		}
		int hamleDizisi[8] = { 0, 0, 0, 0, 0, 0, 0, 0 }, KucukHamle = 0, kucukIndex = 0,
			moveNumbers[8] = { -64, -64, -64, -64, -64, -64, -64, -64 };

		for (int i = 0; i < 8; i++)
		{
			if (BulunanSatir + dikey[i] >= 0 && BulunanSatir + dikey[i] < 8 && BulunanSutun + yatay[i] >= 0 && BulunanSutun + yatay[i] < 8)
			{//  if bloðuna devam edebilmesi için santranç tahtasýnýn  içinde olmasý lazým.
				if (ChessBoard[BulunanSatir + dikey[i]][BulunanSutun + yatay[i]] == 0)
				{//Buradaki if bloðu oynanma ihtimali olan yerlerin oynanýp oynanmadýðýný kontrol eder.
				 //Eðer oynanmamýþsa if bloðuna devam eder.
					hamleDizisi[i] = 1;//Daha sonra oynadýðý indisin deðerini 1 sayýsýna eþitler.
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
					{//Buradaki if bloðu  yapýlan  2. hamlenin Satranç tahtasýnda olup olmadýðý kontrol  edilir.
						if (ChessBoard[BulunanSatir + dikey[j] + dikey[i]][BulunanSutun + yatay[j] + yatay[i]] == 0)
						{// Buradaki if bloðunda ise atýn daha önce burayý ziyaret edip etmediði kontrol edilir.
							hamleSayisi++;
						}
					}
				}
				moveNumbers[j] = hamleSayisi;//hamleSayisi  moveNumbers[j] deðiþkenine atýlýr.
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
				kucukIndex = i; //Bulunan indis kucukIndex deðiþkenine yollanýr.
			}
		}//en düþük  hamlenin bulunduðu indis deðeri döndürülür.
		hamle = kucukIndex;
		if ((BulunanSatir + dikey[hamle]) >= 0 && (BulunanSatir + dikey[hamle]) < 8 && (BulunanSutun + yatay[hamle]) >= 0 && (BulunanSutun + yatay[hamle]) < 8)
		{//Bu if bloðunda atýn oynamak istediði karenin daha önceden oynanýp oynanmadýðý kontrole tabi tutulur.
			if (ChessBoard[BulunanSatir + dikey[hamle]][BulunanSutun + yatay[hamle]] == 0)
			{// ChessBoard dizisindeki oynayacaðý hamlenin bulunduðu indisteki deðeri 1 e eþitlenir
				ChessBoard[BulunanSatir + dikey[hamle]][BulunanSutun + yatay[hamle]] = 1;
				BulunanSatir = BulunanSatir + dikey[hamle];//bulunan satir dikey adlý vektördeki deðeri ile toplanýr.
				BulunanSutun = BulunanSutun + yatay[hamle];//bulunan sütun yatay adlý vektördeki deðeri ile toplanýr.
				moveCount++;
			}
		}
		cout << " Bir Sonraki Hamle Icin Herhangi Bir Tusa Basin.\n\n";
		system("pause");
	}
}