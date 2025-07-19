/***************************************************************************
Name: Kevinson Thony
Due Date: 06-02-25
Course: C0P3275C
Assignment: Assignment 3(Flow and function)
Professor: Sorgente

Description: Promtps the user to enter information for 3 users, then uses the infromation to display there generation,
             and then find the youngest and oldest person, and then displays the leap years for the 3 persons.
*************************************************************/

#include <iostream> //standard library for i/o
#include <string> // always include this when you use the string class
using namespace std;

//function prorotypes go here
//preconditon: The paramaters must have a value assigned to them
//Postcondition: Returns the information that was inputed from the user
//reference parameters for the name,age, year born
void GetInfo(string &name, int &age, int &year); //Call by Reference 

//preconditon: The paramaters must have a value assigned to them
//postcondition: Returns the generation from the inputted year corresponding to the name
//description: takes in the name and year as in input then returns the generation from the inputted year corresponding to the name
void GetGeneration(string name, int year); //Call by Value

//input: 3 names and 3 ages by value
//finds and prints the name and age of the youngest age
void FindYoungest(string name1, int age1, string name2, int age2, string name3, int
age3);

//preconditon: The paramaters must have a value assigned to them
//postcondition: Returns the oldest person from the 3
//Description: Enter the name and age of all 3 people and get a name and age printed of the oldest person
void FindOldest(string name1, int age1, string name2, int age2, string name3, int
age3);

//preconditon: The paramaters must have a value assigned to them
//Postcondition: Returns the leap years since the birth of the persons name
//Description: Enter the name and birthyear and get the leapyears of that person since there birth
void LeapYear(const string &name,const int &year, int years);

int main()
{
    //declare variables for 3 first names, ages, and birthyear
    string name1, name2, name3;
    int age1, age2, age3, birth_year1,birth_year2,birth_year3,years;

    char input;
    do{
        cout << "Gather infromation:\n";
        //ask and get the names, ages, and birthyear one by one
        //call Getinfo funciton 3 times
        GetInfo(name1, age1, birth_year1);
        cout << "--------------------------------------------\n";
        GetInfo(name2, age2, birth_year2);
        cout << "--------------------------------------------\n";
        GetInfo(name3, age3, birth_year3);
        
        cout << "\nGeneration:\n";
        //Returns the generations of the 3 persons inputs based off the birth years
        //call categories funciton 3 times
        GetGeneration(name1, birth_year1);
        cout << std::endl;
        GetGeneration(name2, birth_year2);
        cout << std::endl;
        GetGeneration(name3, birth_year3);
        cout << std::endl;

         cout << "\nYoungest and oldest:\n";
        //find the youngest and print their names and ages
        //FindYoungest(name1, age1, name2, age2, name3, age3);
        FindYoungest(name1, age1, name2, age2, name3, age3);
        cout << std::endl;
        //find the oldest and print their names and ages
        FindOldest(name1, age1, name2, age2, name3, age3);

        cout << std::endl;

        //Returns the leap years from the birth year of the person to the present
        //call LeapYears function 3 imes
        cout << "\nLeapyear:\n";
        LeapYear(name1, birth_year1, years);
        cout << std::endl;
        LeapYear(name2, birth_year2, years);
        cout << std::endl;
        LeapYear(name3, birth_year3, years);

        cout << "\n\nagain?(ENTER 'y' to continue or 'n' to quit)";
        cin >> input;
    }
    while(input =='Y' || input == 'y');
    return 0;
}

//function defintions go here

//reference(by ref) parameters for the name,age, year born
//Collects the user information
void GetInfo(string &name, int &age, int &year)
{
        cout << "Enter Name: ";
        cin >>  name;
        cout << "Enter the year you were born: ";
        cin >> year;
        cout << "Enter your current age: ";
        cin >> age;
}  

//Uses the inputed birth year for the if else loop and prints out the generation depending on if the year firts in the if statment
void GetGeneration(string name, int year)
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



//input: 3 names and 3 ages by value
//finds and prints the name and age of the youngest age(call by value)
//uses an if else statment to compare the ages to find the youngest
void FindYoungest(string name1, int age1, string name2, int age2, string name3, int
age3)
{
    if (age2 > age1 && age3 > age1)
    {
        cout << "The youngest person is: " << name1 << " with the age of " << age1;
    }
    else if (age1 >age2 && age3 > age2)
    {
        cout << "The youngest person is: " << name2 << " with the age of " << age2;
    }
    else 
    {
        cout << "The youngest person is: " << name3 << " with the age of " << age3;
    } 
}

//uses an if else statment to compare the ages to find the oldest
void FindOldest(string name1,int age1, string name2,int age2,string name3,int age3)
{
    if (age2 < age1 && age3 < age1)
    {
        cout << "The oldest person is: " << name1 << " with the age of " << age1;
    }
    else if (age1 < age2 && age3 < age2)
    {
        cout << "The oldest person is: " << name2 << " with the age of " << age2;
    }
    else 
    {
        cout << "The oldest person is: " << name3 << " with the age of " << age3;
    } 
}

//uses a for loop to initalzie the start year and decerments to the birth year while finding leap years
void LeapYear(const string &name,const int &year, int years)
{
    cout << name << ", here are the leap years since you were born:\n";

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

