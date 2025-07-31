#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int xVal = 0, int yVal = 0) : x(xVal), y(yVal) {}

    // Friend function declaration
    friend Point operator+(const Point& a, const Point& b);

    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

// Friend function definition
Point operator+(const Point& a, const Point& b) {
    return Point(a.x + b.x, a.y + b.y);
}

int main() {
    Point p1(3, 4);
    Point p2(1, 2);
    Point result = p1 + p2;

    cout << "Result of p1 + p2: ";
    result.display();  // Output: (4, 6)
    return 0;
}
