#include <iostream>
#include<cmath>
#include<conio.h>

void get_pesel(int tab[])
{
	std::cout << "podaj pesel: \n";
	for (int i = 0; i < 11; i++)
	{
		tab[i] = _getch() - 48;
		if (tab[i] < 0 || tab[i]>9)
		{
			std::cout << "pesel moze zawierac tylko cyfry";
			exit(1);
		}
		std::cout << tab[i] << std::endl;
	}
}
void sprawdz_poprawnosc(int tab[])
{
	int wynik=0;
	
	for (int i = 0; i < 10; i++)
	{
		int w = i + 1;
		int waga = 0;
		switch (w)
		{
		case 1:
		case 5:
		case 9:
		//case 11:
			waga = 1;
			break;
		case 2:
		case 6:
		case 10:
			waga = 3;
			break;
		case 3:
		case 7:
			waga = 7;
			break;
		case 4:
		case 8:
			waga = 9;
		}
		wynik += (tab[i] * waga)%10;

		
	}
	wynik = wynik % 10;
	wynik = 10 - wynik;
	
	if (wynik != tab[10])
	{
		std::cout << "pesel niepoprawny";
		exit(1);
	}
	

}
void give_plec(int tab[])
{
	if ((tab[9] % 2) == 0)
		std::cout << "kobieta";
	else
		std::cout << "mezczyzna";
}
void give_dzien(int &dzien,int tab[])
{
	dzien = 10 * tab[4] + tab[5];
}
void rok_mies(int &rok, int &mies, int tab[])
{
	int kont = tab[2] * 10 + tab[3];



	if (kont >= 21 && kont <= 32)
	{
		rok = 2000 + 10 * tab[0] + tab[1];
		mies = 10 * tab[2] + tab[3] - 20;
	}
	else if (kont >= 81 && kont <= 92)
	{
		rok = 1800 + 10 * tab[0] + tab[1];
		mies = 10 * tab[2] + tab[3] - 80;
	}
	else if (kont >= 01 && kont <= 12)
	{
		rok = 1900 + 10 * tab[0] + tab[1];
		mies = 10 * tab[2] + tab[3];
	}
	else if (kont >= 41 && kont <= 52)
	{
		rok = 2100 + 10 * tab[0] + tab[1];
		mies = 10 * tab[2] + tab[3] - 40;
	}
	else if (kont >= 61 && kont <= 72)
	{
		rok = 2200 + 10 * tab[0] + tab[1];
		mies = 10 * tab[2] + tab[3] - 60;
	}
	
}
int main()
{
	
	int rok;
	int tab[11];
	int mies;
	int dzien;
	get_pesel(tab);
	sprawdz_poprawnosc(tab);
	std::cout << "twoja plec to ";
	give_plec(tab);
	give_dzien(dzien, tab);
	rok_mies(rok, mies, tab);
	std::cout << std::endl << "twoja data urodzenia to ";
	std::cout << dzien << "." << mies << "." << rok;
	

}

