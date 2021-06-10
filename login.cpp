//*************************************************************************
//
//  Assignment:    #11
//  File:          Login.cpp
//  Due Date:      Dec. 5 2018
//  Author:        Joi Wilson
//  Course Name:   COSC 1560 01
//  Description:   This program simulates the login for the site "singmeup.com"
//                 it focuses on cstrings and qualifications
//*************************************************************************

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;
//*******************************************************************************************************
void run();
void loadData(char[], char[], char[], char[], const int, fstream&);
void validateUsername(char[], const int, bool[], int);
void validatePassword(char[], char[], const int, bool[], int);
void outputResults(char[], char[], char[], bool[], int);
//*******************************************************************************************************

int main()
{
    run();
    
    return 0;
}
//*******************************************************************************************************
void run()
{
    fstream inFile;
    inFile.open("user_data.txt", ios::in);
    
    int size;
    const int SIZE = 20;
    const int U_SIZE = 20;
    const int P_SIZE = 20;
    const int F_SIZE = 9;
    char user[20];
    char username[20];
    char password1[20];
    char password2[20];
    bool fail[F_SIZE] = {0,0,0,0,0,0,0,0,0};
    
    inFile >> size;
    
    for(int i = 0; i < size; i++)
    {
        loadData(user, username, password1, password2, SIZE, inFile);
        validateUsername(username, U_SIZE, fail, F_SIZE);
        validatePassword(password1, password2, P_SIZE, fail, F_SIZE);
        outputResults(user, username, password1, fail, F_SIZE);
    }
    
    inFile.close();
}
//*******************************************************************************************************
void loadData(char user[], char username[], char password1[], char password2[], const int SIZE, fstream& inFile)
{
    inFile.ignore();
    inFile.getline(user, 20);
    inFile >> username;
    inFile >> password1;
    inFile >> password2;
}
//*******************************************************************************************************
void validateUsername(char username[], const int U_SIZE, bool fail[], int F_SIZE)
{
    bool caseFlag = 0;
    bool numFlag = 0;
    
    for(int i = 0; i < F_SIZE; i++)
    {
        fail[i] = 0;
    }
    
    if(username[9] == NULL)
        fail[0] = 1;
    
    for(int i = 0; i < U_SIZE; i++)
    {
        if(username[i] >= 'A' && username[i] <= 'Z')
            caseFlag = 1;
        if(username[i] >= '0' && username[i] <= '9')
            numFlag = 1;
    }
    
    if(caseFlag == 0)
        fail[1] = 1;
    
    if(numFlag == 0)
        fail[2] = 1;
}
//*******************************************************************************************************
void validatePassword(char password1[], char password2[], const int P_SIZE, bool fail[], int F_SIZE)
{
    int result = 0;
    bool uppercaseFlag = 0;
    bool lowercaseFlag = 0;
    bool numFlag = 0;
    bool specialFlag = 0;
    
    if(password1[7] == NULL)
        fail[3] = 1;
    
    result = strcmp(password1, password2);
    if(result != 0)
        fail[4] = 1;
    
    for(int i = 0; i < P_SIZE; i++)
    {
        if(password1[i] >= '0' && password1[i] <= '9')
            numFlag = 1;
        if(password1[i] >= 'A' && password1[i] <= 'Z')
            uppercaseFlag = 1;
        if(password1[i] >= 'a' && password1[i] <= 'z')
            lowercaseFlag = 1;
        if(password1[i] == '!' || password1[i] <= '"' || password1[i] <= '#' || password1[i] <= '$' || password1[i] <= '%' || password1[i] <= '&')
            specialFlag = 1;
    }
    
    if(numFlag == 0)
        fail[5] = 1;
    
    if(uppercaseFlag == 0)
        fail[6] = 1;
    
    if(lowercaseFlag == 0)
        fail[7] = 1;
    
    if(specialFlag == 0)
        fail[8] = 1;
}
//*******************************************************************************************************
void outputResults(char user[], char username[], char password1[], bool fail[], int F_SIZE)
{
    fstream outFile;
    outFile.open("a9.txt", ios::app);
    
    string fail_text[9] = {"Username is less than 10 chars in length",
        "Username does not contain 1 uppercase",
        "Username does not contain 1 lowercase",
        "Password is less than 8 chars in length",
        "Passwords do not match",
        "Password does not contain 1 digit",
        "Password does not contain 1 uppercase char",
        "Password does not contain 1 lowercase char",
        "Password does not contain 1 special char"};
    
    outFile << left << setw(12) << "User: " << user << endl;
    outFile << left << setw(12) << "Username: " << username << endl;
    outFile << left << setw(12) << "Status: ";
    if(fail[0] == 1 || fail[1] == 1 || fail[2] == 1)
    {
        outFile << "Invalid" << endl;
        outFile << left << setw(12) << "Reason(s): ";
        for(int i = 0; i < 3; i++)
        {
            if(fail[i] == 1)
                outFile << fail_text[i] << endl;
        }
    }
    else
        outFile << "Valid" << endl;
    
    outFile << left << setw(12) << "Password: " << password1 << endl;
    outFile << left << setw(12) << "Status: ";
    if(fail[3] == 1 || fail[4] == 1 || fail[5] == 1 || fail[6] == 1 || fail[7] == 1 || fail[8] == 1)
    {
        outFile << "Invalid" << endl;
        outFile << left << setw(12) << "Reason(s): ";
        for(int i = 3; i < 9; i++)
        {
            if(fail[i] == 1)
                outFile << right << fail_text[i] << endl;
        }
    }
    else
        outFile << "Valid" << endl;
    
    outFile << endl;
    
    outFile.close();
}

