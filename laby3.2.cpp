#include <iostream>
#include<cmath>
#include<conio.h>

int main()
{
	int tab[11];
	for (int i = 0; i < 11; i++)
	{
		tab[i] = _getch()-48;
		if (tab[i] < 0 || tab[i]>9)
		{
			std::cout << "pesel moze zawierac tylko cyfry";
			return 1;
		}
		std::cout << tab[i] << std::endl;
	}
	if (tab[10] % 2 == 0)
		std::cout << "kobieta";
	else
		std::cout << "mezczyzna";
	int kont = tab[2] * 10 + tab[3];
	int rok;
	int mies;
	if (kont >= 21 && kont <= 32)
	{
		rok = 2000 + 10 * tab[0] + tab[1];
		mies = 10 * tab[0] + tab[1]-20;
	}
	else if(kont >= 81 && kont <= 92)
	{
		rok = 1800 + 10 * tab[0] + tab[1];
		mies = 10 * tab[0] + tab[1] - 80;
	}
	else if (kont >= 01 && kont <= 12)
	{
		rok = 1900 + 10 * tab[0] + tab[1];
		mies = 10 * tab[0] + tab[1];
	}
	else if (kont >= 41 && kont <= 52)
	{
		rok = 2100 + 10 * tab[0] + tab[1];
		mies = 10 * tab[0] + tab[1] - 40;
	}
	else if (kont >= 61 && kont <= 72)
	{
		rok = 2200 + 10 * tab[0] + tab[1];
		mies = 10 * tab[0] + tab[1] - 60;
	}
}
//dodac dzien urodzenia, spawdzanie poprawnosci
