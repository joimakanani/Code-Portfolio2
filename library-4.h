//*************************************************************************
//
//  Assignment:    #10
//  File:          LibraryV2.cpp
//  Due Date:      Nov. 16 2018
//  Author:        Joi Wilson
//  Course Name:   COSC 1560 01
//  Description:   This program is the final version of the Library
//                 program which focuses on classes
//*************************************************************************

#ifndef Library_h
#define Library_h
#include "Book.h"
#include "Patron.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//*************************************************************************

struct Transaction
{
    Book b;
    Patron p;
    string date;
};

class Library
{
private:
    Book* books[10000];
    Patron* patrons[1000];
    Transaction* t[50000];
    int numBooks;
    int numPatrons;
    int numTrns;

public:
    void addBook(Book b);
    void addPatron(Patron p);
    void addTransaction(int id, string isbn);
    double getAllFees();
    void getBook(string isbn);
    void getPatron(int id);
    int getNumBooks(){return numBooks;}
    int getNumPatrons(){return numPatrons;}
    void outputAllBooks(ofstream&, char);
    void outputAllPatrons(ofstream&, char);
    void checkOutBook(string);
    void checkInBook(string);
    Library();
    ~Library();
};

#endif /* Library_h */

//*************************************************************************
