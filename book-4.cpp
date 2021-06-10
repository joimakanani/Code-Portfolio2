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

#include "Book.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//*************************************************************************

void Book :: checkIN()
{
    if(out)
        out = false;
}

//*************************************************************************

void Book:: checkOUT()
{
    if(!out)
        out = true;
}

//*************************************************************************

void Book :: displayBook()
{
    cout << "ISBN: " << isbn << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Copyright: " << copyright << endl;
    cout << "Genre: " << genre << endl;
}

//*************************************************************************

void Book :: outputBook(ofstream &outFile, char choice)
{
    if (choice == 'R')
    {
        outFile << "isbn: " << isbn;
    }
    else
    {
        outFile << isbn << '|' << title << '|' << author << '|' << copyright << '|' << genre << endl;
    }
}

//*************************************************************************

Book :: Book()
{
    isbn = "";
    title = "";
    author = "";
    copyright = "";
    genre = "";
    out = false;
}

//*************************************************************************

Book :: Book(string i, string t, string a, string c, string g, bool o)
{
    isbn = i;
    title = t;
    author = a;
    copyright = c;
    genre = g;
    out = o;
}
//*************************************************************************
