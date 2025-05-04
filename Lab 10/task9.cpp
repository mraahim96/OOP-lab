#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    fstream file("large_log.txt", ios::out);
    if(!file.is_open())
    {
        cout << "Error opening file!" << endl;
        return 1;
    }
    file << "This is the first part of the log.\n";
    file << "This is the second part of the log.\n";
    file << "And this is the third part.\n";

    file.close();

    file.open("large_log.txt", ios::in);

    if(!file.is_open())
    {
        cout << "Error opening file!" << endl;
        return 1;
    }

    char ch[10];
    string line;

    file.read(ch, 10);
    getline(file, line);

    size_t pos = file.tellg();
    cout << "Current position in file: " << pos << endl;

    file.read(ch, 10);
    getline(file, line);

    pos = file.tellg();
    cout << "Current position in file: " << pos << endl;

    file.close();
    return 0;
}
