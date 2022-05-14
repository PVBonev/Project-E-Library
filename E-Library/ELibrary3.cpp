#include "E-Library.h"
#include <iostream>

void ELibrary::reallocate()
{
    Book** newData = new Book * [capacity * 2];
    capacity *= 2;
    for (int i = 0; i < M_size; ++i)
    {
        newData[i] = database[i];
    }
    delete[] database;
    database = newData;
}

ELibrary::ELibrary()
{
    capacity = 8;
    M_size = 0;
    database = new Book * [capacity];

}

ELibrary::~ELibrary()
{
    for (int i = 0; i < M_size; ++i)
    {
        delete database[i];
    }

    delete[] database;
}

void ELibrary::sortAuthor()
{
    for (int i = 0; i < M_size; ++i)
    {
        for (int j = i + 1; j < M_size - i; ++j)
        {
            if (strcmp(database[j]->getAuthor(), database[j - 1]->getAuthor())==1)
            {
                Book* temp = database[j];
                database[j] = database[j - 1];
                database[j - 1] = temp;
            }
        }
    }
}
void ELibrary::sortTitle()
{
    for (int i = 0; i < M_size; ++i)
    {
        for (int j = i + 1; j < M_size - i; ++j)
        {
            if (strcmp(database[j]->getTitle(), database[j - 1]->getTitle()) == 1)
            {
                Book* temp = database[j];
                database[j] = database[j - 1];
                database[j - 1] = temp;
            }
        }
    }
}
void ELibrary::sortISBN()
{
    if (this->M_size == 0)
    {
        std::cout << "No books in registry!\n";
    }
    for (int i = 0; i < M_size; ++i)
    {
        for (int j = i + 1; j < M_size - i; ++j)
        {
            if (database[j]->getISBN() > database[j - 1]->getISBN())
            {
                Book* temp = database[j];
                database[j] = database[j - 1];
                database[j - 1] = temp;
            }
        }
    }
}
/*
void ELibrary::filter(bool(*pred)(const Book&))
{
    for (int i = 0; i < m_size; ++i)
    {
        if (pred(*data[i]))
        {
            std::cout << *data[i];
        }
    }
}
*/
ELibrary& ELibrary::operator +=(const Book& st)
{
    if (M_size == capacity)
    {
        ELibrary();
    }
    database[M_size++] = new Book(st);

    return *this;
}

ELibrary& ELibrary::operator -=(int fn)
{
    for (int i = 0; i < M_size; ++i)
    {
       
            std::swap(database[i], database[--M_size]);
            delete database[M_size];
            break;
        
    }

    return *this;
}

std::ostream& operator <<(std::ostream& out, const ELibrary& obj)
{
    //out << obj.M_size << '\n';//shows the number of objects currently

    for (int i = 0; i < obj.M_size; ++i)
    {
        out << *obj.database[i];
    }

    return out;
}

std::istream& operator >>(std::istream& in, ELibrary& obj)
{
    int curSize;
    in >> curSize;
    for (int i = 0; i < curSize; ++i)
    {
        Book temp;
        in >> temp;
        obj += temp;
    }

    return in;
}