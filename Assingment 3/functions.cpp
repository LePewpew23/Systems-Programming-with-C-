 #include <iostream> //standard library for i/o
#include <string> // always include this when you use the string class
#include "functions.h"

using namespace std;

//FUNCTION DEFINITIONS GO HERE

//input: 3 names and 3 ages by value
//calls the FindYoungest and FindOldest funcitons
//prints the youngeast and oldest ages onto the screen and returns the difference
int OldAndYoung(string name1, int age1, string name2, int age2, string name3, int age3)
{
   //calls FindYoungest
   //calls FindOldest
	int young = FindYoungest(name1, age1, name2, age2, name3, age3);
    int oldest = FindOldest(name1, age1, name2, age2, name3, age3);
    cout << endl;
    //prints the young and old ages
    cout << "The youngest age is " << young << " and the oldest age is " << oldest;

    //returns the difference
    int differnce = oldest - young;
    return differnce;
}

//reference parameters for the name and year input, return the age
int GetInfo(string &name, int &year)
{
        int age;
        //ask and get name and year by reference
		cout  << "Enter name: ";
		cin >> name;

		cout << "Enter the year you were born: ";
		cin >> year;

	    cout << "Enter your current age: ";
	    cin >> age; 
	    return age;
}


//input: 3 names and 3 ages by value
int FindYoungest(string name1, int age1, string name2, int age2, string name3, int age3)
{
    //finds and prints the name of the youngest age
	if (age2 > age1 && age3 > age1)
    {
        cout << "The youngest person is: " << name1 << "\n";
        return age1;//returns the youngest age of 1 if conditons are met
    }
    else if (age1 >age2 && age3 > age2)
    {
        cout << "The youngest person is: " << name2 << "\n";
        return age2;//returns the youngest age of 2 if conditons are met
    }
    else 
    {
        cout << "The youngest person is: " << name3 << "\n";
        return age3;//returns the youngest age of 3 if conditons are met
    } 
}

//input: 3 names and 3 ages by value
int FindOldest(string name1, int age1, string name2, int age2, string name3, int age3)
{
	//finds and prints the name of the oldest age
	if (age2 < age1 && age3 < age1)
    {
        cout << "The oldest person is: " << name1 << "\n";
        return age1;//returns the oldest age of 1 if conditons are met
    }
    else if (age1 < age2 && age3 < age2)
    {
        cout << "The oldest person is: " << name2 << "\n" ;
        return age2;//returns the oldest age of 2 if conditons are met
    }
    else 
    {
        cout << "The oldest person is: " << name3 << "\n";
        return age3;//returns the oldest age of 3 if conditons are met
    } 
	
}

void LeapYears(const int &year, const string &name)
{
	    cout << name << ", here are the leap years since you were born:\n";
        int years = 2025; //sets 2025 as the intialzed year to count down from

    for (years = 2025;  year <= years ; years--)
    {
        if ( years == 1900){
            continue;
        }
        else if (years % 4 == 0)
        {
            cout << "Leap years: " <<  years << "\n";
        }
    }
}


void Categories(string name, int year)
{
	if ( year >= 1901 && year <=1927) 
    {
        cout << name << ": G.I. Genereation!";
    }
    else if (year >= 1928 && year <= 1945 )
    {
        cout << name << ": Traditionalists!"; 
    }
    else if (year >= 1946 && year <= 1964)
    {
        cout << name << ": Baby Boomers!"; 
    }
    else if (year >= 1965 && year <= 1980)
    {
        cout << name << ": Generation X!"; 
    }
    else if (year >= 1981 && year <= 1996)
    {
        cout << name << ": Millennials!"; 
    }
    else if (year >= 1997 && year <= 2012)
    {
        cout << name << ": Generation Z!"; 
    }
    else if (year >= 2013 && year <= 2024)
    {
        cout << name << ": Generation Alpha!"; 
    }
    else if (year > 2025)
    {
        cout << name << ": Generation Beta!";
    }
    else 
    {
        cout << name << ": Wow and you dont look a day over 20"; 
    }
}