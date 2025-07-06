#include<iostream>
#include<string>
using namespace std;

class Car{
    public:
    virtual void startEngine()  = 0;//virtual tells us that this function is a pure
    // virtual function, meaning it must be overridden in derived classes.

    virtual void shiftGer(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void brake()  = 0;
    virtual void stopEngine() = 0;
    virtual ~Car() {} // Virtual destructor for proper cleanup
};


//Inheriting from the Car class
class BMW : public Car {
    public:
     string brand;
     string model;
     bool isEngineOn;
     int currentSpeed;
     int currentGear;
     BMW(string b, string m) {
          this->brand = b;
            this->model = m;
            isEngineOn = false;
            currentSpeed = 0;
            currentGear = 0;
     }
     void startEngine() {
        isEngineOn = true;
        cout << "Engine started for " << brand << " " << model << endl;
     }
     void shiftGer(int gear){
        if(!isEngineOn) {
            cout << "Cannot shift gear. Engine is off." << endl;
            return;
        }
        currentGear = gear;
        cout << "Gear shifted to " << currentGear << " for " << brand << " " << model << endl;
     }

 void accelerate() {
        if(!isEngineOn) {
            cout << "Cannot accelerate. Engine is off." << endl;
            return;

        }
        currentSpeed+=10;
        cout << "Accelerating " << brand << " " << model << " to " << currentSpeed << " km/h" << endl;
    }
    void brake() {
        if(!isEngineOn) {
            cout << "Cannot brake. Engine is off." << endl;
            return;
        }
        if(currentSpeed > 0) {
            currentSpeed -= 10;
            cout << "Braking " << brand << " " << model << ". Current speed: " << currentSpeed << " km/h" << endl;
        } else {
            cout << brand << " " << model << " is already stopped." << endl;
        }
    }
    void stopEngine() {
        if(isEngineOn) {
            isEngineOn = false;
            currentSpeed = 0;
            currentGear = 0;
            cout << "Engine stopped for " << brand << " " << model << endl;
        } else {
            cout << "Engine is already off." << endl;
        }
    }
};