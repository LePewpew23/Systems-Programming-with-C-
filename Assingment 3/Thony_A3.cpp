/*********************************************************************
Name: Kevinson
Due Date: 06/10/25
Course:  C0P3275C
Assignment: Assignment 3 FUNCTIONS  separate compilation
Professor: Sorgente

Description: Requestest the user for information for three people, that then becomes processed
to find the generation they were born in, the age difference also the youngest and oldeset person
and then prints the leap year of the person using there birth year.
*************************************************************/
#include <iostream> //standard library for i/o
#include <string> // always include this when you use the string class
#include "functions.h"

using namespace std;



int main()
{
	//declare variables for 3 first names, ages, and birthyear
	string name1, name2, name3;
	int age1, age2, age3, birthyear1, birthyear2, birthyear3;
	char input;
	

	do{
	        //ask and get the names, ages, and birthyear one by one
        	//age1 = GetInfo(name1,year1); //now returns an integer
		cout << "Information: \n";
		age1 = GetInfo(name1, birthyear1);
		cout << "--------------------------------------------\n";
		age2 = GetInfo(name2, birthyear2);
		cout << "--------------------------------------------\n";
		age3 = GetInfo(name3, birthyear3);
	        
		//call categories function 3 times    
		cout << "\nCategories: \n";
		Categories(name1, birthyear1);	
		cout << endl;
		Categories(name2, birthyear2);
		cout << endl;
		Categories(name3, birthyear3);
		cout << endl;

	    //call the OldAndYoung function - it returns an integer
		//print the difference onto the screen	
		cout << "\nAge difference: \n";
		int agedif = OldAndYoung(name1, age1, name2, age2, name3, age3);
		cout << endl;
		// Outputs the difference of the oldest and youngest age
		cout << "\nThe differnece in ages is : " << agedif << "\n";

	    //call LeapYears function 3 times
		cout << "\nLeapYears: \n";
		LeapYears(birthyear1, name1);
		cout << endl;
		LeapYears(birthyear2, name2);
		cout << endl;
		LeapYears(birthyear3, name3);
	        
	        cout << "\n\nagain?(ENTER 'y' to continue or 'n' to quit)";
	        cin >> input;
 
	}
	while(input =='Y' || input == 'y');
	
	return  0;
}