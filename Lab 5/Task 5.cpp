#include <iostream>
#include <string>
using namespace std;

class Doctor{
    string name;
    string specialization;
    int experience;
    public:
    Doctor(string n, string s, int exp):name(n),specialization(s),experience(exp){}

    string getName(){
        return name;
    }

    string getSpecialization(){
        return specialization;
    }

    int getExperience(){
        return experience;
    }
};

class Hospital{
    string hospname;
    Doctor** doctor;
    int limit;
    int dcount;
    public:
    Hospital(string name):hospname(name){
        dcount=0;
        limit=50;
        doctor=new Doctor*[limit];
    }

    void addDoctor(Doctor* doc){
        if(dcount==limit){
            cout<<"doctor limit reached"<<endl;
        } else {
            doctor[dcount]=doc;
            dcount++;
            cout<<"doctor added\n"<<endl;
        }
    }

    bool removeDoctor(Doctor* doc){
        for (int i=0;i<dcount;i++) {
            if(doctor[i]->getName()==doc->getName()){
                delete doctor[i];
                for(int j=i;j<dcount-1;j++){
                    doctor[j]=doctor[j+1];
                }
                dcount--;
                return true;
            }
        }
        return false;
    }

    void ChangeHospital(Doctor* doc, Hospital* newhosp){
        if (removeDoctor(doc)==true){
            newhosp->addDoctor(doc);
            cout<<"Doctor "<< doc->getName()<<" moved to "<<newhosp->hospname<<endl;
        } else {
            cout<<"Doctor not found"<<endl;
        }
    }



    void display(){
        cout<<"Hospital Name: "<<hospname<<endl;
        cout<<"Doctors working: \n"<<endl;
        for (int i=0;i<dcount;i++){
            cout<<"Doctor Name: "<<doctor[i]->getName()<<endl;
            cout<<"Specialization: "<<doctor[i]->getSpecialization()<<endl;
            cout<<"Experience: "<<doctor[i]->getExperience()<<" years \n"<<endl;

        }
    }

};

int main(){
    Hospital hosp1("Siut");
    Doctor doc1("Musiala","KneeSurgeon",20);
    Doctor doc2("Pedri","DeathSpecialist",20);
    hosp1.addDoctor(&doc1);
    hosp1.addDoctor(&doc2);
    hosp1.display();

    Hospital hosp2("North West");
    Doctor doc3("Lewangoalski","Specialist",18);
    hosp2.addDoctor(&doc3);
    hosp1.ChangeHospital(&doc2,&hosp2);
    hosp1.removeDoctor(&doc2);
    

    hosp1.display();
    hosp2.display();
}
