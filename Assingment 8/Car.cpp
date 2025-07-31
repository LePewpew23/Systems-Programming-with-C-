#include <iostream> //standard library for i/o
#include <string> // always include this when you use the string class
#include "Car.h"
#include <cctype>

using namespace std;

//member functions here(function definitions)

//default constructor 
car::car() : make("N/A"), model("N/A"), passengers(0), accel(0), id(289), price(0)
{
    cout << "\nDefault constructor";
}

//explicit value constructor(overloaded)
car::car(string NewMake, string NewModel , int NewPass, int NewAccel, int NEwId, double NewPrice)
{
    cout << "\nExplicit value constructor";
    make = NewMake;
    model = NewModel;
    passengers = NewPass;
    id = NEwId;
    accel = NewAccel;
    price = NewPrice;
}

//mutator functions (five functions)
void car::setMake(string m) { make = m; }
void car::setModel(string m) { model = m; }
void car::setId(int I) { id = I; }
void car::setAccel(int a) {accel = a; }
void car::setPassengers(int P) { passengers = P; }
void car::setPrice(double P) { price = P; }

//accessor functions (five functions)
string car::GetMake()const { return make; }
string car::GetModel()const { return model; }
int car::GetId()const { return id; }
int car::GetAccel()const { return accel; }
int car::GetPassengers()const { return passengers; }
double car::GetPrice()const { return price; }

//new function
string car::race(const car& otherCar){
    string result;

    cout << "Ready your engines!!!";
    //uses the accesors functions to get the model and make of what the user has selected for the race and prints it out along with the acceleration
    cout << "\nYour Car: " << GetMake() << " " << GetModel() << " (0-60: " << accel << "s)\n";
    cout << "Opponent Car: " << otherCar.GetMake() << " " << otherCar.GetModel() << " (0-60: " << otherCar.GetAccel() << "s)\n";

    //compares the acceleration of both cars to find whoch is the fastest
    if (accel < otherCar.accel) {
        result += "Your car is the fastest!!! \n";
    }
    else if (accel > otherCar.accel) {
        result += "The opponent's car is faster :( \n";
    }
    else {
        result += "It's a TIE!!!\n";
    }
    //returns the result of who wins
    return result;
}