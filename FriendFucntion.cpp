#include <bits/stdc++.h>
using namespace std;

class Box {
private:
    double width;

public:
    Box() : width(0) {}  // Constructor to initialize width to 0

    // Friend function declaration
    friend void printWidth(Box box);

    // Setter function to set the width
    void setWidth(double w) {
        width = w;
    }
};

// Friend function definition
void printWidth(Box box) {
    // Can access private member `width` of class Box
    cout << "Width of the box: " << box.width << endl;
}


class B;  // Forward declaration of class B

class A {
private:
    int valueA;

public:
    A() : valueA(10) {}

    // Declare class B's function as a friend
    friend int sum(A, B);
};
// Multiple Classes:
class B {
private:
    int valueB;

public:
    B() : valueB(20) {}

    // Declare a friend function
    friend int sum(A, B);
};

// Friend function definition
int sum(A objA, B objB) {
    return objA.valueA + objB.valueB;
}


int main() {
    Box box;
    box.setWidth(10.5);

    // Using friend function to access private data
    printWidth(box);  // Output: Width of the box: 10.5

    return 0;
}
