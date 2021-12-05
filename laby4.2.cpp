#include <iostream>

int main()
{

	std::cout << "podaj ciag znakow\n";
	char ciag[100];
	std::cin.getline(ciag, 100);
	std::cout << ciag<<"\n";
	int l_znakow = 0;
	while (ciag[l_znakow] != 0)
	{
		l_znakow++;
	}
	int liczba[26];
	for (int i = 0; i < 26 ; i++)
	{
		liczba[i] = 0;
	}
	for (int i = 0; i < l_znakow; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			int num1 = j + 97;
			int num2 = j + 65;
			if (num1 == ciag[i]||num2==ciag[i])
			{
				liczba[j]++;
			}
		}
	}
	for (int i = 0; i < 26; i++)
	{
		char temp = i + 97;
		std::cout<<temp<<"-"<<liczba[i]<<"\n";
	}
}
