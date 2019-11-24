#include <iostream>
#include <cmath>
#include <assert.h>

// Define pi
#define PI 3.14159

// Define Line Class
struct LineSegment
{
    // Define protected attribute length
public:
    double length;
};

// Define Circle subclass
class Circle
{
    // Define public setRadius() and getArea()
public:
    Circle(LineSegment &radius);
    double Area();

private:
    LineSegment &radius;
};
Circle::Circle(LineSegment &radius) : radius(radius) {}

double Circle::Area() { return (PI * pow(Circle::radius.length, 2)); }

// Test in main()
int main()
{
    LineSegment radius{3.0};
    Circle circle(radius);
    assert(int(circle.Area()) == 28.0);
}