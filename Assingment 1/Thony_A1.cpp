/******************************************************************************************************
Name: Kevinson Thony
Date: 5/18/25
Course:COP3275C 042 12897
Assignemnt: Assignment 1
Professor: Sorgente

Description: A program that displays information you input about you or a fictional character you make
******************************************************************************************************/

#include <iostream> //standard libary for I/O
#include <string>   // Neede for my string data types
using namespace std; 

int main() {
    //States what data type the identifiers are  
    string first_name, last_name, color, favorite_food;
    int age;
    double favorite_Number;
    char middle_initial;
    
    //Greets the user
    cout << "Welcome to the Personal info Collector! \n";
    
    //Asks the user a series of questions to asnwer
    cout << "Whats your First name? ";
    cin >> first_name;
    
    cout << "Whats your middle name? ";
    cin >> middle_initial;

    cout << "Whats your last name? ";   
    cin >> last_name ;
    
    //Displays the users info then procedds to ask another set of questions 
    cout << "\nHi " << first_name << " " << middle_initial<< ". " << last_name << ", " << "How old are you? ";
    cin >> age;
    
    cout << "Whats your favorite color? ";
    cin >> color;
    
    cout << "Nice! And whats yur favorite number (decimals are allowed)?";
    cin >> favorite_Number;
    
    cout << "Whats your favorite food?";
    cin.ignore(); //
    getline(cin, favorite_food);
    
    //Outputs all of the users info and thanks them
    cout << "\nThanks, " << first_name << "! Heres what i learned about you: \n";
    cout << "-Youre " << age << " years old \n";
    cout << "-Your favorite number is " << favorite_Number << "\n";
    cout << "-Your favorite food is " << favorite_food << "\n";
    cout << "\n";
    cout << "Goodbye and have a great day!";
}

