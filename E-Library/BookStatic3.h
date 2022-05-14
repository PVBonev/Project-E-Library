#pragma once
#include <iostream>
class Book//in this class we will store the caracteristics of an individual book
{
private:
	char author[256];//255 is the longest human name
	char title[32];// the average title has 3-5 words
	char filename[42];//we suppose the file name should be the same as the title with aditions of .txt or a little extra note
	char description[1001];//nothing particular about this number again just my personal idea
	short rating;
	int ISBN;//identification number 
public:
	Book();//definition of a constructor without parameters
	Book(const char* author, const char* title, const char* filename,
		const char* description, const float rating, const int ISBN);//default constructor w parameters
	Book& operator= (Book& other);
	const char* getAuthor();//we use this for the sorting algorhitm
	const char* getTitle();//we use this for the sorting algorhitm
	const int getISBN();//we use this for the sorting algorhitm
	friend std::ostream& operator<< (std::ostream& out, const Book& book);//for testing purposes only
	friend std::istream& operator>> (std::istream& in,  Book& book);//used for command add book

};