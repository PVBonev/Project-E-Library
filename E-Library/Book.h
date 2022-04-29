#pragma once
int bookCount;
const int MAX = 101;
class Book
{
private:
	char author[MAX];
	char title[MAX];
	char filename[MAX];
	float rating;
	int ISBN;//identification number 
public:
	Book();
	Book(const char* author, char* title, char* filename, float rating, int ISBN);
	Book& operator= (Book& other);
	Book& FindBook(Book& book) const;
	Book& AddBook(Book& newbook);
};