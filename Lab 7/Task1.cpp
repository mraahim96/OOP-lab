#include <iostream>
using namespace std;

class Device{
    protected:
    int ID;
    string Name;
    bool status;
    string location;
    public:
    Device(int i, string n, string loc = " " ) :ID(i),Name(n),location(loc){}
    
    virtual void turnon(){
         status = true;
         cout<<Name<<"Is now ON"<<endl;
    }
    
    virtual void turnoff(){
         status = false;
         cout<<Name<<"Is now OFF"<<endl;
    }
    
    virtual void displayInfo(){
        cout<<"Device ID : "<< ID <<endl;
        cout<<"Device Name : "<< Name <<endl;
        cout<<"Status : "<< status <<endl;
        cout<<"Location : "<< location <<endl;
    }
};

class Light : public Device{
    protected:
    int brightness;
    string colormode;
    public:
    Light (int i, string n, string loc,int b,string c) : Device(i,n,loc),brightness(b),colormode(c){}
    
      void displayInfo() override {
        Device::displayInfo();
        cout << "Brightness: " << brightness << endl;
        cout<< "Color Mode : "<<colormode<<endl;
    }
    
};

class Thermostat : public Device{
    protected:
    int temp;
    public:
    Thermostat(int i, string n, string loc,int t):Device(i,n,loc),temp(t){}
    
    virtual void displayInfo() override{
        Device::displayInfo();
        cout << "Current Temperature: " << temp << "°C" << endl;
    }
    
};

class SecurityCamera:public Device{
    protected:
    string resolution;
    bool recordingstatus;
    bool nightvision;
    public:
    SecurityCamera(int i, string n, string loc,string res,bool nv):Device(i,n,loc),resolution(res),nightvision(nv),recordingstatus(false){}
    void turnon(){
        status = true;
        recordingstatus = true;
        cout<<Name<<" is now ON and recording"<<endl;
    }
    void turnoff(){
        status = false;
        recordingstatus = false;
        cout<<Name<<" is now OFF and not recording"<<endl;
    }
    
    void displayInfo() override{
        Device::displayInfo();
        cout << "Resolution : " << resolution << endl;
        cout<< "Night Vision : "<< (nightvision?"ON":"OFF") << endl;
        cout<< "Recording Status : "<< (recordingstatus?"ON":"OFF") << endl;
    }

};

class SmartPlug:public Device{
    private:
    int powerconsump;
    int timersetting;
    public:
    SmartPlug(int i,string n,string loc,int power,int timer) : Device(i,n,loc),powerconsump(power),timersetting(timer){}
      void turnoff() override {
        status = false;
        cout << Name << " is now OFF."<< endl; 
        cout<<"Power used: " << powerconsump << "Watts" << endl;
    }

    void displayInfo() override {
        Device::displayInfo();
        cout << "Power Consumption: " << powerconsump << "Watts" << endl;
        cout << "Timer Setting: " << timersetting << " minutes" << endl;
    }
};
int main(){
    Light L1(1,"Tube Light","Drawing Room",20,"Yellow");
    Thermostat T1(2,"Heater","Living Room",25);
    SecurityCamera C1(3,"Security Camera","Backyard", "1080p",true);
    SmartPlug P1(4,"Smart Plug","Kitchen",10,5);
    
    L1.displayInfo();
    T1.displayInfo();
    C1.displayInfo();
    P1.turnoff();
    C1.turnon();

    
}
