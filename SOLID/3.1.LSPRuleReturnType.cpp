//Return Type Rule says that functions should return the most derived type possible
#include <iostream>
using namespace std;
class Animal{

};
class Dog : public Animal{

};
class Parent{
    public:
    virtual Animal* getAnimal(){
       cout<<"Parent's getAnimal called"<<endl;
       return new Animal();
    }
};
class Child : public Parent{
    public:
    Dog* getAnimal() override{ // Covariant return type
        cout<<"Child's getAnimal called"<<endl;
        return new Dog();
    }
};

class Client{
    private:
    Parent* p;
    public:
    Client(Parent* parent){
        p = parent;
    }
    void takenAnimal(){
         p->getAnimal();
        
    }
};

int main(){
    Parent* parent = new Parent();
    Client* client1 = new Client(parent);
    client1->takenAnimal();

    Child* child = new Child();
    Client* client2 = new Client(child);
    client2->takenAnimal();

    return 0;
}