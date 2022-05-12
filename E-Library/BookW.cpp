#include <cstring>
#include <cassert>
#include "Book.h"
#pragma warning(disable:4996)

Book::Book():author(nullptr),title(nullptr),filename(nullptr),description(nullptr),rating(0),ISBN(0)
{}
Book::Book(const char* author, const char* title, const char* filename,
	const char* description, const float rating, const int ISBN)
{
	assert(author != nullptr);// || title != nullptr || filename != nullptr);

	this->author = new(std::nothrow) char[strlen(author) + 1];
	if (!this->author)
	{
		std::cout << "Memory problem!";
		return;
	}
	strcpy(this->author, author);
	
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
	if (book.author == nullptr || book.title == nullptr || book.filename == nullptr ||
		book.description == nullptr || book.rating>5 || book.ISBN>99999999)
	{
		out << "Corrupt data!\n";
	}
	else
	{
		out << "Author: " << book.author << " ||| Title: " << book.title << " ||| File name: " << book.filename
			<< " ||| Rating: " << book.rating << "/5" << " ||| ISBN: " << book.ISBN << std::endl
			<< "Description: " << book.description << std::endl;
	}
	for (int i = 0; i < 100; i++)std::cout << '-';
	std::cout << "\n";

	return out;
}
std::istream& operator>> (std::istream& in, const Book& book)
{
	std::cout << "Enter information about the book:\n Author:";
	in >> book.author;
	std::cout << "Title: ";
	in >> book.title;
	std::cout << "File name: ";
	in >> book.filename;
	std::cout << "Rating(1-5): ";
	//in.ignore();
	//in >> book.rating;
	std::cout << "Description: ";
	in >> book.description;
	return in;
}


Book& Book::operator= (Book& other)
{

	assert(author != nullptr || title != nullptr || filename != nullptr);
	this->author = new(std::nothrow) char[strlen(author) + 1];
	strcpy(this->author, other.author);
	this->title = new(std::nothrow) char[strlen(title) + 1];
	strcpy(this->title, other.title);
	this->filename = new(std::nothrow) char[strlen(filename) + 1];
	strcpy(this->filename, other.filename);
	this->description = new(std::nothrow) char[strlen(description) + 1];
	strcpy(this->description, other.description);
	this->rating = other.rating;
	this->ISBN = other.ISBN;
	return *this;
}
