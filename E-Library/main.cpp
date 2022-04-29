
#include <iostream>
#include "Header.h"
bool Password(char* password)
{
    if (strcmp(password, "Azsumkomputur0101!"))
        return 1;//compares the string we have entered 
                 //with the set password which is 
                 //Azsumkomputur0101! and returns 1 if
                 // there is coincidence and 0 if there is not
    return 0;
}
int main()
{

    return 0;
}
