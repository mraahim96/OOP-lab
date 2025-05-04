#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct InventoryItem
{
    int id;
    char name[20];
};

int main()
{
    InventoryItem item1;
    item1.id = 1;
    strcpy(item1.name, "Item 1");

    fstream file ("inventory.dat", ios::out | ios::binary);
    if(!(file.is_open()))
    {
        cout << "Error opening file!" << endl;
        return 1;
    }


    file.write((char*)&item1, sizeof(item1));
    file.close();
    cout << "Data written to file successfully." << endl;

    InventoryItem item2;
    file.open("inventory.dat", ios::in | ios::binary);
    if(!(file.is_open()))
    {
        cout << "Error opening file!" << endl;
        return 1;
    }
    file.read((char*)&item2, sizeof(item2));
    file.close();

    cout << "ID: " << item2.id << endl;
    cout << "Name: " << item2.name << endl;  
    
    return 0;

}
