// E-Library3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <cstring>
#include "BookStatick.h"
#pragma warning(disable:4996)
void ChoosingOperation()
{
	char input[2];//stores values 1,2,3
	do
	{
		strcpy(input, nullptr);
		std::cout << "Choose an operation from the list: \n"
			<< "(1) - Sort by title/author/ISBN \n"
			<< "(2) - Find book \n"//Title,author,ISBN
			<< "(3) - Add book \n"
			<< "PRESS ENY OTHER KEY TO EXIT";
		std::cin >> input;
		if (input[1] == '1')//action
			if (input[1] == '2')//action
				if (input[1] == '3')std::cout << "1";//action

	} while (input[1] == '1' || input[1] == '2' || input[1] == '3');
}
int main()
{
	//ChoosingOperation();
	Book B("Ivan", "Srednoshtna razhodka", "razhodka.txt", "good book", 3, 12345),
		B11,
		B2("Tony", "Stars", "", "fine book", 4, 12345678),
		B3("Bony", "Star", "shon.txt", " book", 4, 123456789),
		B4("Bony", "Star", "shon.txt", " book", 10, 123456);
	std::cout << B << B11 << B2 << B3 << B4;
	std::cin >> B11;
	
	return 0;
}