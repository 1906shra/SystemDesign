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
class ShoppingCartStorage{
    private:
    ShoppingCart * cart;
    public:
    ShoppingCartStorage(ShoppingCart * c){
        cart = c;
    }
    void saveToDatabase() {
        // Simulate saving to a database
        cout << "Saving cart to database..." << endl;
    }

};

int main(){
    ShoppingCart cart;
    cart.addProduct(Product("Laptop", 50000));
    cart.addProduct(Product("Mouse", 1500));
    
    ShoppingCartPrinter printer(&cart);
    printer.printInvoice();
    
    ShoppingCartStorage storage(&cart);
    storage.saveToDatabase();
    
    return 0;
}