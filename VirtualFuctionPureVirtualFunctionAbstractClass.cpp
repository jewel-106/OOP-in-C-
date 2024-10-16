#include<bits/stdc++.h>
using namespace std;

// Abstract base class
class Animal {
public:
    // Pure virtual function
    virtual void sound() = 0;

    // Virtual function
    virtual void display(){
        cout<<"Animal class display function"<<endl;
    }

    // Non-virtual function
    void info() {
        std::cout << "This is an animal" << std::endl;
    }
};

class Dog : public Animal {
public:
    // Providing implementation for the pure virtual function
    void sound() override {
        std::cout << "Bark" << std::endl;
    }
    // Overriding the Animal class display function
    void display() override {
        cout<<"Dog class display function"<<endl;
    }
};

class Cat : public Animal {
public:
    // Providing implementation for the pure virtual function
    void sound() override {
        std::cout << "Meow" << std::endl;
    }
    // Overriding the Animal class display function
    void display() override {
        cout<<"Cat class display function"<<endl;
    }
};

int main() {
    // Animal animal; // Error: cannot instantiate abstract class

    Animal* dog = new Dog();
    Animal* cat = new Cat();

    dog->sound(); // Output: Bark
    cat->sound(); // Output: Meow

    delete dog;
    delete cat;

    return 0;
}
