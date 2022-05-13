#pragma once
#include <iostream>
class Book
{
private:
	char author[256];
	char title[101];
	char filename[64];
	char description[1001];
	short rating;
	int ISBN;//identification number 
public:
	Book();
	Book(const char* author, const char* title, const char* filename,
		const char* description, const float rating, const int ISBN);
	~Book();
	Book& operator= (Book& other);
	friend std::ostream& operator<< (std::ostream& out, const Book& book);
	friend std::istream& operator>> (std::istream& in,  Book& book);

};