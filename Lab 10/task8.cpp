#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    fstream file("config.txt", ios::out );
    if(!file.is_open())
    {
        cout << "Error opening file!" << endl;
        return 1;
    }
    file << "Airforshare";
    file.close();

    file.open("config.txt", ios::in | ios::out);
    if(!file.is_open())
    {
        cout << "Error opening file!" << endl;
        return 1;
    }
    
    file.seekp(5, ios::beg);
    file << "Chatgpt";
    file.close();

    file.open("config.txt", ios::in);
    if(!file.is_open())
    {
        cout << "Error opening file!" << endl;
        return 1;
    }
    string line;
    while(getline(file, line))
    {
        cout << line << endl;
    }
    file.close();

    return 0;
}
