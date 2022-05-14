#include <iostream>
#include <cstring>
#include "E-Library.h"
#pragma warning(disable:4996)//we use this line to deal with strcpy compiler error
bool PasswordCheck(char* password,bool& flag)//checks if the password we have entered is correct which in this case is 12345
{
	if (strcmp(password, "12345") == 0)//password is correct if it is ==0
		flag = true;
	return flag;//if it is -1 or 1 then it is incorrect
}
void ChoosingOperation()
{
	ELibrary elib;
	short input,inp;//stores values 1,2,3 and inp is used for the sorting
	char password[31];
	static bool flag = false;
	do
	{
		std::cout << "\nChoose an operation from the list: \n"
			<< "(1) - Sort books by title/author/ISBN \n"
			<< "(2) - Find book \n"//Title,author,ISBN
			<< "(3) - Add book \n"
			<< "(4) - Remove book\n"
			<< "(5) - Show Book\n\n"
			<< "PRESS ANY OTHER KEY TO EXIT\n\nOperation: ";
		std::cin >> input;
		if (input == 1)
		{
			std::cout << "Choose by which criteria to sort:\n"
					  <<"[1] - Sort by TITLE\n"
					  <<"[2] - Sort by AUTHOR\n"
					  <<"[3] - Sort by ISBN\nChoice: ";
			std::cin >> inp;
			if (inp == 1)
			{
				elib.sortTitle();
			}
			if (inp == 2)
			{
				elib.sortAuthor();
			}
			if (inp == 3)
			{
				elib.sortAuthor();
			}
			std::cout << elib;//after the user chooses how to sort the library we show its contents
		}
		if (input == 2)std::cout << "TEST\n";//action
		if (input == 3)
			{
			    if (flag == false)
				{
					std::cout << "Enter password to perform this action: ";
					std::cin >> password;
				}
				std::cin.ignore();
				if (PasswordCheck(password,flag) == true)
				{
					std::cout << "TRUE\n";
					Book B;
					std::cin >> B;
					elib += B;
				}
				else std::cout << "Wrong password!\n";
			}
		if (input == 4)
		{
			if (flag == false)
			{
				std::cout << "Enter password to perform this action: ";
				std::cin >> password;
			}
			std::cin.ignore();
			if (PasswordCheck(password, flag) == true)
			{
				std::cout << "Correct password\n";
				
				//elib-=B;
				//std::cout<<"Book removed successfully"
				std::cout << "!!!OPERATION UNDER DEVELOPMENT!!!\n";
			}
			else std::cout << "Wrong password!\n";
		}

	} while (input == 1 || input == 2 || input == 3 || input==4 || input==5);//the programm runs while we continue choosing operations
}

int main()
{
	ChoosingOperation();
	/*Book B("Ivan", "Srednoshtna razhodka", "razhodka.txt", "good book", 3, 12345),
		B11,
		B2("Tony", "Stars", "", "fine book", 4, 12345678),
		B3("Bony", "Star", "shon.txt", " book", 4, 123456789),
		B4("Bony", "Star", "shon.txt", " book", 10, 123456);
	std::cout << B << B11 << B2 << B3 << B4;
	Book B11;
	std::cin >> B11;
	std::cout << B11;
	*/
	return 0;
}