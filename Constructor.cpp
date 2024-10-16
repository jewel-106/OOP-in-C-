#include <iostream>
using namespace std;

class Box {
private:
    double width;

public:
    // Non-parameterized constructor
    Box() {
        width = 0.0;  // Setting default value
        cout << "Default constructor called. Width is set to 0." << endl;
    } 
    // Parameterized constructor
    Box(double w) {
        width = w;
        cout << "Parameterized constructor called. Width is set to " << w << "." << endl;
    }
    // Copy constructor
    Box(const Box &box) {
        width = box.width;  // Copy width from the passed object
        cout << "Copy constructor called. Width is copied as " << width << "." << endl;
    }
    void displayWidth() {
        cout << "Width: " << width << endl;
    }
};

int main() {
    Box box1;  // Default constructor is called
    box1.displayWidth();  // Output: Width: 0

    Box box2(10.5);  // Parameterized constructor is called
    box2.displayWidth();  // Output: Width: 10.5

    Box box3 = box1;  // Copy constructor is called

    box1.displayWidth();  // Output: Width: 10.5
    box3.displayWidth();  // Output: Width: 10.5


    return 0;
}
