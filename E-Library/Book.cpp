#include <cstring>
#include <cassert>
#include <iostream>
#include "Book.h"

Book::Book()
{
	strcpy(this->author, "N/a");
	strcpy(this->title, "N/a");
	strcpy(this->filename, "N/a");
	this->rating = 0;
	this->ISBN = 00000000;
}
Book::Book(const char* author, char* title, char* filename, float rating, int ISBN)
{
	assert(author != nullptr || title != nullptr || filename != nullptr);
	strcpy(this->author,author);
	strcpy(this->title, title);
	strcpy(this->filename, filename);
	this->rating = rating;
	this->ISBN = ISBN;
}