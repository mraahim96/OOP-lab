#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream file("sensor_log.txt");

    if(!file.is_open())
    {
        cout << "Error opening file!" << endl;
        return 1;
    }

    file << "Tung Tung Tung Tung Tung Tung Tung Tung Tung Sahur.\n";
    file << "vs Tralalalelo Tralala .\n";

    size_t pos = file.tellp();
    cout << "Current position in file: " << pos << endl;

    file << "Here he is again,away from 2 3 4 wonderful wonderful wonderful.\n";
    pos = file.tellp();
    cout << "Current position in file: " << pos << endl;

    file << "How good is he?.\n";
    pos = file.tellp();
    cout << "Current position in file: " << pos << endl;

    file.close();

    return 0;


}
