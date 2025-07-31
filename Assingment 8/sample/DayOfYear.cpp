#include <iostream>
#include "DayOfYear.h"

using namespace std;

//member function definitions

//constructor initializes member variables to 0
DayOfYear::DayOfYear() : month(0), day(0)
{
	//body is intentionally left blank
}

//constructor initializes member variables to newMonth and newDay
DayOfYear::DayOfYear(int newMonth, int newDay)
{
	month = newMonth;
	day = newDay;
}


//gets the date from the user
void DayOfYear::input()
{
	//dot operator is not needed because it is a member function
	cout << "\nEnter the month as a number: ";
	cin >> month;

	cout << "\nEnter the day of the month: ";
	cin >> day;
}

//prints the month and day
void DayOfYear::output() const
{
	//dot operator is not needed because it is a member function
	cout << "\nmonth is " << month
		<< ", day is " << day << endl;
}


//sets the month and day of an object
void DayOfYear::set(int newMonth, int newDay)
{
	month = newMonth;
	day = newDay;
	checkDate();
}

//confirms correct values for month and day
void DayOfYear::checkDate()
{
	if ((month < 1) || (month > 12) || (day < 1) || (day > 31))
	{
		cout << "\nThat is an illegal date " << "program will end" << endl;
		exit(1);
	}
}


//returns the month
int DayOfYear::getMonth() const
{
	return month;
}


//returns the day
int DayOfYear::getday() const
{
	return day;
}


