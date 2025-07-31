#ifndef CAR_H
#define CAR_H

#pragma once

#include <string> // always include this when you use the string class
using namespace std;

class car
{
    public:
        //friend function can access the private member variables

        //Precondition: Veh1 and Veh2 have values.
        //Returns the sum of the Prices of the 2 Vehicles.
        //friend function can access the private member variables
        friend double operator + (const car& Veh1, const car& Veh2);
        
        //Precondition: Vehicle1 and Vehicle2 have values.
        //Returns true if Vehicle1 cost is less than Vehicle2 cost.
        //otherwise, returns false.
        friend bool operator < (const car& Veh1, const car& Veh2);
        

        car(); //default constructor
        car(string, string, int, int, int, double);

        //mutator functions
        void setMake(string);
        void setModel(string);
        void setPassengers(int);
        void setAccel(int);
        void setId(int);
        void setPrice(double);
        
        //accessor functions
        string GetMake()const;
        string GetModel()const;
        int GetPassengers()const;
        int GetAccel()const;
        int GetId()const;
        double GetPrice()const;

        //compares the 0 to 60 of two vehicels selected by the user
        //returns the fastest car
        string race(const car& otherCar);
 
    private:
        string make, model;
        int passengers, accel, id;
        double price; 
 };
#endif 
