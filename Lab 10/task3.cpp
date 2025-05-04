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
    int res;

    while(getline(file, line))
    {
        ss.clear();
        ss.str(line); 

        getline(ss, type, ',');
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, year, ',');
        getline(ss, Extra); 

        if(!(res = stoi(year)))
        {
            cout << "Error converting year to integer!" << endl;
            return 1;
        }

        cout << "Type: " << type << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Year: " << res << endl;
        cout << "Extra: " << Extra << endl;
        cout << "------------------------" << endl;
    }
    file.close();
    return 0;
}
