//Separate compilation for class DayOfYear

#include <iostream>
#include "DayOfYear.h"

using namespace std;

//main driver function
int main()
{
	DayOfYear today, bach_birthday(3, 21);

	cout << "Enter today's date:\n";
	today.input();
	cout << "Today's date is ";
	today.output();

	cout << "J. S. Bach's birthday is ";
	bach_birthday.output();

	//comares 2 days of the year
	if (today == bach_birthday)
		cout << "Happy Birthday Johann Sebastian!\n";
	else
		cout << "Happy Unbirthday Johann Sebastian!\n";
	return 0;
}

//overload the == operator
bool operator == (const DayOfYear& date1, const DayOfYear& date2)
{
	return (date1.month == date2.month &&
		date1.day == date2.day);
}