#include <iostream>
#include <string>
using namespace std;

class Student{
    int ID;
    string name;
    int* scores;

    public:
    Student(int id,string sname,int score[]):ID(id),name(sname){
        scores=new int[10];

        for(int i=0;i<10;i++){
            scores[i]=score[i];
        }
    }
    
    Student(const Student& copy):ID(copy.ID),name(copy.name){
        scores=new int[10];

        for(int i=0;i<10;i++){
            scores[i]=copy.scores[i];
        }
    }

    ~Student(){
        delete[] scores;
    }

    void display(){
        cout<<"Student ID: "<<ID<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Scores: ";
        for (int i=0;i<10;i++){
            cout<<scores[i]<<" ";
        }
        cout<<"\n"<<endl;
    }
};

int main(){
    int scores[]={10,22,44,67,98,34,55,42,55,99};
    Student std1(1111,"Mufasa",scores);
    cout<<"Student Info: \n"<<endl;
    std1.display();
    Student copystd=std1;
    cout<<"Student Info (Duplicate): "<<endl;
    copystd.display();
}
