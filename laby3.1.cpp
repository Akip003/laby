#include <iostream>
#include<cmath>
const int MAX = 50;
void wczytaj(int &n, int tab[], int &licznik, int &dodatnie, int &ujemne)
{
	while (true)
	{
		std::cin >> tab[n];
		licznik += tab[n];
		if (tab[n] > 0)
			dodatnie++;
		if (tab[n] < 0)
			ujemne++;
		n++;
		if (tab[n - 1] == (-1))
			break;
	}
}
void wyswietl(int& n, int tab[])
{
	for (int i = 0; i < n; i++)
	{
		std::cout << tab[i] << "\n";
	}
}
void avg(int &n, int &licznik, float &srednia)
{
	srednia = (float)licznik / n;
	std::cout << "srednia wynosi " << srednia << std::endl;
}
void odchylenie(int &n,int tab[],float srednia)
{
	float wariancja=0;
	for (int i = 0; i < n; i++)
	{
		wariancja += sqrt(tab[n] - srednia);
	}
	wariancja = wariancja / n;
	float odchylenie = sqrt(wariancja);
	std::cout << "odchylenie standardowe wynosi " << odchylenie << std::endl;
}
void odwrot_plus_5(int tab[], int &n)
{
	int j = n-1;
	int i = 0;
	int temp;
	while (i < j)
	{
		temp = tab[i];
		tab[i] = tab[j];
		tab[j] = temp;
		
		i++;
		j--;
	}
	for (i = 0; i < n; i++)
	{
		tab[i] += 5;
	}
}

void sprawdz(int tab[], int n)
{
	int a;
	bool jest=0;
	std::cout << "podaj dowolna liczbe\n";
	std::cin >> a;
	for (int i = 0; i < n; i++)
	{
		if(tab[i]==a)
		{
			std::cout << a << " wystepuje na pozycji " << i<<std::endl;
			jest = 1;
		}
	}
	if (jest != 1)
	{
		std::cout << "liczby nie ma w tabeli";
	}
}

void sort(int tab[], int &n)
{
	
	for (int i = 0; i < n; i++)
	{
		int max = tab[i];
		int index=i;
		
		
		for (int j = i+1; j < n; j++)
		{
			if (tab[j] > max)
			{
				max=tab[j];
				index = j;
				
			}
		}
		
		if (max != i)
		{
			tab[index] = tab[i];
			tab[i] = max;
		}
	}
}


int main()
{
	int tab[MAX];
	int n = 0;
	int licznik = 0, dodatnie =0, ujemne =0;
	float srednia;

	
	wczytaj(n, tab, licznik, dodatnie, ujemne);
	std::cout << "wprowadzono " << n << " elementow\n" << "wprowadzone dane: \n";
	wyswietl(n, tab);

	avg(n, licznik, srednia);
	
	odchylenie(n, tab, srednia);

	odwrot_plus_5(tab, n);

	wyswietl(n, tab);
	
	sprawdz(tab, n);
		
	sort(tab, n);

	std::cout << "posortowana tablica:\n";
	wyswietl(n, tab);
		//naprawic odchylenie stadnardowe
}
