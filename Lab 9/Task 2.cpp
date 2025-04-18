#include <iostream>
using namespace std;

class MenuItem {
protected:
    string dishName;
    double price;

public:
    MenuItem(string n, double p) : dishName(n), price(p) {}
    virtual void showDetails() = 0;
    virtual void prepare() = 0;
};

class Appetizer : public MenuItem {
public:
    Appetizer(string n, double p) : MenuItem(n, p) {}

    void showDetails() override {
        cout << "Appetizer: " << dishName << " - $" << price << endl;
    }

    void prepare() override {
        cout << "Preparing appetizer: " << dishName << endl;
    }
};

class MainCourse : public MenuItem {
public:
    MainCourse(string n, double p) : MenuItem(n, p) {}

    void showDetails() override {
        cout << "Main Course: " << dishName << " - $" << price << endl;
    }

    void prepare() override {
        cout << "Cooking main course: " << dishName << endl;
    }
};

int main() {
    MenuItem* m1 = new Appetizer("Chicken Strips", 4.99);
    MenuItem* m2 = new MainCourse("Alfredo Pasta", 22.50);

    m1->showDetails();
    m1->prepare();
    cout << "\n"<<endl;

    m2->showDetails();
    m2->prepare();

    delete m1;
    delete m2;

    return 0;
}
