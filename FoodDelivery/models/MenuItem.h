#ifndef MENUITEM_CPP
#define MENUITEM_CPP

#include<iostream>
#include<string>
using namespace std;
class MenuItem{
    private:
    string name;
    double price;
    string code;
    public:
    MenuItem(const string& name, double price, const string& code){
        this->name = name;
        this->price = price;
        this->code = code;
    }
    string getName() const {
        return name;
    }
    double getPrice() const {
        return price;
    }
    string getCode() const {
        return code;
    }
    void setName(const string& name) {
        this->name = name;
    }
    void setPrice(double price) {
        this->price = price;
    }
    void setCode(const string& code) {
        this->code = code;
    }
};

#endif
