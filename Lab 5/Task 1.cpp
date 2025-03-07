#include <iostream>
#include <string>
using namespace std;

class Apartment{
    int ID;
    string address;
    string* name;

    public:
    Apartment(int id, string add, string& owner) : ID(id),address(add){
        name=new string(owner);
    }

    Apartment(const Apartment& copy):ID(copy.ID),address(copy.address),name(copy.name){}

    void display(){
        cout<<"Apartment ID: "<<ID<<endl;
        cout<<"Address: "<<address<<endl;
        cout<<"Owner Name: "<<*name<<endl;
        cout<<"\n"<<endl;
    }

    ~Apartment(){
        delete name;
    }
};

int main(){
    string name="Sardar";
    Apartment aprt1(0001,"Landi",name);
    Apartment aprt2(0002,"kotal",name);

    Apartment copyaprt1=aprt1;
    Apartment copyaprt2=aprt2;
    aprt1.display();
    aprt2.display();
    copyaprt1.display();
    copyaprt2.display();


    
}
