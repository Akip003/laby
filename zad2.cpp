#include <iostream>
#include<cmath>
#include <conio.h>

double dodawanie(double a, double b)
{
	return a + b;
}
double odejmowanie(double a, double b)
{
	return a - b;
}
double mnozenie(double a, double b)
{
	return a * b;
}
double dzielenie(double a, double b)
{
	return a / b;
}
double pierwiastek(double a, double b)
{
	double wynik;
	wynik = pow(a, 1 / b);
	return wynik;
}
double potegowanie(double a, double b)
{
	double wynik = 1.00;

	if (b > 0 && (int)b - b == 0)
		for (int i = 0; i < b; i++)
		{
			wynik *= a;
		}
	else if (b == 0)
		return 1;
	else if (b < 0 && (int)b - b == 0)
	{
		b *= (-1.00);
		wynik = (double)1.00 / (double)potegowanie(a, b);
		std::cout << "wynik w zmiennej " << wynik << std::endl;

	}
	else if ((int)b - b != 0)
	{
		int mianownik = 1;
		while (b != (int)b)
		{
			b *= 10;
			mianownik *= 10;
		}
		double temp = potegowanie(a, b);
		wynik = pierwiastek(temp, mianownik);



	}
	else
	{
		std::cout << "niepoprawny numer";
		exit(50);
	}
	return wynik;
}
double eksponenta(double a)
{
	double e = 2.718281828459;
	return pow(e, a);

}
int main()
{
	while (true)
	{
		std::cout << "PODAJ DWIE LICZBY: \n";
		double a, b;
		std::cin >> a >> b;
		std::cout << "WYBIERZ DZIALANIE \n 1.dodawanie \n 2.odejmowanie \n 3.mnozenie \n 4.dzielenie \n 5.potegowanie \n 6.pierwiastek \n 7.eksponenta a \n";
		int menu;
		double wynik;
		std::cin >> menu;
		switch (menu)
		{
		case 1:
		{
			wynik = dodawanie(a, b);

		}
		break;
		case 2:
		{
			wynik = odejmowanie(a, b);
		}
		break;
		case 3:
		{
			wynik = mnozenie(a, b);
		}
		break;
		case 4:
		{
			if (b == 0)
			{
				std::cout << "dzielenie przez zero \n";
				return 40;
			}
			else
				wynik = dzielenie(a, b);
		}
		break;
		case 5:
		{
			wynik = potegowanie(a, b);
		}
		break;
		case 6:
		{
			wynik = pierwiastek(a, b);
		}
		break;
		case 7:
		{
			wynik = eksponenta(a);
		}
		break;
		default:
			std::cout << "do tego znaku nie przypisano zadnego dzialania";
			return 1;
			break;
		}
		std::cout << "wynik dzialania jest rowny " << wynik << std::endl << std::endl;
		std::cout << "czy chcesz kontynuowac?[y/n]";
		char kontynuuj = _getch();
		if (kontynuuj != 'y')
			return 3;
		std::cout << "\n*\n*\n*\n";
	}
	return 0;
}