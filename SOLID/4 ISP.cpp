// Interface Segregation Principle (ISP)
// Clients should not be forced to depend on interfaces they do not use.
// This principle encourages the creation of smaller, more specific interfaces rather than a large, general-purpose interface.
//for example when we have a shape class with area and volume methods, not all shapes have volume (like 2D shapes), so we should segregate the interface.
#include <iostream>
#include <stdexcept>
using namespace std;
class TwoDimensionalShape {
    public:
    virtual double area() const = 0;
    virtual ~TwoDimensionalShape() = default;
};
class ThreeDimensionalShape {
    public:
    virtual double volume() const = 0;
    virtual ~ThreeDimensionalShape() = default;
};
class Circle : public TwoDimensionalShape {
    private:
    double radius;
    public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return 3.14159 * radius * radius;
    }
};
class Square : public TwoDimensionalShape {
    private:
    double side;
    public:
    Square(double s) : side(s) {}
    double area() const override {
        return side * side;
    }
};
class Cube : public ThreeDimensionalShape {
    private:
    double side;
    public:
    Cube(double s) : side(s) {}
    double volume() const override {
        return side * side * side;
    }
};
class Sphere : public ThreeDimensionalShape {
    private:
    double radius;
    public:
    Sphere(double r) : radius(r) {}
    double volume() const override {
        return (4.0/3.0) * 3.14159 * radius * radius * radius;
    }
};
int main() {
    TwoDimensionalShape* circle = new Circle(5.0);
    TwoDimensionalShape* square = new Square(4.0);
    ThreeDimensionalShape* cube = new Cube(3.0);
    ThreeDimensionalShape* sphere = new Sphere(2.0);

    cout << "Circle Area: " << circle->area() << endl;
    cout << "Square Area: " << square->area() << endl;
    cout << "Cube Volume: " << cube->volume() << endl;
    cout << "Sphere Volume: " << sphere->volume() << endl;

    delete circle;
    delete square;
    delete cube;
    delete sphere;

    return 0;
}