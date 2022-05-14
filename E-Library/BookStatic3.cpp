#include <cstring>
#include <cassert>
#include "BookStatic.h"
#pragma warning(disable:4996)

Book::Book() //constructor without parameters that initialises all chars with "no ~something~" and the rest with 0 
{
	strcpy(this->author, "No author");

	strcpy(this->title, "No title");

	strcpy(this->filename, "No filename");

	strcpy(this->description, "No description");

	this->rating = 0;
	this->ISBN = 0;
}
Book::Book(const char* author, const char* title, const char* filename,
	const char* description, const float rating, const int ISBN)//default constructor with parameters
{
	assert(author != nullptr || title != nullptr || filename != nullptr);

	
	strcpy(this->author, author);

	strcpy(this->title, title);

	strcpy(this->filename, filename);

	strcpy(this->description, description);

	this->rating = rating;
	this->ISBN = ISBN;
}/*
Book::~Book()
{
	delete[] this->author;
	delete[] this->title;
	delete[] this->filename;
	delete[] this->description;

}*/

std::ostream& operator<< (std::ostream& out, const Book& book)
{
	if (book.author == nullptr || book.title == nullptr || book.filename == nullptr ||
		book.description == nullptr || book.rating > 5 || book.ISBN > 99999999)
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
std::istream& operator>> (std::istream& in,  Book& book)
{
	std::cout << "Enter information about the book:\n";
	std::cout<<"- Author:";
	in.getline(book.author,256);
	std::cout << "- Title: ";
	in.getline(book.title,101);
	std::cout << "- File name: ";
	in.getline(book.filename,64);
	std::cout << "- Rating(1-5): ";
	in >> book.rating;
	in.ignore();
	std::cout << "- Description: ";
	in.getline(book.description,1001);
	return in;
}


Book& Book::operator= (Book& other)
{

	assert(author != nullptr || title != nullptr || filename != nullptr);
	strcpy(this->author, other.author);
	strcpy(this->title, other.title);
	strcpy(this->filename, other.filename);
	strcpy(this->description, other.description);
	this->rating = other.rating;
	this->ISBN = other.ISBN;
	return *this;
}

const char* Book::getAuthor()
{
	return this->author;
}
const char* Book::getTitle()
{
	return this->title;
}
const int Book::getISBN()
{
	return this->ISBN;
}