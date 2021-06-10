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
#include "Patron.h"
#include "Library.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

//*************************************************************************

void loadData(Library &lib);
void parse(string data, string prsd_data[], const int SIZE);
void parsePatron(string data, string prsd_data[], const int SIZE);
bool validate (string isbn);
void menu(Library &lib);
void searchBook(Library lib);
void searchPatron(Library lib);
void addBook(Library &lib);
void addPatron(Library &lib);
void checkOutBook(Library &lib);
void checkInBook(Library &lib);
void quit(Library lib);

//*************************************************************************

int main()
{
    Library lib;
    loadData(lib);
    menu(lib);
    
    return 0;
}

//*************************************************************************

void menu(Library &lib)
{
    char choice = 'z';
    
    do
    {
        cout << endl;
        cout << "**** Welcome to the LIBRARY ****" << endl;
        cout << endl;
        cout << "Below are current functions you may perform" << endl;
        cout << "on the library." << endl;
        cout << endl;
        cout << "A. Search/Display a Book" << endl;
        cout << "B. Check out a Book" << endl;
        cout << "C. Check in a Book" << endl;
        cout << "D. Add a Book" << endl;
        cout << "E. Search/Display a Patron" << endl;
        cout << "F. Add a Patron" << endl;
        cout << "G. Quit the Program" << endl;
        
        cout << "Please enter your menu choice: ";
        cin >> choice;
        choice = toupper(choice);
        
        switch (choice)
        {
            case 'A':
            {
                searchBook(lib);
                break;
            }
            case 'B':
            {
                checkOutBook(lib);
                break;
            }
            case 'C':
            {
                checkInBook(lib);
                break;
            }
            case 'D':
            {
                addBook(lib);
                break;
            }
            case 'E':
            {
                searchPatron(lib);
                break;
            }
            case 'F':
            {
                addPatron(lib);
                break;
            }
            case 'G':
            {
                quit(lib);
                break;
            }
            default: cout << "Please enter a valid choice." << endl;
        }
    } while (choice != 'G');
}

//*************************************************************************

void loadData(Library &lib)
{
    ifstream infile;
    infile.open("book_data.txt");
    ofstream outFile;
    outFile.open("a10.txt");
    
    Book b;
    Patron p;
    const int b_SIZE = 5;
    const int n_SIZE = 2;
    string data;
    string prsd_data[b_SIZE];
    string prsd_ndata[n_SIZE];
    bool valid = true;
    int id;
    double f;
    
    if(!infile)
    {
        cout << "could not open the file";
    }
    
    else
    {
        while (!infile.eof())
        {
            getline(infile,data);
            parse(data, prsd_data, b_SIZE);
            valid = validate(prsd_data[0]);
            
            if (valid)
            {
                b.setISBN(prsd_data[0]);
                b.setTitle(prsd_data[1]);
                b.setAuthor(prsd_data[2]);
                b.setCopyright(prsd_data[3]);
                b.setGenre(prsd_data[4]);
                outFile << b.getISBN() << endl;
                outFile << b.getTitle() << endl;
                outFile << b.getAuthor() << endl;
                outFile << b.getCopyright() << endl;
                outFile << b.getGenre() << endl << endl;
            }
        }
    }
    infile.close();
    
    infile.open("Patron_data.txt");
    
    if(!infile)
    {
        cout << "could not open the file";
    }
    
    else
    {
        while (!infile.eof())
        {
            infile >> id;
            infile.ignore();
            getline(infile,data);
            infile >> f;
            parsePatron(data, prsd_data, n_SIZE);
            p.setLibID(id);
            p.setOutstandFees(f);
            p.setFirstN(prsd_data[0]);
            p.setLastN(prsd_data[1]);
            p.getFirstN();
            outFile << p.getFirstN() << endl;
            p.getLastN();
            outFile << p.getLastN() << endl;
            outFile << p.getLibID() << endl;
            outFile << p.getOutstandFees() << endl;
        }
    }
    infile.close();
    outFile.close();
}

