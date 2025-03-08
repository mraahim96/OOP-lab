#include<iostream>
#include <string>
using namespace std;

class Vehicle{
public:
    string brand;
    int speed;
    Vehicle(string b,int s):brand(b),speed(s){}
    void displayDetails(){
	cout<<"Brand:"<<brand<<"\nSpeed:"<<speed<<" km/h\n";
	}
};

class Car:public Vehicle{
public:
    int seats;
    Car(string b,int s,int seat):Vehicle(b,s),seats(seat){}
    void displayDetails(){
	cout<<"Brand:"<<brand<<"\nSpeed:"<<speed<<" km/h\nSeats:"<<seats<<"\n";
	}
};

class ElectricCar:public Car{
public:
    int batteryLife;
    ElectricCar(string b,int s,int seat,int battery):Car(b,s,seat),batteryLife(battery){}
    void displayDetails(){
	cout<<"Brand:"<<brand<<"\nSpeed:"<<speed<<" km/h\nSeats:"<<seats<<"\nBattery Life:"<<batteryLife<<" hours\n";
	}
};

int main(){
    ElectricCar e("Mercedes Benz",255,4,32);
    e.displayDetails();
}

