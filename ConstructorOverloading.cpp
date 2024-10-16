#include <bits/stdc++.h>
using namespace std;

class Box {
private:
    double width, height, depth;

public:
    // Non-parameterized constructor (default constructor)
    Box() {
        width = 0.0;
        height = 0.0;
        depth = 0.0;
        cout << "Default constructor called. All dimensions set to 0." << endl;
    }

    // Parameterized constructor with one parameter
    Box(double w) {
        width = w;
        height = w;
        depth = w;
        cout << "Constructor with one parameter called. All dimensions set to " << w << "." << endl;
    }

    // Parameterized constructor with three parameters
    Box(double w, double h, double d) {
        width = w;
        height = h;
        depth = d;
        cout << "Constructor with three parameters called. Dimensions set to Width: " << w
             << ", Height: " << h << ", Depth: " << d << "." << endl;
    }

    void displayDimensions() {
        cout << "Width: " << width << ", Height: " << height << ", Depth: " << depth << endl;
    }
};

int main() {
    Box box1;            // Default constructor
    Box box2(5.0);       // Constructor with one parameter
    Box box3(2.5, 3.0, 4.0); // Constructor with three parameters

    cout << "Box 1 dimensions: "; box1.displayDimensions();  // Output: Width: 0, Height: 0, Depth: 0
    cout << "Box 2 dimensions: "; box2.displayDimensions();  // Output: Width: 5, Height: 5, Depth: 5
    cout << "Box 3 dimensions: "; box3.displayDimensions();  // Output: Width: 2.5, Height: 3, Depth: 4

    return 0;
}