//*************************************************************************

void parse(string data, string prsd_data[], const int b_SIZE)
{
    int curr = 0;
    int prev = 0;
    int count = 0;
    
    while(count < b_SIZE)
    {
        curr = data.find('|', prev);
        prsd_data[count] = data.substr(prev, curr - prev);
        prev = curr + 1;
        count++;
    }
}

//*************************************************************************

bool validate(string id)
{
    bool valid = true;
    
    if (!isdigit(id[0]))
   {
       valid = false;
       
   }
    if (!isdigit(id[1]))
    {
        valid = false;
        
    }
    
    if (!isdigit(id[2]))
    {
        valid = false;
        
    }
    
    if (!isdigit(id[3]))
    {
        valid = false;
    }
    
    return valid;
}

//*************************************************************************

 void parsePatron(string data, string prsd_data[], const int n_SIZE)
 {
     int curr = 0;
     int prev = 0;
     int count = 0;
     
     while(count < n_SIZE)
     {
         curr = data.find(' ', prev);
         prsd_data[count] = data.substr(prev, curr - prev);
         prev = curr + 1;
         count++;
     }
 }

//*************************************************************************

void searchBook(Library lib)
{
    string isbn;
    
    cout << "Please enter the book's ISBN: ";
    cin >> isbn;
    lib.getBook(isbn);
    
}

//*************************************************************************

void searchPatron(Library lib)
{
    int id;
    cout << "Please enter the patron ID: ";
    cin >> id;
    lib.getPatron(id);
}

//*************************************************************************

void addBook(Library &lib)
{
    Book b;
    string isbn,
           title,
           author,
           copyright,
           genre;
    
    cout << endl;
    cout << "**** Enter information for the NEW book ****" << endl;
    cout <<"ISBN: ";
    cin >> isbn;
    cin.ignore();
    cout << "Title: ";
    getline(cin, title);
    cout << "Author's Name: ";
    getline(cin, author);
    cout << "Copyright: ";
    getline(cin, copyright);
    cout << "Genre: ";
    getline(cin, genre);
    
    b.setISBN(isbn);
    b.setAuthor(author);
    b.setTitle(title);
    b.setCopyright(copyright);
    b.setGenre(genre);
    
    lib.addBook(b);
}

//*************************************************************************

void addPatron(Library &lib)
{
    Patron p;
    int id;
    string first,
           last;
    
    cout << endl;
    cout << "**** Enter information for the NEW patron ****" << endl;
    cout <<"ID: ";
    cin >> id;
    cin.ignore();
    cout << "First Name: ";
    getline(cin, first);
    cout << "Last Name: ";
    getline(cin, last);
    
    p.setLibID(id);
    p.setFirstN(first);
    p.setLastN(last);
    
    lib.addPatron(p);
    
}

//*************************************************************************

void checkOutBook(Library &lib)
{
    string isbn;
    
    cout << "Checking out Book" << endl;
    cout << "Please enter the book's ISBN: ";
    cin >> isbn;
    lib.checkOutBook(isbn);
    
}

//*************************************************************************

void checkInBook(Library &lib)
{
    string isbn;
    
    cout << "Checking in Book" << endl;
    cout << "Please enter the book's ISBN: ";
    cin >> isbn;
    lib.checkInBook(isbn);
}

//*************************************************************************

void quit(Library lib)
{
    ofstream bOut;
    ofstream pOut;
    
    bOut.open("book_output.txt");
    pOut.open("patron_output.txt");
    
    lib.outputAllBooks(bOut, 'z');
    lib.outputAllPatrons(pOut, 'z');
    
    bOut.close();
    pOut.close();
    
    bOut.open("book_formatted.txt");
    pOut.open("patron_formatted.txt");
    
    lib.outputAllBooks(bOut, 'R');
    lib.outputAllPatrons(pOut, 'R');
    
    bOut.close();
    pOut.close();
    
    cout << "4 new data files created.";
    cout << " Quitting program.";
}

//*************************************************************************
