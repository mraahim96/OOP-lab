#include <iostream>
#include <string>
using namespace std;

class Project;

class Employee{
    string designation;
    string name;
    int projcount=0;
    Project* project[10];
    public:
    Employee (string des, string empname):designation(des),name(empname){}

    string getName(){
        return name;
    }
    string getDesignation(){
        return designation;
    } 

};

class Project{
    string title;
    string deadline;
    int empcount=0;
    Employee* employee[10];
    public:
    Project(string ptitle, string dline):title(ptitle),deadline(dline){}

    void addEmployee(Employee* emp){
        employee[empcount]=emp;
        empcount++;
    }

    void displayProject(){
        cout<<"Project Title: "<<title<<endl;
        cout<<"Project Deadline: "<<deadline<<endl;
        cout<<"\nEmployees Working on this project: \n"<<endl;
        for(int i=0;i<empcount;i++){
            cout<<"Employee Name: "<<employee[i]->getName()<<endl;
            cout<<"Employee Designation: "<<employee[i]->getDesignation()<<endl;
        }
    }

    string getTitle(){
        return title;
    }

    string getDeadline(){
        return deadline;
    }
};

int main(){
    Employee emp1("CEO","John Cena");
    Employee emp2("SEO","John Paseena");
    Project proj1("Game Development","32nd Oct 2026");
    proj1.addEmployee(&emp1);
    proj1.addEmployee(&emp2);
    proj1.displayProject();

    Project proj2("OOP Project","19th July 2027");
    proj2.addEmployee(&emp1);
    proj2.displayProject();

    
}
