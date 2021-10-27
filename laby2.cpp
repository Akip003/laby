#include <iostream>
#include <conio.h>
void prog1()

	{
		std::cout << "podaj liczbe\n";
		int n;
		std::cin >> n;
		for (int i = 0; i < n; i++)
		{
			std::cout << "-";
		}

		
	}

void prog2()
{
char a;
	int x = 0;
	int y = 0;
	while(1)
	{
		std::cout << "podaj znak\n";
		a = _getch();
		if (a == 'k')
		{
			std::cout << "podano " << x << " znakow "<<std::endl<<"podano "<<y<<" duzych liter";
			break;
		}
		else
		{
			x++;
		}
		if (a >= 65 && a <= 90)
			y++;
	}

		
}
void prog3()
{
	int x, max=0, min=999999,suma=0,liczby=0;
	double sr;
	while (1)
	{
		std::cin >> x;
		liczby++;

		if (liczby == 1) {
			min = x;
			max = x;
		}
		suma += x;
		if (x > max)
		{
			max = x;
		}
		if (x < min)
		{
			min = x;
		}
		std::cout << "czy kontynuowac?[y/n]";
		char a;
		std::cin>>a;
		if (a != 'y')
		{
			sr = (double)suma / liczby;
			std::cout << "najwiekszy element wynosi " << max << std::endl << "najmniejszy element wynosi " << min << std::endl << "srednia wynosi " << sr;
			break;
		}
	}
}
void prog4()
{
	std::cout << "podaj liczbe wyrazow w ciagu\n";
	int n;
	double s=0;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		double x;
		std::cin >> x;
		double c = (double)1 / x;
		s += c;
	}
	std::cout << "suma szeregu jest rowna " << s;
}
void prog5()
{
	std::cout << "podaj wysokosc\n";
	int wys;
	int n = 1;
	std::cin >> wys;
	int a = wys-1;
	for (int i = 0; i < wys; i++)
	{
		for(int i=0;i<a;i++)
			std::cout << " ";
		for(int j = 0; j < n;j++ )
		{
			std::cout << "#";
		}
		std::cout << std::endl;
		n += 2;
		a -= 1;
	}
	a = wys - 1;
	for (int i = 0; i < a; i++)
		std::cout << " ";
	std::cout << "0";

}
int main()
{
	
	std::cout << "ktory program chcesz wybrac?";
	int n;
	std::cin >> n;
	switch (n)
	{
	case 1:
		prog1();
		break;
	case 2:
		prog2();
		break;
	case 3:
		prog3();
		break;
	case 4:
		prog4();
		break;
	case 5:
		prog5();
		break;

	default:
		std::cout << "podano zla wartosc";
		break;
	};
	

	return 0;
}
