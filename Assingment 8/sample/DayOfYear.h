//header file for DayOfyear
//#ifndef DAYOFYEAR_H
//#define DAYOFYEAR_H
#pragma once

class DayOfYear
{
public:

	//friend function can access the private member variables
	friend bool operator == (const DayOfYear& date1, const DayOfYear& date2);
	//Precondition: date1 and date2 have values.
	//Returns true if date1 and date2 represent the same date;
	//otherwise, returns false.
	
	DayOfYear(); //default constructor 
	DayOfYear(int, int); //explicit-value constructor
	void input();
	void output() const;

	void set(int newMonth, int newDay);
	//precondition: newmonth and newDay form a possible date
	//postCondition: The date is reset according to arguments

	int getMonth() const;
	//returns the month (1-12), 1 for January, etc.

	int getday() const;
	//returns the day of the month

private:

	void checkDate();
	//checks if the month and day values are in the correct range
	int month;
	int day;
};

//#endif DAYOFYEAR_H