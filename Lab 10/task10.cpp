#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream file("data_records.txt", ios::out);

    if(!file.is_open())
    {
        cout << "Error opening file!" << endl;
        return 1;
    }

    file << "Record 1\n";
    file << "Record 2\n";
    file << "Record 3\n";
    file << "Record 4\n";

    file.close();
    ifstream file2("data_records.txt", ios::in);
    if(!file2.is_open())
    {
        cout << "Error opening file!" << endl;
        return 1;
    }
    file2.seekg(20, ios::beg);
    string line;
    getline(file2, line);
    cout << line << endl;
    file2.close();
    return 0;
}
