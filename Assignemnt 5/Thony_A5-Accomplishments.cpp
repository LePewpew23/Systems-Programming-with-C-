/****SAMPLE PROGRAM HEADER*******************************************************
Name: Kevinson Thony
Due Date:
Course:  C0P3275C
Assignment: Assignment 5

Professor: Sorgente

Description: (Your program description goes here -- what it does--In the program we processed....

*******************************************************************************/

#include <iostream> //standard library for i/o
#include <string> // always include this when you use the string class
using namespace std;


//class declaration here 
class car 
{
public:
    car(); //default constructor
    car(string, string, int, int, double);

    //these are kinda like function prototypes
    //mutator functions (five functions)(changes values)(function prototypes)
    void setMake(string);
    void setModel(string);
    void setPassengers(int);
    void setId(int);
    void setPrice(double);

    //accessor functions (five functions)(views values)(function prototypes)
    string GetMake()const;
    string GetModel()const;
    int GetPassengers()const;
    int GetId()const;
    double GetPrice()const;
 
private: //5 variables

    string make, model;
	int passengers, id;
	double price;  
};
  
//member functions here(function definitions)

//default constructor 
car::car() : make("N/A"), model("N/A"), passengers(0), id(2), price(0)
{
    //left blank intentionally, initalized in above.
}

//explicit value constructor(overloaded)
car::car(string NewMake, string NewModel , int NewPass, int NEwId, double NewPrice)
{
    cout << "\nExplicit value constructor";
    make = NewMake;
    model = NewModel;
    passengers = NewPass;
    id = NEwId;
    price = NewPrice;
}

//mutator functions (five functions)
void car::setMake(string m) { make = m; }
void car::setModel(string m) { model = m; }
void car::setId(int I) { id = I; }
void car::setPassengers(int P) { passengers = P; }
void car::setPrice(double P) { price = P; }

//accessor functions (five functions)
string car::GetMake()const { return make; }
string car::GetModel()const { return model; }
int car::GetId()const { return id; }
int car::GetPassengers()const { return passengers; }
double car::GetPrice()const { return price; }

//-------------------------------------------------------------------
//programmer function prototypes

//input one Vehicle by reference
//get the information for one vegetable with user input 
void GetCarinfo(car& Vehicle);

//input: one const vegetable by reference
//prints the information about a veggie onto the screen
void PrintCarInfo(const car& Vehicle);



int main()
{
    //declare 4 objects
    car sedan("Honda", "Accord", 5, 1, 2999.99), SUV, truck, Van;
    
    //uses the GetCarInfo function to fill Truck and Van objects
    GetCarinfo(truck);
    GetCarinfo(Van);

    //print the info for all 4 Vehicles (PrintCarInfo)
    cout << "Explict Constructors\n";
    PrintCarInfo(sedan);
    cout << "Default Consturctors\n";
    PrintCarInfo(SUV);
    PrintCarInfo(truck);
    PrintCarInfo(Van);

    return 0;
}


//input one vegetable by reference
//get the information for one vegetable with user input 
//prompt for input one by one
void GetCarinfo(car& Vehicle)
{
    string make, model;
    int ID, Passengers;
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


//input: one const car by reference
//prints the information about the vehicle onto the screen
void PrintCarInfo(const car& Vehicle)
{
    
    //set the number of decimal places for doubles
    cout.setf(ios::fixed);	
    cout.setf(ios::showpoint);
    cout.precision(2); //use any number here for the number of decimal places
    //Prints data using the getter functions
    cout << "\n\n------Printing Vehicle info-----\n\n";
    cout << "ID: " << Vehicle.GetId() << endl;
    cout << "Make: " << Vehicle.GetMake() << endl;
    cout << "Model: " << Vehicle.GetModel() << endl;
    cout << "Passengers: " << Vehicle.GetPassengers() << endl;
    cout << "Price: $" << Vehicle.GetPrice() << endl;

}















