//*************************************************************************
//
//  Assignment:    #6
//  File:          Park.cpp
//  Due Date:      Oct. 10 2018
//  Author:        Joi Wilson
//  Course Name:   COSC 1560 01
//  Description:   This accepts the class "Park" and hardcodes
//                 information about the class through 14 member
//                 functions called from the main function
//*************************************************************************


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

class Park
{
private:
    string parkName;
    string location,
    month;
    int day,
    year,
    visitors;
    double size;
    
public:
    
    void setParkName(string input);
     void setLocation(string input);
     void setMonth(string input);
    void setYear(int y);
    void setDay(int d);
    void setSize(double s);
     void setVisitor(int v);
    string getParkName();
    string getLocation();
    string getMonth();
    int getDay();
    int getYear();
    double getSize();
    int getVisitors();
    
};

//*************************************************************************

int main()
{
    ofstream outFile;
    ifstream inFile;
    outFile.open("park.txt");
    
    Park p1;
    
    p1.setParkName("Acadia");
    
    outFile << "Park Name: " << setw(12) << p1.getParkName() << endl;
    
    p1.setLocation("Maine");
    
    outFile << "Location: " << setw(12) << p1.getLocation() << endl;
    
    p1.setMonth("February ");
    p1.setDay(26);
    p1.setYear(1919);
    
    outFile << "Established: " << setw(13) << p1.getMonth() << p1.getDay()  << ", " << p1.getYear() << endl;
    
    p1.setSize(47389.67);
    
    outFile << "Size: " << setw(18) << p1.getSize() << " acres" << endl;
    
    p1.setVisitor(3509271);
    
    outFile << "Visitors (2017): " << setw(2) << p1.getVisitors() << endl;
    
    outFile.close();
}

//*************************************************************************

void Park :: setParkName(string name)
 {
 parkName = name;
 }

//*************************************************************************

 void Park :: setLocation(string loc)
 {
 location = loc;
 }

//*************************************************************************
 
 void Park :: setMonth(string mon)
 {
 month = mon;
 }

//*************************************************************************

 void Park :: setYear(int y)
 {
 year = y;
 }

//*************************************************************************

 void Park :: setDay(int d)
 {
 day = d;
 }

//*************************************************************************

 void Park :: setSize(double s)
 {
 size = s;
 }

//*************************************************************************

 void Park :: setVisitor(int v)
 {
 visitors = v;
 }

//*************************************************************************
 
 string Park :: getParkName()
 {
 return parkName;
 }

//*************************************************************************
 
 string Park :: getLocation()
 {
 return location;
 }

//*************************************************************************
 
 string Park :: getMonth()
 {
 return month;
 }

//*************************************************************************
 
 int Park :: getDay()
 {
 return day;
 }

//*************************************************************************
 
 int Park :: getYear()
 {
 return year;
 }

//*************************************************************************
 
 double Park :: getSize()
 {
 return size;
 }

//*************************************************************************
 
 int Park :: getVisitors()
 {
 return visitors;
 }

//*************************************************************************
