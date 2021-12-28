#include <iostream>
#include <string>
#include<fstream>
#include <vector>
#include <stdio.h>
double licz_srednia(double tab[])
{
	double suma = 0;
	for (int i = 0; i < 12; i++)
	{
		suma += tab[i];
	}
	return (suma / 12);
}
struct dane_osobowe
{
	std::string imie;
	std::string nazwisko;
	std::string pesel;
};
struct pracownicy
{
	dane_osobowe dane;
	double wynagrodzenie[12];
	double srednia;

};
void wczytaj(std::vector<pracownicy> &firma)
{
	std::ifstream odczyt("pracownicy.txt");
	std::string x, y, z;
	


	while (odczyt)
	{
		odczyt >> x;
		odczyt >> y;
		odczyt >> z;
		dane_osobowe temp;
		temp.imie = x;
		temp.nazwisko = y;
		temp.pesel = z;
		pracownicy temp2;
		temp2.dane = temp;


		double p;
		for (int i = 0; i < 12; i++)
		{
			odczyt >> p;
			temp2.wynagrodzenie[i] = p;
		}
		temp2.srednia = licz_srednia(temp2.wynagrodzenie);
		firma.push_back(temp2);




	}
	odczyt.close();
	firma.pop_back();
}
void wyswietl(dane_osobowe osoba)
{
	std::cout << "imie: " << osoba.imie << "\nnazwisko: " << osoba.nazwisko << "\npesel: " << osoba.pesel<<"\n";
}
void wyswietl(pracownicy firma)
{
	wyswietl(firma.dane);
	std::cout << "wynagrodzenei w poszczegolnych miesiacach:\n";
	for (int i = 0; i < 12; i++)
	{
		std::cout << firma.wynagrodzenie[i]<<"\t";
	}
	std::cout << "\nsrednia zarobkow w tym roku: " << firma.srednia << "\n\n";

}
void wyswietl(std::vector<pracownicy> vec)
{
	for (int i = 0; i < vec.size(); i++)
		wyswietl(vec[i]);
}
double srednia_global(std::vector<pracownicy> firma)
{
	double suma = 0;
	for (int i = 0; i < firma.size(); i++)
	{
		suma += firma[i].srednia;
	}
	return (suma / firma.size());
}
void srednia_mies(std::vector<pracownicy>firma)
{
	std::vector<double>mies(12);
	for (int i = 0; i < 12; i++)
	{
		mies[i] = 0;
	}
	for (int i = 0; i < firma.size(); i++)
	{
		for (int j = 0; j < 12; j++)
		{
			mies[j] += firma[i].wynagrodzenie[j];
		}
	}
	std::cout << "srednia zarobkow firmy w danych miesiacach : \n";
	for (int i = 0; i < 12; i++)
	{
		std::cout << i+1 << ": " << mies[i]/(firma.size())<<"\n";
	}
}
int main()
{
	
	std::vector<pracownicy> firma;

	
	
	wczytaj(firma);
	
	wyswietl(firma);
	//std::cout << "\nsrednia zarobkow w firmie jest rowna: " << srednia_global(firma);
	srednia_mies(firma);
	

	return 0;
}
