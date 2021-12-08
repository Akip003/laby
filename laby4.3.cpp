#include<iostream>
int dl = 4;

void tablica(char*& tablica)
{

	tablica = new char[dl];


}
int l_elem(char tab[])
{
	int n = 0;
	while (tab[n] > 0 && tab[n] <= 117)
	{
		n++;
	}
	return n;
}
int l_puste(char tab[])
{
	return(dl - l_elem(tab));

}
void powieksz(char tab[])
{
	if (l_puste(tab) == 0)
	{
		dl *= 2;
		tablica(tab);
	}

}
void dodaj(char* tab)
{
	int n = l_elem(tab);

	std::cin >> tab[n];
}
void wyswietl(char tab[])
{
	int a = l_elem(tab);
	for (int i = 0; i < a; i++)
		std::cout << tab[i] << "\t";
}
void usun(char tab[], int e)
{
	int max = l_elem(tab);
	
	for (int i = e; i < max; i++)
	{
		tab[i] = tab[i + 1];
	}
	if(max>e)
	tab[max - 1] = 0;

}


int main()
{


	char* tab;
	tablica(tab);

	while (true)
	{
		powieksz(tab);
		std::cout << "co chcesz zrobic?\n1.dodaj element\n2.wyswielt tablice\n3.podaj ilosc elementow\n4.podaj ilosc wolnych miejsc\n5.usun wybrany element\nNacisnij inny przycisk aby zakonczyc\n";
		int x;
		std::cin >> x;
		switch (x)
		{
		case 1:
			dodaj(tab);
			break;
		case 2:
			std::cout << "elementy tablicy: \n";
			wyswietl(tab);
			std::cout << "\n============\n\n";
			break;
		case 3:
			std::cout << "liczba elementow wynosi " << l_elem(tab) << "\n\n";
			break;
		case 4:
			std::cout << "liczba pustych miejsc wynosi " << l_puste(tab) << "\n\n";
			break;
		case 5:
			int element;
			std::cout << "podaj miejsce elementu do usuniecia (liczac od zera)";
			std::cin >> element;
			usun(tab, element);
			break;
		default:
			return 1;
		}
		
	}


	return 0;
}
