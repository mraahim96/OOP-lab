#include<iostream>
using namespace std;
class Character {
    protected:
    int ID;
    string name;
    int health;
    int level;
    string weaponType;
    public:
    Character(int i, string n, int h, int l, string w):ID(i),name(n),health(h),level(l),weaponType(w){}
    virtual void attack(){
        cout<<name<<" attacks with "<<weaponType<<endl;
    }
    virtual void defend(){
        cout<<name<<" defends against the attack "<<endl;

    }
    virtual void displayInfo(){
        cout<<"ID: "<<ID<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Health: "<<health<<endl;
        cout<<"Level: "<<level<<endl;
        cout<<"Weapon Type: "<<weaponType<<endl;
    }
};

class Warrior : public Character{
    protected:
    int armorStrength;
    int meeleDamage;
    public:
    Warrior(int i, string n, int h, int l, string w, int a, int md):Character(i,n,h,l,w),armorStrength(a),meeleDamage(md){}
    void attack()override{
        
        cout<<name<<" attacks with a powerful "<<weaponType<<" dealing "<<meeleDamage<<" damage and gaining "<<armorStrength<<" armor strength"<<endl;
    }

};
class Mage :public Character{
protected:
    int manaPoints;
    int spellPower;

public:
    Mage(int id, string n, int lvl, int hp, string weapon, int mana, int power)
        : Character(id, n, lvl, hp, weapon), manaPoints(mana), spellPower(power) {}

    void defend() override {
        
        cout << name << " casts a magical barrier, reducing incoming damage!\n";
    }
};

class Archer : public Character {
private:
    int arrowCount;
    int rangedAccuracy;

public:
    Archer(int id, string n, int lvl, int hp, string weapon, int arrows, int accuracy)
        : Character(id, n, lvl, hp, weapon), arrowCount(arrows), rangedAccuracy(accuracy) {}

    void attack() override {
        if (arrowCount > 0) {
            cout << name << " fires an arrow with " << rangedAccuracy << "% accuracy!"<<endl;
            arrowCount--;
        } else {
            cout << name << " has no arrows left!"<<endl;
        }
    }
};
class Rogue : public Character{
    protected:
    int stealthLevel;
    int agility;
    public:
    Rogue(int i, string n, int h, int l, string w, int s, int ag):Character(i,n,h,l,w),stealthLevel(s),agility(ag){}
    void displayInfo()override{
        Character::displayInfo();
        cout<<"Stealth Level: "<<stealthLevel<<endl;
        cout<<"Agility: "<<agility<<endl;
    }
};
int main(){
    Warrior w(1, "Jin Sakai", 20000, 1000, "Sword", 30, 25);
    Mage m(2, "Arthur", 9000, 100, "Staff", 100, 50);
    Archer a(3, "ArcherQueen", 15000, 70, "Bow", 15, 90);
    Rogue r(4, "Kakashi", 13000, 120, "Dagger", 82, 1500);
    w.displayInfo();
    w.attack();
    
    m.displayInfo();
    m.defend();
    
    a.displayInfo();
    a.attack();
    
    r.displayInfo();
    
    return 0;
}
