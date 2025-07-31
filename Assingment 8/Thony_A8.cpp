/************************************************************************
NAME: Kevinson Thony
Due Date: 7/25/2025
Course:  C0P3275C
Professor: Sorgente
Assignment: Assignment 8 class member functions, explicit value constructor, 
friend function operator overload, separate compilation
Description: My program uses the class car to create 4 objects 1 of which is intialized explicitly while the others use a defualt construr,
             2 of those objects are then accesed with a the mutator functions in the class that then changes the data of the variables for those 2 objects,
            then all of the objects are printied out. It also uses overloaded functions for adding and comparing the prices of the vehicles and also includes a race function 
            that compares the acceleratiion of two car.
**************************************************************************/

#include "Car.h"

#include <iostream> //standard library for i/o
#include <string> // always include this when you use the string class

using namespace std;


//programmer function prototypes

//input one Vehicle by reference
//get the informationfor one vehicle with user input 
void GetCarinfo(car& Vehicle);

//input: one const car by reference, and the vehicle type by refernce
//prints the information about the vehicle onto the screen
void PrintCarInfo(const car& Vehicle, const string& Variation);

int main()
{
    //declare 4 objects
    car sedan("Honda", "Accord", 5, 4,351, 29999.99), super, truck, van;
    
    //use the GetCarInfo function to fill v3 and v4
    GetCarinfo(super);
    GetCarinfo(truck);
    GetCarinfo(van);

    //print the info for all 4 vehicles (PrintCarInfo)
    PrintCarInfo(sedan, "Sedan");
    PrintCarInfo(super, "Super");
    PrintCarInfo(truck, "Truck");
    PrintCarInfo(van, "Van");
    
    //demonstrate the '+' friend function
    cout << "\n---------------demonstrate the '+' friend function-----------------";
    cout << "\nAdding the prices of two vehicels: " <<  sedan.GetModel() << " and " << truck.GetModel();
    double amount = sedan + truck;
    cout << ": $" << amount << endl;

    //demonstrate the '<' friend function
    cout <<"\n---------------demonstrate the '<' friend function-----------------";
    cout << "\nComparing the prices of the " << sedan.GetModel() << " and " << truck.GetModel() << endl;
    if (sedan < truck)
    { cout << "The " << truck.GetModel() << " has a lager price tag than the " << sedan.GetModel(); }
    else {cout << " The " << sedan.GetModel() << " has a lager price tag than the " << truck.GetModel();}
    
    //Demonstrate the added member function
    string option, opponent;
    int speed;
    cout << "\n\nWhat Vehicle type do you want to race?(ex: sedan, truck, van, super) ";
    cin >> option;

    cout << "Choose your opponet(ex: sedan, truck, van, super)";
    cin >> opponent;
    cout << endl;

   car userCar, opponentCar;
    //compares the input to find the proper class to use for the user and the opponents car
    if (option == "sedan"){ userCar = sedan;}
    else if (option == "truck") {userCar = truck;}
    else if (option == "van") {userCar = van;}
    else {userCar = super;}

    if (opponent == "sedan") {opponentCar = sedan;}
    else if (opponent == "truck") {opponentCar = truck;}
    else if (opponent == "van") {opponentCar = van;}
    else {opponentCar = super;}

    //calls the new function race to compare the 0 to 60 speeds and race them
    string winner = userCar.race(opponentCar);
    cout << winner;
    
    cout << "\n\n\nThank you, have a great day!\n\n";
    return 0;
}



//friend function can access the private member variables
//Precondition: Veh1 and Veh2 have values.
//Returns true if Veh1 cost is less than Veh2 cost
//otherwise, returns false.
bool operator < (const car& Veh1, const car& Veh2)

{
    return Veh1.price < Veh2.price;
}


//friend function can access the private member variables
//Precondition: Veh1 and Veh2 have values.
//Returns the sum of the price of the 2 vehicles 
double operator +(const car& Veh1, const car& Veh2)

{
    return Veh1.price + Veh2.price;
}

//input one vegetable by reference
//get the information for one vegetable with user input 
//prompt for input one by one
void GetCarinfo(car& Vehicle)
{
    string make, model;
    int ID, Passengers, accel;
    double Price;
    //gets data from user input and then sends that data to the mutator function
    cout << "\n\n------Getting Vehicle information from the user-----\n\n";
    //make
    cout << "Enter Vehicle make: ";
    cin >> make;
    Vehicle.setMake(make);
    //model
    cout << "Enter Vehicle Model: ";
    cin >> model;
    Vehicle.setModel(model);
    //0 - 60
    cout << "Enter Vehicle 0 - 60: ";
    cin >> accel;
    Vehicle.setAccel(accel);
    //ID
    cout << "Enter Vehicle ID number: ";
    cin >> ID;
    Vehicle.setId(ID);
    //Passengers
    cout << "Enter Vehicle Passengers: ";
    cin >> Passengers;
    Vehicle.setPassengers(Passengers);
    //Price
    cout << "Enter Vehicle Price: ";
    cin >> Price;
    Vehicle.setPrice(Price);
}


//input: one const vegetable by reference
//prints the information about a veggie onto the screen
void PrintCarInfo(const car& Vehicle, const string& Variation)
{
    //set the number of decimal places for doubles
    cout.setf(ios::fixed);	
    cout.setf(ios::showpoint);
    cout.precision(2); //use any number here for the number of decimal places

    //Prints data using the getter functions
    cout << "\n\n------Printing Vehicle info-----\n\n";
    cout << "Vehicle Type: " << Variation << endl;
    cout << "ID: " << Vehicle.GetId() << endl;
    cout << "Make: " << Vehicle.GetMake() << endl;
    cout << "Model: " << Vehicle.GetModel() << endl;
    cout << "Passengers: " << Vehicle.GetPassengers() << endl;
    cout << "Price: $" << Vehicle.GetPrice() << endl;
    cout << "0 - 60: " << Vehicle.GetAccel() << " Seconds\n";
}















