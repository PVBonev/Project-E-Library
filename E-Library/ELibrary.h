#pragma once
#include "Book.h"
class ELibrary
{
private:
	Book** data;
	int capacity;// maximum available capacity
	int size;//the current number of
public:
	void SortbyTitle() const;//declaration of the 3 types
	void SortbyAuthor() const;//of sorting
	void SortbyRating() const;
	void swap(Book& a, Book& b);
}; 