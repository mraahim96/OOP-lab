#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
int main()
{
    ifstream file("vehicle.txt");
    if(!file.is_open())
    {
        cout << "Error opening file!" << endl;
        return 1;
    }
    string line;
    stringstream ss;
    string type,id,name,year,Extra;
    float b1;
    int b2;

    while(getline(file, line))
    {
        ss.clear();
        ss.str(line); 

        getline(ss, type, ',');
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, year, ',');
        getline(ss, Extra); 

        if(type == "Autonomous Car")
        {
            size_t pos = Extra.find(":");
            
            if(pos == string::npos)
            {
                cout<< "there is no : present in Extra" << endl;
                continue;
            }
            b1 = stof(Extra.substr(pos+1, 3));

            cout<< "Vehicle Id: " << id << endl;
            cout<< "Value Extracted: " << b1 << endl;
        }

        else if(type == "ElectricVehicle")
        {
            size_t pos = Extra.find(":");
            if(pos == string::npos)
            {
                cout<< "there is no : present in Extra" << endl;
                continue;
            }
            b2 = stoi(Extra.substr(pos+1, 4));

            cout<< "Vehicle Id: " << id << endl;
            cout<< "Value Extracted: " << b2 << endl;
        }

        else if(type == "Hybrid Truck")
        {
            size_t pos1 = Extra.find(":");
            size_t pos2 = Extra.find("|");

            

            if(pos1 == string::npos || pos2 == string::npos)
            {
                cout<< "there is no : or | present in word Extra" << endl;
                continue;
            }
            string p1 = Extra.substr(pos1 + 1, 4);
            string p2 = Extra.substr(pos2 + 11, 2);

            int p = stoi(p1);
            int q = stoi(p2);
            

            cout<< "Cargo: " << p << endl;
            cout<< "Bettery: " << q << endl;
        }

        else
        {
            cout<< " vehicle type is unknown: " << type << endl;
        }
        
    }
    file.close();
    return 0;
}
