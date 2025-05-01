#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    ifstream inputFile("vehicles.txt");

    if(!inputFile.is_open()){
        cerr<<"Errpr file couldnt be opened"<<endl;
        return 1;
    }

    string line;

    while(getline(inputFile,line)){
        if(line.empty()||line[0]=='#'){
            continue;
        }
        cout<<line<<endl;
    }

inputFile.close();
}
