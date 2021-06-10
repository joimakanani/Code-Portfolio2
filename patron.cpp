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

#include "Patron.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//*************************************************************************

void Patron:: displayPatron()
{
    cout << "First Name: " << firstN << endl;
    cout << "Last Name: " << lastN << endl;
    cout << "Library ID: " << libID << endl;
    cout << "Outstanding Fees: " << outstandFees << endl;
}

//*************************************************************************

void Patron:: outputPatron(ofstream & outFile, char choice)
{
    if (choice == 'R')
    {
        outFile << "Library ID: " << libID << endl;
    }
    else
    {
        outFile << firstN << ' ' << lastN << ' ' << libID << ' ' << outstandFees << endl;
    }
}

//*************************************************************************

bool Patron :: fees()
{
    bool feesOwed = false;
    
    if (outstandFees > 0)
    {
        feesOwed = true;
    }
    return feesOwed;
}

//*************************************************************************

Patron :: Patron()
{
    firstN = "";
    lastN = "";
    libID = 0;
    outstandFees = 0;
}

//*************************************************************************

Patron :: Patron(string f, string l, int lib, double of)
{
    firstN = f;
    lastN = l;
    libID = lib;
    outstandFees = of;
}

//*************************************************************************

Patron :: ~Patron()
{
    firstN = "";
    lastN = "";
    libID = 0;
    outstandFees = 0;
}

//*************************************************************************
