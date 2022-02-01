#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct element {
	string x;
	string y;
	int z;
	element* nastepny;
	element();
};

element::element() {
	nastepny = 0;
}

struct lista {
	element* pierwszy;
	void dodaj(string x, string y, int z);
	void usun(int nr);
	void wyswietl();
	lista();
};


lista::lista() {
	pierwszy = 0;
}

void lista::wyswietl()
{

	element* temp = pierwszy;


	while (temp)
	{
		cout << "parametr1: " << temp->x << " \tparametr2: " << temp->y <<"\tparametr3: "<<temp->z<< endl;
		temp = temp->nastepny;
	}
}

void lista::usun(int nr)
{

	if (nr == 1)
	{
		element* temp = pierwszy;
		pierwszy = temp->nastepny;
		delete temp;
	}

	else if (nr >= 2)
	{
		int j = 1;

		element* temp = pierwszy;

		while (temp)
		{

			if ((j + 1) == nr) break;


			temp = temp->nastepny;
			j++;
		}


		if (temp->nastepny->nastepny == 0) {
			delete temp->nastepny;
			temp->nastepny = 0;
		}

		else {
			element* usuwany = temp->nastepny;
			temp->nastepny = temp->nastepny->nastepny;
			delete usuwany;
		}
	}
}

void lista::dodaj(string x, string y, int z)
{
	element* nowy = new element;

	nowy->x = x;
	nowy->y = y;
	nowy->z = z;

	if (pierwszy == 0)
	{
		pierwszy = nowy;
	}
	else
	{

		element* temp = pierwszy;

		while (temp->nastepny)
		{
			temp = temp->nastepny;
		}
		temp->nastepny = nowy;
	}
}

int main()
{
	lista* baza = new lista;

	baza->dodaj("maciej", "pierwszy", 23);
	baza->dodaj("arkadiusz", "drugi", 44);
	baza->dodaj("dariusz", "trzeci", 19);
	baza->dodaj("andrzej", "czwarty", 21);
	baza->dodaj("Jozek", "piaty", 22);
	baza->dodaj("twoj", "stary", 91);

	baza->wyswietl();
	baza->usun(3);

	cout << "lista po usunieciu elementu: " << endl;

	baza->wyswietl();

	delete baza;



	return 0;
}
