/*
 * Name: Kevinson Thony
 * Date: May 12, 2025
 * Course: COP 3275C
 * Description: Console-based virtual vegetable store management system.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// Base class declaration
class Produce {
private:
    string name;
    string color;
public:
    Produce();
    Produce(const string& name, const string& color);
    ~Produce();
    string getName() const;
    void setName(const string& name);
    string getColor() const;
    void setColor(const string& color);
};

// Derived class declaration
class Vegetable : public Produce {
private:
    double costPerPound;
    double pricePerPound;
    int id;
public:
    Vegetable();
    Vegetable(const string& name, const string& color, double cost, double price);
    ~Vegetable();
    double calculateProfit(double pounds) const;
    double getCostPerPound() const;
    double getPricePerPound() const;
    int getID() const;
    friend Vegetable operator+(const Vegetable& v1, const Vegetable& v2);
    friend bool operator<(const Vegetable& v1, const Vegetable& v2);
};

// Prototype for random ID generator (used in Vegetable constructor)
int generateRandomID();

// Member function implementations
Produce::Produce() : name(""), color("") {}
Produce::Produce(const string& name, const string& color) : name(name), color(color) {}
Produce::~Produce() {}
string Produce::getName() const { return name; }
void Produce::setName(const string& name) { this->name = name; }
string Produce::getColor() const { return color; }
void Produce::setColor(const string& color) { this->color = color; }

Vegetable::Vegetable() : Produce(), costPerPound(0.0), pricePerPound(0.0), id(generateRandomID()) {}
Vegetable::Vegetable(const string& name, const string& color, double cost, double price)
    : Produce(name, color), costPerPound(cost), pricePerPound(price), id(generateRandomID()) {}
Vegetable::~Vegetable() {}
double Vegetable::calculateProfit(double pounds) const {
    return (pricePerPound - costPerPound) * pounds;
}
double Vegetable::getCostPerPound() const { return costPerPound; }
double Vegetable::getPricePerPound() const { return pricePerPound; }
int Vegetable::getID() const { return id; }

// Prototypes for programmer-defined functions
vector<Vegetable> loadVegetables(const string& filename);
void saveResult(const string& filename, const Vegetable& veg, double pounds, double profit);
void displayMenu(const vector<Vegetable>& vegetables);
int getUserSelection(int maxOption);
double getPounds();

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    // Load vegetables from file
    vector<Vegetable> vegetables = loadVegetables("vegetables.txt");
    cout << "Finished reading the file." << endl << endl;

    int choice;
    do {
        displayMenu(vegetables);
        choice = getUserSelection(static_cast<int>(vegetables.size()));
        if (choice == 0) break;
        if (choice < 0 || choice > static_cast<int>(vegetables.size())) {
            cout << "Invalid selection." << endl << endl;
            continue;
        }
        Vegetable& selected = vegetables[choice - 1];
        double pounds = getPounds();
        double profit = selected.calculateProfit(pounds);
        cout << fixed << setprecision(2);
        cout << "Profit on this transaction: $" << profit << endl << endl;
        saveResult("vegetable_results.txt", selected, pounds, profit);
    } while (choice != 0);

    cout << "Thank you for shopping!" << endl;
    return 0;
}

// Definition of random ID generator
int generateRandomID() {
    return rand() % 10000 + 1;
}

// Load vegetables from file
vector<Vegetable> loadVegetables(const string& filename) {
    vector<Vegetable> veggies;
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening " << filename << endl;
        exit(1);
    }
    string name, color;
    double cost, price;
    while (inFile >> name >> color >> cost >> price) {
        Vegetable veg(name, color, cost, price);
        cout << "Loaded: " << veg.getName() << ", " << veg.getColor()
             << ", $" << veg.getCostPerPound() << ", $" << veg.getPricePerPound() << endl;
        veggies.push_back(veg);
    }
    inFile.close();
    return veggies;
}

// Save transaction result to file
void saveResult(const string& filename, const Vegetable& veg, double pounds, double profit) {
    ofstream outFile(filename, ios::app);
    if (!outFile) {
        cerr << "Error opening " << filename << endl;
        return;
    }
    outFile << "Vegetable name: " << veg.getName() << endl;
    outFile << "Price per pound: $" << veg.getPricePerPound() << endl;
    outFile << "Cost per pound: $" << veg.getCostPerPound() << endl;
    outFile << "Pounds purchased: " << pounds << endl;
    outFile << "Profit: $" << profit << endl;
    outFile << "--------------------------" << endl;
    outFile.close();
}

// Display the menu of available vegetables
void displayMenu(const vector<Vegetable>& vegetables) {
    cout << "--- Virtual Vegetable Store ---" << endl;
    cout << "Available Vegetables:" << endl;
    for (size_t i = 0; i < vegetables.size(); ++i) {
        const Vegetable& v = vegetables[i];
        cout << (i + 1) << ". " << v.getName() << " (" << v.getColor() << ") - $"
             << fixed << setprecision(2) << v.getPricePerPound() << "/lb" << endl;
    }
    cout << "0. Exit" << endl << endl;
    cout << "Choose a vegetable by number: ";
}

// Get the user's menu choice
int getUserSelection(int maxOption) {
    int choice;
    cin >> choice;
    return choice;
}

// Get the number of pounds to purchase
double getPounds() {
    double pounds;
    cout << "Enter pounds to purchase: ";
    cin >> pounds;
    return pounds;
}

// Friend function: concatenate names
Vegetable operator+(const Vegetable& v1, const Vegetable& v2) {
    string newName = v1.getName() + " and " + v2.getName();
    string newColor = v1.getColor() + " & " + v2.getColor();
    return Vegetable(newName, newColor, 0.0, 0.0);
}

// Friend function: compare cost per pound
bool operator<(const Vegetable& v1, const Vegetable& v2) {
    return v1.getCostPerPound() < v2.getCostPerPound();
}
