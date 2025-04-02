#include<iostream>
using namespace std;

class Product {
protected:
    int productID;
    string productName;
    double price;
    int stockQuantity;

public:
    Product(int id, string name, double p, int stock) 
        : productID(id), productName(name), price(p), stockQuantity(stock) {}

    virtual void applyDiscount(double discountPercentage) {
        price -= price * (discountPercentage / 100);
    }

    virtual double calculateTotalPrice(int quantity) {
        return price * quantity;
    }

    virtual void displayProductInfo() const {
        cout << "ID : " << productID << endl;
        cout << "Name : " << productName << endl;
        cout << "Price : " << price << endl;
        cout << "Stock Quantity : " << stockQuantity << endl;
    }

    double getPrice() const { return price; }
    
    
    friend double operator+(const Product &p1, const Product &p2) {
        return p1.price + p2.price;
    }

    
    friend ostream &operator<<(ostream &os, const Product &p) {
        p.displayProductInfo();
        return os;
    }
};

class Electronics : public Product {
protected:
    int warrantyPeriod;
    string brand;

public:
    Electronics(int id, string name, double p, int stock, int wp, string br) 
        : Product(id, name, p, stock), warrantyPeriod(wp), brand(br) {}

    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Warranty Period: " << warrantyPeriod << " years" << endl;
        cout << "Brand: " << brand << endl;
    }
};

class Clothing : public Product {
protected:
    string size;
    string color;
    string fabricMaterial;

public:
    Clothing(int id, string name, double p, int stock, string s, string c, string fm) 
        : Product(id, name, p, stock), size(s), color(c), fabricMaterial(fm) {}

    void applyDiscount(double discountPercentage) override {
        price -= price * (discountPercentage / 100);
        cout << "Seasonal Discount Offer Applied" << endl;
    }

    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Size: " << size << endl;
        cout << "Color: " << color << endl;
        cout << "Fabric Material: " << fabricMaterial << endl;
    }
};

class FoodItem : public Product {
protected:
    string expirationDate;
    double calories;

public:
    FoodItem(int id, string name, double p, int stock, string expDate, double cal) 
        : Product(id, name, p, stock), expirationDate(expDate), calories(cal) {}

    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Expiry Date: " << expirationDate << endl;
        cout << "Calories: " << calories << " kcal" << endl;
    }

    double calculateTotalPrice(int quantity) override {
        return (quantity > 10) ? price * quantity * 0.9 : price * quantity;
    }
};

int main() {
    Electronics e1(1, "Smartphone", 15000,10, 2, "Apple");
    Clothing c1(2, "Jeans", 3000, 50, "M", "Blue", "Denim");
    FoodItem f1(3, "Chocolate", 200, 100, "2025-12-31", 250);

    c1.applyDiscount(15);
    cout << "Total price for 6 chocolates: $" << f1.calculateTotalPrice(6) << "\n";

    cout << "\nProduct Details:\n";
    cout << e1 << "\n";
    cout << c1 << "\n";
    cout << f1 << "\n";
    
    return 0;
}
