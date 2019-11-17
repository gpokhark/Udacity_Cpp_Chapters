#include <cassert>
#include <cmath>
#include <stdexcept>

// TODO: Define class Sphere
class Sphere
{
public:
    // Constructor
    Sphere(int radius) : radius_(radius), volume_(pi_ * 4 / 3 * pow(radius_, 3))
    {
        if (radius <= 0)
            throw std::invalid_argument("radius must be positive");
    }

    // Accessors
    int Radius() const { return radius_; }
    int Volume() const { return volume_; }

private:
    // Private members
    float const pi_{3.14159};
    int const radius_;
    float const volume_;
};

// Test
int main(void)
{
    Sphere sphere(5);
    assert(sphere.Radius() == 5);
    assert(abs(sphere.Volume() - 523.6) < 1);
}