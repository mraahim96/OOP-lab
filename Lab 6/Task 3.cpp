#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n,int a):name(n),age(a){}

    virtual void displayDetails() {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
};

class Teacher : virtual public Person {
protected:
    string subject;

public:
    Teacher(string n, int a, string sub):Person(n, a), subject(sub) {}

    virtual void displayDetails() {
        Person::displayDetails();
        cout<<"Subject: "<<subject<<endl;
    }
};

class Researcher : virtual public Person {
protected:
    string researcharea;

public:
    Researcher(string n, int a, string area) : Person(n, a), researcharea(area) {}

    virtual void displayDetails() {
        Person::displayDetails();
        cout<<"Research Area: "<<researcharea<<endl;
    }
};

class Professor : public Teacher, public Researcher {
private:
    int publications;

public:
    Professor(string n, int a, string sub, string area, int pub)
        : Person(n, a), Teacher(n, a, sub), Researcher(n, a, area), publications(pub) {}

    void displayDetails() {
        Teacher::displayDetails();
        Researcher::displayDetails();
        cout<<"Publications: "<<publications<<endl;
    }
};

int main() {
    Professor prof("Virus", 32, "Engineering", "Machine Class", 25);
    cout<<"Professor Details:"<<endl;
    prof.displayDetails();
}
