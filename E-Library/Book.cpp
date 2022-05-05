#include <cstring>
#include <cassert>
#include "Book.h"
#pragma warning(disable:4996)

Book::Book()
{
	//strcpy(this->author, "N/a");
	this->author = nullptr;
	//strcpy(this->title, "N/a");
	this->title = nullptr;
	this->filename = nullptr;
	this->description = nullptr;
	//strcpy(this->filename, "N/a");
	//strcpy(this->description, "N/a");
	this->rating = 0;
	this->ISBN = 00000000;
}
Book::Book(const char* author, const char* title, const char* filename,
		   const char* description,const float rating,const int ISBN)
{
	assert(author != nullptr || title != nullptr || filename != nullptr);
	this->author = new(std::nothrow) char[strlen(author) + 1];
	strcpy(this->author,author);
	this->title = new(std::nothrow) char[strlen(title) + 1];
	strcpy(this->title, title);
	this->filename = new(std::nothrow) char[strlen(filename) + 1];
	strcpy(this->filename, filename);
	this->description = new(std::nothrow) char[strlen(description) + 1];
	strcpy(this->description, description);
	this->rating = rating;
	this->ISBN = ISBN;
}
Book::~Book()
{
	delete[] this->author;
	delete[] this->title;
	delete[] this->filename;
	delete[] this->description;

}
std::ostream& operator<< (std::ostream& out, const Book& book)
{
	out << "Author: " << book.author << " ||| Title: " << book.title << " ||| File name: " << book.filename
		<< " ||| Rating: " << book.rating << "/5" << " ||| ISBN: " << book.ISBN << std::endl
		<< "Description: " << book.description;
}