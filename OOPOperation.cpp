#include<bits/stdc++.h>
using namespace std;

// Base class (demonstrating Encapsulation and Abstraction)
class Animal {
private:
    // Private data member (Encapsulation)
    string name;

protected:
    // Protected data member (Accessible by derived classes)
    int age;

public:
    // Constructor to initialize name and age (Encapsulation)
    Animal(string n, int a) : name(n), age(a) {}

    // Public method to access private member name (Abstraction)
    string getName() {
        return name;
    }

    // Virtual function for runtime polymorphism (will be overridden)
    virtual void sound() {
        cout << "This is a generic animal sound!" << endl;
    }

    // A non-virtual function to demonstrate inheritance
    void info() {
        cout << "Animal Name: " << name << ", Age: " << age << endl;
    }

    // Destructor
    virtual ~Animal() {
        cout << "Animal destructor called for " << name << endl;
    }
};

// Derived class demonstrating Inheritance and Polymorphism
class Dog : public Animal {
private:
    string breed;

public:
    // Constructor (Invoking base class constructor)
    Dog(string n, int a, string b) : Animal(n, a), breed(b) {}

    // Overriding base class function (Polymorphism)
    void sound() override {
        cout << "Dog barks!" << endl;
    }

    // Additional function specific to Dog
    void displayBreed() {
        cout << "Breed: " << breed << endl;
    }

    // Destructor
    ~Dog() {
        cout << "Dog destructor called for " << getName() << endl;
    }
};

// Another derived class demonstrating more Polymorphism
class Cat : public Animal {
public:
    // Constructor (Invoking base class constructor)
    Cat(string n, int a) : Animal(n, a) {}

    // Overriding base class function (Polymorphism)
    void sound() override {
        cout << "Cat meows!" << endl;
    }

    // Destructor
    ~Cat() {
        cout << "Cat destructor called for " << getName() << endl;
    }
};

int main() {
    // Encapsulation: Using Animal's constructor to set name and age
    Animal* animal1 = new Animal("Generic Animal", 5);
    animal1->info();     // Calls base class function
    animal1->sound();    // Calls base class sound function

    // Inheritance and Polymorphism: Dog and Cat are derived from Animal
    Animal* dog1 = new Dog("Buddy", 3, "Golden Retriever");
    dog1->info();        // Calls base class function
    dog1->sound();       // Calls Dog's overridden sound function (Polymorphism)

    Animal* cat1 = new Cat("Whiskers", 2);
    cat1->info();        // Calls base class function
    cat1->sound();       // Calls Cat's overridden sound function (Polymorphism)

    // Deleting objects to call destructors
    delete animal1;
    delete dog1;
    delete cat1;

    return 0;
}
