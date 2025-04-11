#include <iostream>
#include <string>
using namespace std;

class Product{
public:
    int productId;
    string productName;
    double price;
    int stockQuantity;

    Product(int id, string name, double price, int stock=0): productId(id), productName(name), price(price), stockQuantity(stock){}

    virtual void applyDiscount(){}
    virtual double calculateTotalPrice(int quantity){ return price*quantity;}
    virtual void display(){
        cout<<"\n\nProduct Id: "<<productId<<endl;
        cout<<"Product Name: "<<productName<<endl;
        cout<<"Price: "<<price<<endl;
        if(stockQuantity!=0) cout<<"Stock Quantity: "<<stockQuantity<<endl;
    }

    friend ostream& operator<<(ostream& out, Product& p){
        out<<"Product: "<<p.productName<<" | Price: "<<p.price;
        return out;
    }

    Product operator+(Product& p) {
        return Product(0, "Bulk Purchase", this->price + p.price);
    }

    virtual ~Product(){}

};

class Electronics: public Product{
public:
    int warrantyPeriod;
    string brand;

    Electronics(int id, string name, double price, int period, string brand, int stock=0): Product(id, name, price, stock), warrantyPeriod(period), brand(brand){}

    void display(){
        Product::display();
        cout<<"Warranty Period: "<<warrantyPeriod<<endl;
        cout<<"Brand: "<<brand<<endl;
    }
};

class Clothing: public Product{
public:
    char size;
    string color;
    string fabricMaterial;

    Clothing(int id, string name, double price, char size, string color, string material, int stock=0): Product(id, name, price, stock), size(size), color(color), fabricMaterial(material){}

    void applyDiscount(){
        price*=0.9; //10% Discount
    }
};

class FoodItem : public Product {
    string expirationDate;
    int calories;

public:
    FoodItem(int id, string name, double p, string expiry, int cal, int stock=0): Product(id, name, p, stock), expirationDate(expiry), calories(cal) {}

    double calculateTotalPrice(int quantity){
        return (quantity > 10) ? (price * quantity * 0.85) : (price * quantity);  // 15% bulk discount
    }
    void display(){
        Product::display();
        cout << "Expiration Dates: " << expirationDate << "\nCalories: " << calories << "\n";
    }
};

class Book : public Product {
    string author;
    string genre;

public:
    Book(int id, string name, double p, string author, string genre, int stock=0): Product(id, name, p, stock), author(author), genre(genre) {}

    void display(){
        Product::display();
        cout << "Author: " << author << "\nGenre: " << genre << "\n";
    }
};

int main(){
    Electronics e1(1, "Iphone", 1500, 4, "Apple");
    Clothing c1(2, "Jacket", 26, 'M', "Green", "Cotton");
    FoodItem f1(3, "Sandwich", 2, "2025-12-10", 95);
    Book b1(4, "The Beginning After the end", 50, "TurtleME", "Peakfiction");

    e1.display();
    c1.display();
    f1.display();
    b1.display();

    c1.applyDiscount();
    cout << "\nNew Clothing Price: " << c1.calculateTotalPrice(1) << "\n";

    cout << "\nBulk Purchase Total Price for 12 Sandwiches: " << f1.calculateTotalPrice(12) << "\n";

    Product bulkPurchase = c1 + f1;
    cout << "\nBulk Purchase: " << bulkPurchase << "\n";
    return 0;
}
