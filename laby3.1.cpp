#include <iostream>
#include<cmath>
const int MAX = 50;
int main()
{
	int tab[MAX];
	int n = 0;
	int licznik = 0, dodatnie =0, ujemne =0;

	std::cout << "podaj elementy tablicy";
		while (tab[n-1]!=(-1))
	{
		std::cin >> tab[n];
		licznik += tab[n];
		if (tab[n] > 0)
			dodatnie++;
		if (tab[n] < 0)
			ujemne++;
			n++;
			
	}

		std::cout<<"wprowadzono"<<n<<"elementow\n" << "wprowadzone dane dane\n";
		for (int i = 0; i < n; i++)
		{
			std::cout << tab[i]<<"\n";
		}
		int srednia = licznik /n;
		std::cout << "srednia wynosi " << srednia << std::endl;

		int wariancja = 0;
		for (int i = 0; i < n; i++)
		{
			wariancja += sqrt(tab[n] - srednia);
		}
		wariancja = wariancja /n;
		int odchylenie = sqrt(wariancja);
		std::cout << "odchylenie standardowe wynosi " << odchylenie<<std::endl;

		int t_temp[MAX];
		int k = n;
		for (int i = 0; i < n; i++)
		{
			t_temp[k] = tab[i];
			k--;
		}
		std::cout << "tablica po odwroceniu i dodaniu 5: \n";
		for (int i = 0; i < n; i++)
		{
			tab[i] = t_temp[i]+5;
			std::cout << tab[i] << std::endl;
		}
		std::cout << "podano " << dodatnie << "liczb dodatnich i " << ujemne << "liczb ujemnych\n";
		std::cout << "podaj dowolną liczbę:\n";
		int a;
		std::cin >> a;
		bool obecna;
		for (int i = 0; i < n; i++)
		{
			if (a == tab[i])
			{
				std::cout << "liczba znajduje się na pozycji" << i;
				obecna = 1;
			}

		}

		if (obecna == 0)
		{
			std::cout << "liczba nie znajduje sie w tablicy";
		}
		for (int i = 0; i < n; i++)
		{
			int max = tab[0];
			int index=i;
			for (int j = i; j < n; j++)
			{
				if (tab[j] > max)
				{
					max = tab[j];
					index = j;
				}


			}
			if (index != i)
			{
				int temp = tab[i];
				tab[i] = max;
				tab[index] = temp;
			}
			
		}
		std::cout << "posortowana tablica:\n";
		for (int i = 0; i < n; i++)
			std::cout << tab[i] << std::endl;

}