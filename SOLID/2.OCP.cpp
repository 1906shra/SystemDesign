//OCP stands for Open/Closed Principle
// A class should be open for extension but closed for modification.
//now taking an expmple of previous SRP example and making it OCP compliant
//to make this possible we will use polymorphism , so that we can extend the functionality without modifying the existing code.
//also we will use abstract class to define the interface for the new functionality.
//also inheritance will be used to implement the new functionality.

#include<iostream>
#include<vector>
using namespace std;
// Single Responsibility Principle (SRP) Example
// A class should have only one reason to change, meaning it should have only one job or responsibility.

class Product{
    public:
    string name;
    double price;
    Product(string n, double p){
         name = n;
         price = p;
    }
};

class ShoppingCart{
    vector<Product> products;
    public:
    void addProduct(Product p){
         products.push_back(p);
    }
    const vector<Product>& getProducts() const {
         return products;
    }
    double calculateTotal() {
            double total = 0;
            for(auto p:products){
                 total += p.price;
            }
            return total;
    }
};

class ShoppingCartPrinter{
    private:
    ShoppingCart * cart;
    public:
    ShoppingCartPrinter(ShoppingCart * c){
        cart = c;
    }
    void printInvoice() {
        cout << "Invoice:" << endl;
        for(auto p:cart->getProducts()){
            cout << p.name << ": Rs." << p.price << endl;
        }
        cout << "Total: Rs." << cart->calculateTotal() << endl;
        
    }
};
// //class ShoppingCartStorage{
//     private:
//     ShoppingCart * cart;
//     public:
//     ShoppingCartStorage(ShoppingCart * c){
//         cart = c;
//     }
//     void saveToSqlDatabase() {
//         // Simulate saving to a database
//         cout << "Saving cart to SQL database..." << endl;
//     }
//     void saveToNoSqlDatabase() {
//         // Simulate saving to a NoSQL database
//         cout << "Saving cart to NoSQL database..." << endl;
//     }
//     void saveToCloudStorage() {
//         // Simulate saving to cloud storage
//         cout << "Saving cart to cloud storage..." << endl;
//     }

// };
class Persistance {
    public:
    virtual void save(const ShoppingCart& cart) = 0; // pure virtual function
    virtual ~Persistance() = default; // virtual destructor
};

class SQLPersistance : public Persistance{

    public:
    void save(const ShoppingCart& cart) override {
        cout << "Saving cart to SQL database..." << endl;
    }
};
class NoSQLPersistance : public Persistance{
    public:
    void save(const ShoppingCart& cart) override {
        cout << "Saving cart to NoSQL database..." << endl;
    }
};

class CloudPersistance : public Persistance{
    public:
    void save(const ShoppingCart& cart) override {
        cout << "Saving cart to cloud storage..." << endl;
    }
};





int main(){
    ShoppingCart cart;
    cart.addProduct(Product("Laptop", 50000));
    cart.addProduct(Product("Mouse", 1500));
    
    ShoppingCartPrinter printer(&cart);
    printer.printInvoice();
    
    SQLPersistance sqlStorage;
    sqlStorage.save(cart);
    NoSQLPersistance nosqlStorage;
    
    nosqlStorage.save(cart);
    return 0;
}