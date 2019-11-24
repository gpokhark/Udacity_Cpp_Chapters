#include <assert.h>
#include <cmath>

// TODO: Define PI
#define PI 3.1415926535

// TODO: Declare abstract class VehicleModel
// TODO: Declare virtual function Move()
class VehicleModel
{
public:
    virtual void Move(double v, double phi) = 0;
};

// TODO: Derive class ParticleModel from VehicleModel
// TODO: Override the Move() function
// TODO: Define x, y, and theta

class ParticleModel : public VehicleModel
{
private:
public:
    double theta{0}, x{0}, y{0};
    void Move(double v, double phi) override
    {
        theta += phi;
        x += v * cos(theta);
        y += v * sin(theta);
    }
};

// TODO: Derive class BicycleModel from ParticleModel
// TODO: Override the Move() function
// TODO: Define L
class BicycleModel : public VehicleModel
{
private:
public:
    double theta{0}, x{0}, y{0}, L{1};
    void Move(double v, double phi) override
    {
        theta += v / L * tan(phi);
        x += v / L * cos(theta);
        y += v / L * sin(theta);
    }
};
// TODO: Pass the tests
int main()
{
    // Test function overriding
    ParticleModel particle;
    BicycleModel bicycle;
    particle.Move(10, PI / 9);
    bicycle.Move(10, PI / 9);
    assert(particle.x != bicycle.x);
    assert(particle.y != bicycle.y);
    assert(particle.theta != bicycle.theta);
}