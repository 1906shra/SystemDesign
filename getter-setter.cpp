//Write a C++ program to create a class called Person that has private member variables for name, age and country. Implement member functions to set and get the values of these variables.

#include<iostream>
#include<string>
using namespace std;

class Person{
    private:
    string name;
    int age;
    string country;
    public:
    //default constructor
    Person() : name(""), age(0), country("") {}

    //constructor to initialize the member variables
    Person(string n,int a,string c) {
        name = n;
        age = a;
        country = c;
    }

    //setter function to set the name
    void setName(string n) {
        name = n;
    }
    //getter function to get the name
    string getName() const{
        return name;
    }
    void setAge(int a) {
        age = a;
    }
    //getter function to get the name
    int getAge() const{
        return age;
    }
    void setCountry(string c) {
        country = c;
    }
    //getter function to get the name
    string getCountry() const{
        return country;
    }

};

int main(){
    Person p;

  // Set the p's details using setter functions
  p.setName("Saveli Sujatha"); // Set the p's name
  p.setAge(25); // Set the p's age
  p.setCountry("USA"); // Set the p's country

  // Get and display the p's details using getter functions
  std::cout << "Name: " << p.getName() << std::endl; // Output the p's name
  std::cout << "Age: " << p.getAge() << std::endl; // Output the p's age
  std::cout << "Country: " << p.getCountry() << std::endl; // Output the p's country

  return 0; // Return 0 to indicate successful completion
}
