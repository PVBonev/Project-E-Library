#include <iostream>
#include "Book.h"
//#include "ELibrary.h"
/*void ChoosingOperation()
{
	char input[2] = { '0','\0' };//creating a variable in which we will store the value that will choose
								 //which operation we want to use
	do
	{
		std::cout << "Choose an operation from the list: " << std::endl
			<< "(1)-Sort by title/author/rating" << std::endl
			<< "(2)-Find book" << std::endl
			<< "(3)- Add book" << std::endl
			<< "PRESS ANY OTHER KEY TO EXIT" << std::endl;
		std::cin >> input;
		if (input[1] == '1') std::cout << '1';//SortbyAuthor();
		if (input[1] == '2') std::cout << '2';//ELibrary::SortbyAuthor();
		if (input[1] == '3') std::cout << '3';//ELibrary::SortbyAuthor();
	} while ((input[1] != '1') && (input[1] != '2') && (input[1] != '3'));
}
bool Password(char* password)
{
    if (strcmp(password, "Azsumkomputur0101!"))
        return 1;//compares the string we have entered 
                 //with the set password which is 
                 //Azsumkomputur0101! and returns 1 if
                 // there is coincidence and 0 if there is not
    return 0;
}
*/
int main()
{
	Book B("Anton M", "2 zvezdi", "IM2Z.txt", "Nice book", 3.8, 123456);
	std::cout << B;
    return 0;
}
