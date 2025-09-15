#ifndef RESTAURENT_H
#define RESTAURENT_H

#include<iostream>
#include<string>
#include<vector>
#include "MenuItem.h"
using namespace std;

class Restuarent {
   private:
   static int idCounter;
   string name;
   string address;
   int id;
    vector<MenuItem> menu;
    public:
   
    Restuarent(string name,const string& location  ){
        this->name = name;
        this->address = location;
        //static int idCounter = 0;
        this->id = ++idCounter;
    }
    ~Restuarent(){
        menu.clear();
    }
    string getName() const {
        return name;
    }
    string getAddress() const {
        return address;
    }
    int getId() const {
        return id;
    }
    void setName(const string& name) {
        this->name = name;
    }
    void setAddress(const string& address) {
        this->address = address;
    }
    void addMenuItem(const MenuItem& item) {
        menu.push_back(item);
    }
    

};

#endif