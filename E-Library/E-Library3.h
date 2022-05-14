#pragma once
#include "BookStatic.h"
class ELibrary
{
private:
	Book** database;//here we have a pointer that points at other pointers...just like the matrixes we did in UP
	size_t capacity;//maximum capacity
	size_t M_size;//current size
	void reallocate();
public:
	ELibrary();
	~ELibrary();
	void sortAuthor();
	void sortTitle();
	void sortISBN();
	ELibrary& operator +=(const Book& book);//we need += for adding books
	ELibrary& operator -=(int fn);//and -= for removing books
	friend std::ostream& operator<< (std::ostream& out, const ELibrary& books);//we predefine << so we can show all books after sorting them(operation 1)
	friend std::istream& operator>> (std::istream& in, ELibrary& books);//we predifine >> so we can add book(operation 3)

};