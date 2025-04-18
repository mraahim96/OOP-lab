#include <iostream>
#include <string>

using namespace std;

class Patient {
protected:
    string name;
    string id;

public:
    Patient(string n, string i) : name(n), id(i) {}

    virtual void displayTreatment() = 0;
    virtual void calculateCost() = 0;
};

class InPatient : public Patient {
public:
    InPatient(string n, string i) : Patient(n, i) {}

    void displayTreatment() {
        cout << "Inpatient Treatment Plan for " << name << " (ID: " << id << "):" << endl;
        cout << "Hospitalization, 24/7 monitoring, surgery if necessary." << endl;
    }

    void calculateCost() {
        cout << "Cost for inpatient care for " << name << " (ID: " << id << "): $5000" << endl;
    }
};

class OutPatient : public Patient {
public:
    OutPatient(string n, string i) : Patient(n, i) {}

    void displayTreatment() {
        cout << "Outpatient Treatment Plan for " << name << " (ID: " << id << "):" << endl;
        cout << "Consultation, diagnostics, follow-up visits as required." << endl;
    }

    void calculateCost() {
        cout << "Cost for outpatient care for " << name << " (ID: " << id << "): $200" << endl;
    }
};

int main() {
    Patient* p1 = new InPatient("Raahim", "101");
    Patient* p2 = new OutPatient("hassan", "102");

    p1->displayTreatment();
    p1->calculateCost();

    p2->displayTreatment();
    p2->calculateCost();

    delete p1;
    delete p2;

    return 0;
}
