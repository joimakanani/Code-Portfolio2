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

#ifndef Patron_h
#define Patron_h
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//*************************************************************************

class Patron
{
private:
    string firstN;
    string lastN;
    int libID;
    double outstandFees;
    
public:
    void setFirstN(string f){firstN = f;}
    void setLastN(string l){lastN = l;}
    void setLibID(int lib){libID = lib;}
    void setOutstandFees(double of){outstandFees = of;}
    string getFirstN(){return firstN;}
    string getLastN(){return lastN;}
    int getLibID(){return libID;}
    double getOutstandFees(){return outstandFees;}
    
    bool fees();
    void displayPatron();
    void outputPatron(ofstream&, char);
    Patron();
    Patron(string f, string l, int lib, double outstandFees);
    ~Patron();
};
#endif

//*************************************************************************
