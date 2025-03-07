#include <iostream>
#include <string>
using namespace std;

class Products{
    int id;
    string name;
    int quantity;
    public:
    Products(int pid,string pname,int quan):id(pid),name(pname),quantity(quan){
    }

    int getID(){
        return id;
    }

    string getName(){
        return name;
    }

    int getQuantity(){
        return quantity;
    }

    void displayproduct(){
        cout<<"Product ID: "<<id<<endl;
        cout<<"Product Name: "<<name<<endl;
        cout<<"Product Quantity: "<<quantity<<endl;
    }
};

class Warehouse{
    Products** products;
    int productcount;
    int limit;
    public:
    Warehouse(int lim):limit(lim),productcount(0){
        products=new Products*[limit];
    }

    void addProduct(int pid,string pname,int quan){
        if (productcount<limit){
            products[productcount] = new Products(pid, pname, quan);
            productcount++;
        } else {
            cout<<"Warehouse is full. Cannot add more products"<<endl;
        }
    }

    void searchByID(int id) {
        bool found=false;
        for (int i=0;i<productcount;i++) {
            if (products[i]->getID()==id) {
                products[i]->displayproduct();
                found=true;
                break;
            }
        }
        if (found==false) {
            cout<<"Product with ID "<<id<<" not found"<<endl;
        }
    }

    void displayAllProducts() {
        for (int i=0; i<productcount;i++) {
            products[i]->displayproduct();
            cout<<endl;
        }
    }

    void sortProducts() {
        for (int i=0;i<productcount-1;i++) {
            for (int j=0;j<productcount-i-1;j++) {
                if(products[j]->getName()>products[j+1]->getName()) {
                    Products* temp =products[j];
                    products[j]=products[j + 1];
                    products[j + 1]=temp;
                }
            }
        }
        displayAllProducts();
        
    }

    ~Warehouse() {
        for (int i=0;i<productcount;i++) {
            delete products[i]; 
        }
        delete[] products; 
    }
    


};

int main() {
    Warehouse warehouse(5);

    warehouse.addProduct(001, "Bulb", 10);
    warehouse.addProduct(002, "Laserlight", 20);
    warehouse.addProduct(003, "Fridge", 27);
    warehouse.addProduct(004, "Ac", 11);
    warehouse.addProduct(005, "Tv", 13);

    warehouse.sortProducts();


    warehouse.searchByID(001);
    warehouse.searchByID(005);
}
