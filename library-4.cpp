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

#include "Library.h"
#include "Book.h"
#include "Patron.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//*************************************************************************

void Library :: addBook(Book b)
{
    books[numBooks]= new Book;
    books[numBooks] -> setISBN(b.getISBN());
    books[numBooks] -> setTitle(b.getTitle());
    books[numBooks] -> setAuthor(b.getAuthor());
    books[numBooks] -> setCopyright(b.getCopyright());
    books[numBooks] -> setGenre(b.getGenre());
    
    numBooks++;
}

//*************************************************************************

void Library :: addPatron(Patron p)
{
    patrons[numPatrons]= new Patron;
    patrons[numPatrons] -> setFirstN(p.getFirstN());
    patrons[numPatrons] -> setLastN(p.getLastN());
    patrons[numPatrons] -> setLibID(p.getLibID());
    patrons[numPatrons] -> setOutstandFees(p.getOutstandFees());
    
    numPatrons++;
}

//*************************************************************************

void Library :: addTransaction(int id, string isbn)
{
    int bLoc = -1;
    int pLoc = -1;
    bool found = false;
    int count = 0;
    while(count < numBooks && !found)
    {
        if(books[count] -> getISBN() == isbn &&
           books[count] -> getAvailable() == 0)
        {
            bLoc = count;
            found = true;
        }
        count++;
    }
    count = 0;
    found = false;
    
    while(count < numPatrons && !found)
    {
        if(patrons[count] -> getLibID() == id &&
           patrons[count] -> getOutstandFees() == 0)
        {
            pLoc = count;
            found = true;
        }
        count++;
    }
    if(bLoc != -1 && pLoc != -1)
    {
        t[numTrns] = new Transaction;
        t[numTrns] -> b.setISBN(books[bLoc] -> getISBN());
        books[bLoc] -> checkOUT();
        t[numTrns] -> p.setLibID(patrons[pLoc] -> getLibID());
        t[numTrns] -> date = "";
    }
    if (bLoc = -1)
    {
        cout << "book is unavailable" << endl;
    }
    if (pLoc = -1)
    {
        cout << "patron owes fees" << endl;
    }
}

//*************************************************************************

double Library :: getAllFees()
{
    Patron p;
    double total = 0;
    
    for(int i = 0; i < numPatrons; i++)
    {
        total += p.getOutstandFees();
    }
    return total;
}

//*************************************************************************

void Library:: getBook(string isbn)
{
    for(int i = 0; i < numBooks; i++)
    {
        if(books[i] -> getISBN() == isbn)
        {
            books[i] -> displayBook();
        }
    }
}

//*************************************************************************

void Library:: getPatron(int id)
{
    for(int i = 0; i < numPatrons; i++)
    {
        if(patrons[i] -> getLibID() == id)
        {
            patrons[i] -> displayPatron();
        }
    }
}

//*************************************************************************

void Library:: outputAllBooks(ofstream& outFile, char c)
{
    
    for(int i = 0; i < numBooks; i++)
    {
        books[i] -> outputBook(outFile, c);
    }
}

//*************************************************************************

void Library:: outputAllPatrons(ofstream& outFile, char c)
{
    for(int i = 0; i < numPatrons; i++)
    {
        patrons[i] -> outputPatron(outFile, c);
    }
}

//*************************************************************************

void Library :: checkOutBook(string isbn)
{
    for(int i = 0; i < numBooks; i++)
    {
        if(books[i] -> getISBN() == isbn)
        {
            books[i] -> checkOUT();
        }
    }
}

//*************************************************************************

void Library :: checkInBook(string isbn)
{
    for(int i = 0; i < numBooks; i++)
    {
        if(books[i] -> getISBN() == isbn)
        {
            books[i] -> checkIN();
        }
    }
}

//*************************************************************************

Library :: Library()
{
    for (int i = 0; i < 10000; i++)
        books[i] = nullptr;
    for (int j = 0; j < 1000; j++)
        patrons[j] = nullptr;
    for (int k = 0; k < 50000; k++)
        t[k] = nullptr;
    numBooks = 0;
    numPatrons = 0;
    numTrns = 0;
}

//*************************************************************************

Library :: ~Library()
{
    for(int i = 0; i < 10000; i++)
    {
        if(books[i] != nullptr)
        {
            delete books[i];
            books[i] = nullptr;
        }
        
    for (int j = 0; j < 1000; j++)
        if(patrons[j] != nullptr)
        {
            delete patrons[j];
            patrons[j] = nullptr;
        }
        
    for (int k = 0; k < 50000; k++)
        if(t[k] != nullptr)
        {
            delete t[k];
            t[k] = nullptr;
        }
    }
}

//*************************************************************************
