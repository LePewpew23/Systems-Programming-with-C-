
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

using namespace std;

//FUNCTION PROTOTYPES GO HERE 


//reference parameters for the name and year born 
//returns the age
int GetInfo(string &name,int &year);

//input: ONE name and ONE birthyear by value
//prints the name and generation category 
void Categories(string name, int year);

//input: 3 names and 3 ages by value
//finds and prints the name of the youngest age
//reruns the youngest Age
int FindYoungest(string name1, int age1, string name2, int age2, string name3, int age3);

//input: 3 names and 3 ages by value
//finds and prints the name of the oldest age
//returns the oldest age
int FindOldest(string name1, int age1, string name2, int age2, string name3, int age3);

//input: year by reference (const)
//prints all the leap years onto the screen from birth year until present year (2025)
void LeapYears(const int &year, const string &name);


//input: 3 names and 3 ages by value
//calls the FindYoungest and FindOldest funcitons
//prints the youngeast and oldest ages onto the screen and returns the difference
int OldAndYoung(string name1, int age1, string name2, int age2, string name3, int age3);


#endif