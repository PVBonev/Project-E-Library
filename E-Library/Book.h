#pragma once
#include <iostream>
class Book
{
private:
	char* author;
	char* title;
	char* filename;
	char* description;
	float rating;
	int ISBN;//identification number 
public:
	Book();
	Book(const char* author,const char* title,const char* filename,
		 const char* description,const float rating,const int ISBN);
	~Book();
	//Book& operator= (Book& other);
	//Book& FindBook(Book& book) const;
	//Book& AddBook(Book& newbook);
	friend std::ostream& operator<< (std::ostream& out, const Book& book);
};