//Write a C++ program to implement a class called Circle that has private member variables for radius. Include member functions to calculate the circle's area and circumference.
#include<iostream>
using namespace std;
class Circle{
    private:
     double radius;
     public:
     Circle(double r){
        radius = r;
     }

     //setter function (to set the radius)
     void setRadius(double r){
        radius  =r;

     }
     //getter function (to get the radius)

     double getRadius() const{
        return radius;
     }

     //function to calualate area 
     double area() const{
         return 3.14159 * radius * radius;
     }
     //function to calculate circumference
     double circumference() const{
         return 2 * 3.14159 * radius;
     }

};

int main(){
   double r;
   cout<<" Enter the radius of the circle: ";
    cin>>r;
    Circle c(r);
    cout<<" Area of the circle: " << c.area() << endl;
    cout<<" Circumference of the circle: " << c.circumference() << endl;
    return 0;
}