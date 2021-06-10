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

#ifndef Book_h
#define Book_h
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//*************************************************************************

class Book
{
private:
    string isbn;
    string title;
    string author;
    string copyright;
    string genre;
    bool out;
    
public:
    void setISBN(string i){isbn = i;}
    void setTitle(string t){title = t;}
    void setAuthor(string a){author = a;}
    void setCopyright(string c){copyright = c;}
    void setGenre(string g){genre = g;}
    string getISBN(){return isbn;}
    string getTitle(){return title;}
    string getAuthor(){return author;}
    string getCopyright(){return copyright;}
    string getGenre(){return genre;}
    bool getAvailable(){return out;}
    
    void checkIN();
    void checkOUT();
    void displayBook();
    void outputBook(ofstream& out, char c);
    Book();
    Book(string i, string t, string a, string c, string g, bool o);
};
#endif /* Book_h */

//*************************************************************************
