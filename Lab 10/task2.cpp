#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
int main(){
ifstream file("vehicles.txt");
string line;
while (getline(file,line)){
    if(line.empty()|| line[0]=='/')continue;
    istringstream iss(line);
    string type,id,name,year,extraData,certification;
    getline(iss,type,',');
    getline(iss,id,',');
    getline(iss,name,',');
    getline(iss,year,',');
    getline(iss,extraData,',');
    getline(iss,certification,','); 

    cout<<"Type : "<<type<<endl;
    cout<<"ID : "<<id<<endl;
    cout<<"Name : "<<name<<endl;
    cout<<"Year : "<<year<<endl;
    cout<<"Extra Data : "<<extraData<<endl;
    cout<<"Certification : "<<certification<<endl;
}
file.close();
}
