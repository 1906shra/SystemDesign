//exception rule
//A subclass should not throw exceptions that are not thrown by the base class
//This ensures that the subclass can be used in place of the base class without unexpected behavior due to unhandled exceptions.
#include <iostream>
#include <stdexcept>
using namespace std;

class Parent {
    public:
    virtual void getValue() noexcept(false){
        throw logic_error("Parent exception");
    }
};
class Child : public Parent {
    public:
    void getValue() noexcept(false) override{ // Allowed to throw the same exception
        throw out_of_range("Child exception");
    }
};

class Client {
    private:
    Parent* p;
    public:
    Client(Parent* parent) : p(parent) {}
    void takeValue() {
        try {
            p->getValue();
        } catch (const exception& e) {
            cout << "Caught exception: " << e.what() << endl;
        }
    }
};
int main() {
    Parent* parent = new Parent();
    Client* client1 = new Client(parent);
    client1->takeValue();

    Child* child = new Child();
    Client* client2 = new Client(child);
    client2->takeValue();

    delete parent;
    delete client1;
    delete child;
    delete client2;

    return 0;
}