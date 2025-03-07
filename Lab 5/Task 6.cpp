#include <iostream>
#include <string>
using namespace std;

class Levels{
    string levelname;
    int levelnum;
    public:
    Levels(string lname, int lnum):levelname(lname),levelnum(lnum){}

    string getLevelName(){
        return levelname;
    }
    int getLevelNum(){
        return levelnum;
    }
};

class VideoGame{
    string name;
    string genre;
    int numlevels;
    Levels** levels;
    int lcount;
    public:
    VideoGame(string n,string g,int numl,Levels* level1):name(n),genre(g),numlevels(numl),lcount(0){
        if(numlevels>0){
            levels=new Levels*[numlevels];
            addLevel(level1);
        }
    }

    void addLevel(Levels* level){
        if(lcount<numlevels){
            levels[lcount]=level;
            lcount++;
        } else {
            cout<<"max level number reached"<<endl;
        }
    }

    void displayGameDetails(){
        cout<<"Game Name: "<<name<<endl;
        cout << "Genre: " <<genre<<endl;
        cout<<"Levels: "<<endl;
        for(int i=0;i<lcount;i++) {
            cout<<"Level "<<levels[i]->getLevelNum()<<": "<<levels[i]->getLevelName()<<endl;
        }
    }

    ~VideoGame() {
        for(int i=0;i<lcount;i++){
            delete levels[i];
        }
        delete[] levels;
    }


};

int main() {
    Levels level1("Birth",1);
    VideoGame game1("Mout ka khel","Mistery",3,&level1);
    Levels level2("Life",2);
    Levels level3("Death",3);
    game1.addLevel(&level2);
    game1.addLevel(&level3);

    game1.displayGameDetails();

    delete &game1;
    



}
