/******************************************************************************
Name: Kevinson Thony
Due Date: 07/18/25
Course:  C0P3275C
Assignment: Assignment 7 character arrays and strings in C++
Professor: Sorgente
Brief description: My program takes the first name of the user and then uses my defined functions
                   to create new and differnt versions of the name and after it asks for short phrase 
                   and does the same to that phrase
*******************************************************************************/
#include <algorithm> //reverse function  and upper function
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

const int Size = 100;

//input: const reference string
//return the reverse of the string
string ReverseIt(const string& word);

//input: const reference string
//return the string in all capital letters
string MakeUpper(const string& word);

//input: const reference string and a string pointer
//dynamically create a sting array and fill it with the NATO phonetic strings
//print the string array
//delete the new string array
void StringArray(const string& word, string* Nato); 

//input: character by value and string by reference
//assign the NATO phonetic string that matches the character (A through Z)
//for any other character assign space " "
void MakeNato(char letter, string &word);

//input: string array and the length of the array
//print the strings in the array in a column
void PrintStringArray(int len, string Nato[]);

//input: const reference string and a pointer to an integer
//dynamically create an integer array and fill it with the corresponding numerical (ASCII) value
//print the integer array
//delete the new integer array
void MakeASCII(const string& word, int *nums);

//input: integer array and the length of the array
//print the integers in the array in a row separated by spaces
void PrintNumberArray(int len, int nums[]);

//input: integer array and the length of the array
//calculate and return the average of the numbers in the array
double CalculateAverage(int len, int nums[]);


int main()
{
    //declares strings for the users first name, reversed first name, upper first name, and pointer for NATO array
    string  Name, RName, UName,* NATO;

    //Gets the name of the user
    cout << "What is your first name: ";
    cin >> Name;

    //reverses the name
    RName = ReverseIt(Name);

    //makes the name all uppercase
    UName = MakeUpper(Name);

    //prints three first name versions onto the screen
    cout << "\nOriginal Name: " << Name << "\nReversed Name: " << RName << "\nUppercase Name: " << UName;

    //calls the StringArray function using he NATO pointer and Upper name
    StringArray(UName,NATO);
    //declares an integer pointer
    int* number;
    
    MakeASCII(Name, number);
    cout << endl;
    MakeASCII(UName, number);
  
    char again;
    
    do{
    
        //declares 3 strings for phrases (original, reversed, upper)
        string Phrase, RPhrase, UPhrase;
        //gets the phrase from the user
        cout << "\n\nEnter a short phrase or title: "; 
        cin.ignore();
        getline(cin, Phrase);
        
        //reverses the phrase
        RPhrase = ReverseIt(Phrase);

        //makes the phrase all uppercase
        UPhrase = MakeUpper(Phrase);

        //prints the three phrase versions onto the screen
        cout << "\nOriginal Phrase: " << Phrase << "\nReversed Phrase: " << RPhrase << "\nUppercase Phrase: " << UPhrase;

        //calls the StringArray function 
        StringArray(UPhrase, NATO);

        MakeASCII(Phrase, number);
        cout << endl;
        MakeASCII(UPhrase, number);

        cout <<"\nwould you like to enter another phrase (y or n)? ";
        cin >> again;
        again = tolower(again);
        
    }while(again == 'y');
    return 0;
}

//function defintions go here


//input: const reference string
//return the reverse of the string
string ReverseIt(const string& word)
{
    string word2 = word;
    reverse(word2.begin(),word2.end());
    return word2;
}

//input: const reference string
//output: return the Uppercased version of the string
string MakeUpper(const string& word)
{
    string  Upper = word;
    //uses the transform function to apply the toupper function to each characters in the string
    transform(Upper.begin(), Upper.end(),Upper.begin(), ::toupper);
    return Upper;
}
    
void StringArray(const string& word, string* Nato)
{
    int len = word.length();//uses the length of the word as an int variable
    Nato = new string[len]; // makes a dynamic array using the length of the word
    for(int i = 0; i < len; i++)
    {
        MakeNato(word[i], Nato[i]);//calls the Nato functiion
    }
    cout << "\n\nNATO Phonetic Version: " << endl;
    //print the string array
    PrintStringArray(len,Nato); //prints the nato function using the pring string array
    delete []Nato; //deletes the nato array
}

void MakeNato(char letter, string &word)
{
    if(letter == 'A') word = "ALPHA";
    else if( letter == 'B') word = "BRAVO";
    else if (letter == 'C') word = "CHARLIE";
    else if( letter == 'D') word = "DELTA";
    else if (letter == 'E') word = "ECHO";
    else if( letter == 'F') word = "FOXTROT";
    else if (letter == 'G') word = "GOLF";
    else if( letter == 'H') word = "HOTEL";
    else if (letter == 'I') word = "INDIA";
    else if( letter == 'J') word = "JULIET";
    else if (letter == 'K') word = "KILO";
    else if( letter == 'L') word = "LIMA";
    else if (letter == 'M') word = "MIKE";
    else if( letter == 'N') word = "NOVEMBER";
    else if (letter == 'O') word = "OSCAR";
    else if( letter == 'P') word = "PAPA";
    else if (letter == 'Q') word = "QUEBEC";
    else if( letter == 'R') word = "ROMEO";
    else if (letter == 'S') word = "SIERRA";
    else if( letter == 'T') word = "TANGO";
    else if (letter == 'U') word = "UNIFORM";
    else if( letter == 'V') word = "VICTOR";
    else if (letter == 'W') word = "WHISKEY";
    else if( letter == 'X') word = "X-RAY";
    else if (letter == 'Y') word = "YANKEE";
    else if (letter == 'Z') word = "ZULU"; 
    else word = " ";
}

void PrintStringArray(int len, string Nato[])
{
    //loops through the string array and prints out its contents
    for(int i =0; i < len; i++)
    {
        cout <<"    " <<Nato[i] << endl;
    }
}

void MakeASCII(const string& word, int *nums)
{
    int len  = word.length(); // uses the length of the word as a int variable
    nums = new int[len]; //creates a dynamic array uisng the length of the word

    for(int i= 0; i <len; i++)
    {
        nums[i] = static_cast<int>(word[i]); //coverts eeach character into the ascii value
    }
    //prints out the ascii version
    cout << "\nASCII Name:  " << word << endl;

    //prints the int array uisng the function print numbre array
    PrintNumberArray(len, nums);

    //calculatse and prints the avg
    double avg = CalculateAverage(len, nums);
    cout << "\nThe Average is : " << avg;

}

void PrintNumberArray(int len, int nums[])
{
    //loops through the int array and prints out its contents
    for( int i = 0; i < len;i++)
    {
        cout << nums[i] << " ";
    }
}

double CalculateAverage(int len, int nums[])
{
    //initalizes the variables to 0
    double avg = 0, sum = 0;
    //loops through the int array and adds the numbers up
    for(int i = 0; i < len; i++)
    {
        sum += nums[i];
    }
    avg = sum / len; //uses the sum and divides it by the amount of numbers there is 
    return avg;
}
