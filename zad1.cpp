#include <iostream>
#include <cmath>
#include <conio.h>

int main()
{
	std::cout << "nacisnij klawisz \n";
	int a;
	a = _getch();
	std::cout << a<<std::endl;
	
	if (a >= 97 && a <= 122)
		std::cout << "mala litera";
	else if (a >= 65 && a <= 90)
		std::cout << "duza litera";
	else if (a >= 48 && a <= 57)
		std::cout << "cyfra";
	else
		switch (a)
		{
		case 13:
		{
			std::cout << "enter";
			break;
		}
		case 27:
		{
			std::cout << "ESC";
			break;
		}case 224:
		{
			int b = _getch();
			
			if (b == 75)
				std::cout << "strzalka w lewo";

			else if (b == 77)
				std::cout << "strzalka w prawo";
			else
				std::cout << "inny klawisz";
			break;
		}
		case 0:
		{
			int b = _getch();
			
			if (b == 59)
				std::cout << "F1";
			else
				std::cout << "inny klawisz";
			break;
		}
		case 32:
		{
			std::cout << "spacja";
			break;
		}
	defalut:
		std::cout << "inny klawisz";
		break;
		}

}