/*
txt. for program:

User:       
Username:   Linda
Status:     Invalid
Reason(s):  Username is less than 10 chars in length
Username does not contain 1 lowercase
Password:   Carlson
Status:     Invalid
Reason(s):  Password is less than 8 chars in length
Passwords do not match
Password does not contain 1 digit

User:       
Username:   N9r%ZCVD
Status:     Invalid
Reason(s):  Username is less than 10 chars in length
Password:   N9r%ZCVD
Status:     Invalid
Reason(s):  Passwords do not match

User:       Collins
Username:   bigDeal100
Status:     Valid
Password:   9Pu$kmXF
Status:     Valid

User:       
Username:   Katie
Status:     Valid
Password:   Lewis
Status:     Invalid
Reason(s):  Passwords do not match
Password does not contain 1 digit

User:       
Username:   NnYhdG9
Status:     Valid
Password:   NnYhdG9
Status:     Invalid
Reason(s):  Password is less than 8 chars in length
Passwords do not match

User:       Thomas
Username:   jules1994
Status:     Invalid
Reason(s):  Username is less than 10 chars in length
Username does not contain 1 uppercase
Password:   $jules123
Status:     Invalid
Reason(s):  Password does not contain 1 uppercase char

User:       
Username:   Ben
Status:     Invalid
Reason(s):  Username is less than 10 chars in length
Password:   Williams
Status:     Invalid
Reason(s):  Passwords do not match
Password does not contain 1 digit

User:       
Username:   JRRY_XKQ
Status:     Invalid
Reason(s):  Username is less than 10 chars in length
Username does not contain 1 lowercase
Password:   JRRY_XKQ
Status:     Invalid
Reason(s):  Passwords do not match
Password does not contain 1 digit
Password does not contain 1 lowercase char

User:       Hill
Username:   h1llSter00
Status:     Valid
Password:   &d88uQ2$
Status:     Valid

User:       
Username:   Kevin
Status:     Valid
Password:   Michaels
Status:     Invalid
Reason(s):  Passwords do not match
Password does not contain 1 digit

User:       
Username:   kMike_10
Status:     Valid
Password:   kMike_10
Status:     Invalid
Reason(s):  Passwords do not match
*/
