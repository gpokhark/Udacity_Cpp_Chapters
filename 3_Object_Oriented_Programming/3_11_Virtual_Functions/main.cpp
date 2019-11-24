// Example solution for Shape inheritance
#include <assert.h>
#include <cmath>

// TODO: Define pi
#define PI 3.141529

// TODO: Define the abstract class Shape
// TODO: Define public virtual functions Area() and Perimeter()
// TODO: Append the declarations with = 0 to specify pure virtual functions

class Shape
{
public:
    virtual double Area() const = 0;
    virtual double Perimeter() const = 0;
};

// TODO: Define Rectangle to inherit publicly from Shape
// TODO: Declare public constructor
// TODO: Override virtual base class functions Area() and Perimeter()
// TODO: Declare private attributes width and height
class Rectangle : public Shape
{
public:
    Rectangle(double w, double h)
    {
        Rectangle::width = w;
        Rectangle::height = h;
    }

    double Area() const override { return width * height; }
    double Perimeter() const override { return 2 * (width + height); }

private:
    double width, height;
};

// TODO: Define Circle to inherit from Shape
// TODO: Declare public constructor
// TODO: Override virtual base class functions Area() and Perimeter()
// TODO: Declare private member variable radius

class Circle : public Shape
{
public:
    Circle(double rad) : radius(rad) {}

    double Area() const override { return PI * radius * radius; }
    double Perimeter() const override { return 2 * PI * radius; }

private:
    double radius;
};

// Test in main()
int main()
{
    double epsilon = 0.1; // useful for floating point equality

    // Test circle
    Circle circle(12.31);
    assert(abs(circle.Perimeter() - 77.35) < epsilon);
    assert(abs(circle.Area() - 476.06) < epsilon);

    // Test rectangle
    Rectangle rectangle(10, 6);
    assert(rectangle.Perimeter() == 32);
    assert(rectangle.Area() == 60);
}