/******************************************************************************
NAME: Kevinson Thony
Due Date: 06/18/25
Course:  C0P3275C
Assignment: Assignment 4
Professor: Sorgente

Description: My Program uses opens a text file named Vehicels, whiich it thens reads
			 the info line by line into my 3 diffent objects and then prints them out
*******************************************************************************/

#include <iostream> //standard library for i/o
#include <string> // always include this when you use the string class
#include <fstream> //file IO streams
using namespace std;

//global variable
ifstream fin; //allows to read from the file

//struct definition here
struct Car {
	string make, model;
	int passengers, id;
	double price;  
};

//function protoypes here

//input one instance of your struct by reference and file stream by reference
//get the information for one instance of your struct from the file\

//Preconditon: The file must run and open in order to extract the data
//postconditon:	inputs the info from the line into the member variabel
//Descriptions: Reads the text file line by line filling the member variables
void GetCarInfo(Car& Vehicle, ifstream& fin); 

//input: one const instance of your struct by reference
//prints the information about a instance of your struct onto the screen

//Precondtion: The objects must have the propper data  
//Postcondtion: Propperly formats the inputed infromation to the variales then prints out 
//Description: Prints out all of thje information from the textfile in a formatted form 
void GiveCarInfo(const Car& Vehicle);



int main( )
{
    //declare 3 objects (instances)
	Car Sedan, SUV, Truck;
    //open the file

	fin.open("Vehicles.txt");
	
   	if (fin.fail())//checks to see if the file opens
		//did not find the file
		cout << "Input file did not open correctly" << endl;
	else
	{
	    //gets the information for the sedan
		GetCarInfo(Sedan, fin);
	    //prinst the sedans information
		GiveCarInfo(Sedan);

	    //gets the information for the SUV
		GetCarInfo(SUV, fin);
	    //prints the SUV information	 
	    GiveCarInfo(SUV);

	    //gets the information for the truck
		GetCarInfo(Truck, fin);
	    //prints the Truck information
	    GiveCarInfo(Truck);
	}
	//close the file
    return 0;

}

//function definitions go here
void GetCarInfo(Car& Vehicle, ifstream& fin)
{
	//reads the line of the vehicles make 
	fin >> Vehicle.make;

	//reads the line of the vehicles model
	fin >> Vehicle.model;

	//reads the line of the vehicles passangers
	fin >> Vehicle.passengers;

	//reads the line of the vehicles ID num
	fin >> Vehicle.id;

	//reads the line of the vehicles price
	fin >> Vehicle.price;
}


void GiveCarInfo(const Car& Vehicle)
{
	//formats the decimal points 
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2); 

	//Prints out the lines that were read in order of Id, make,model, passangers, and then prices
	cout << "\n--Printing Vehichle Info---\n";
	cout << "\nVehicle ID: " << Vehicle.id;
	cout << "\nVehicle Make: " << Vehicle.make;
	cout << "\nVehicle Model: " << Vehicle.model;
	cout << "\nVehicle Max Passangers: " << Vehicle.passengers;
	cout << "\nVehicle Price Tag: $" << Vehicle.price << "\n";
}
