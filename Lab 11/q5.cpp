#include<iostream>
#include<exception>

using namespace std;

class NegativeStockException:public exception{};
class OvercapacityException :public exception{};

template<typename T>
class InventoryItem{
    private:
    T stock;
    T maxcapacity;
    public:
    InventoryItem(T max):stock(0),maxcapacity(max){}
    void setStock(T newStock){
        if(newStock<0){
            throw NegativeStockException();
        }
        if (newStock> maxcapacity){
            throw OvercapacityException();
        }
        stock = newStock;
        cout<<"Stock set to : "<<stock<<endl;

    }
    T getstock(){
        return stock;
    }
    
};

int main(){
    InventoryItem <int>item(100);

    try{
        cout<<"attempting to set stock to -5" <<endl;
        item.setStock(-5);

    }
    catch(NegativeStockException e){
        cout<<"caught negativeStock" <<endl;
        cout<<"What () : "<<e.what()<<endl;
    }


    try{
        cout<<"Attempting to set to 120 (over capacity)"<<endl;
        item.setStock(120);

    }

    catch(OvercapacityException e){
        cout<<"Caught over capacity"<<endl;
        cout<<"What () :"<<e.what()<<endl;
    }
}
