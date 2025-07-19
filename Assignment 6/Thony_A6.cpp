/**********************************************************************
Name: Kevinson Thony
Due Date: 07/11/25
Course:  C0P3275C
Assignment: Assignment 6 Arrays and dynamic arrays
Professor: Sorgente
Description: My program reads a text file named Numbers where it then takes the info of that file line by line putting it into a static array.
			Once the static array is made the user gets to deicde the lenght of a dynamic array by input and then it copies the static array into
			the dynamic array only up to how ever much the user has said to and then the sum and avergea of that dynamic array is calculated and after the calculations
			the user can choose any number to seach for in that dynamic array. 
*************************************************************/
#include <iostream> //standard library for i/o
#include <fstream>
#include <string>

using namespace std;
ifstream fin;

//function prototypes go here
/*
Preconditon: The parameters must have values assiged to them
Postcondtion: Prints out the entire arry based of the size
Description: Takes the array and then prints it out based on the size its given */
void PrintArray(int nums[], int size);

/*
Precondition: The parameters must have values assiged to them and sum and average must be initialezed to 0
Postcondtion: Returns the Sum and average of the Dynamic Array
Description: Takes in the dynamic array and size as values and then references the sum and average which it then returns values to*/
void CalcArray(int dyn[], int size, double& sum, double& average);

/*
Precondtion: The parameters must have values assiged to them
Postconditon: Returns the index of the number being searched in the array if it exist
Description: Scans the array to find the target number and its index location to see if it exist*/
void SearchArray(int dyn[],int size, int target);


int main()
{
	//initalizing variables
	int numberslist[100], index = 0, choosen,* pick, target;
	double sum = 0, avg = 0;
	string line;

	//Opens the file
	fin.open("numbers.txt");
	
	//Checks to see if the file exist
	if (fin.fail())
	{
		cout << "File was not open found.";
	}
	else
	{
		while(getline(fin, line))// Reads the the file line by line and makes each line a string
		{
			//Error checking to avoid the program crashing when reading each line
			try{
				//turns the string into an int
				int value = stoi(line); 
				numberslist[index] = value;
				index++;				
			}
			catch (invalid_argument& e)
			{
				//What to do when it catches an error
				cout << "Skipping line: " << line << endl;
			}

		}

		cout << " \nprint all 100 values to make sure they are read from the file: \n";
		PrintArray(numberslist, index);

		//USer picks how alrge the array gets to be
		cout << "\nHow many integers do you want in the new array (ENTER 1 to 100?) ";
		cin >> choosen; // gets the size of the newe dynamic array

		while (choosen <  1 || choosen > 100) // checks if the number is out range and loops until it isnt if it is
			{
				cout << "\nHow many integers do you want in the new array (ENTER 1 a number 100?) ";
				cin >> choosen;
			}
		// uses the users pick to make set the size of the dynamic arrau	
		pick = new int[choosen];

		//loops through the static array to add the values from it into the new dynamic array based of the users pick
		for (int i = 0; i < choosen; i++)
		{
			pick[i] = numberslist[i];
		}
		//prints the new dynamic array
		PrintArray(pick, choosen);

		//Calculates the sum and average of the dynamic array
		CalcArray(pick, choosen, sum ,avg);
		cout << "\nThe sum is " << sum <<" and the average is " << avg;

		//User enters the target number to search for in the arrayu
		cout << "\nEnter a target integer: ";
		cin >> target;

		SearchArray(pick, choosen, target);

		//delets the dynamic array
		delete[] pick;
	}
	fin.close();
	return  0; 
}


//function defintions go here
//prints out the Array 
void PrintArray(int nums[], int size)
{
	for (int i =0; i < size; i++)
	{
		cout << endl << nums[i];
	}
}

//calculates and returns the sum and average of the elements in the function
void CalcArray(int dyn[], int size, double& sum, double& average)
{
	//sets the decimal size to 2
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2); 

	//reinitializes sum and avg to 0
	sum = 0;
	average = 0;

	//loops through the array to add all of the values to get the sum
	for (int i =0; i < size; i++)
		{
			sum += dyn[i];
		}
		//gets the sum and then divides it by the size of the array
		average = sum / size;
}

//searches through the array
void SearchArray(int dyn[],int size, int target)
{
	//initializes the found to false till it finds a value in the arrayu
	bool found = false;
	for (int i =0; i < size; i++)//loops through the array
		{
			if (target == dyn[i]) //checks to see if the target number is the same to the number in the array one by one
			{
				cout << "The target: " << target << " is at index: " << i << endl; // prints the target and its index
				found = true; // ssets found to true once it finds the same number
			}
		}
	
	if(!found)
	{
		cout << "The target: " << target << " is not in the array";//If nothing is found it prints this out 
	}
}
