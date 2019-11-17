#include <cassert>
#include <stdexcept>

// TODO: Define class Pyramid
// public class members
// constructor
// accessors
// mutators
// public Volume() function
// private class members

class Pyramid
{
private:
    float length, width, height, volume;
    void Validate()
    {
        if (length <= 0 || width <= 0 || height <= 0)
            throw std::invalid_argument("negative dimension");
    }

public:
    Pyramid(float l, float w, float h);

    float Length();
    float Width();
    float Height();
    float Volume();

    void Length(float l);
    void Width(float w);
    void Height(float h);
};

Pyramid::Pyramid(float l, float w, float h)
    : length(l), width(w), height(h)
{
    Pyramid::Validate();
}

void Pyramid::Length(float l)
{
    Pyramid::length = l;
    Pyramid::Validate();
}
void Pyramid::Width(float w)
{
    Pyramid::width = w;
    Pyramid::Validate();
}
void Pyramid::Height(float h)
{
    Pyramid::height = h;
    Pyramid::Validate();
}

float Pyramid::Length() { return length; }
float Pyramid::Width() { return width; }
float Pyramid::Height() { return height; }
float Pyramid::Volume()
{
    Pyramid::volume = Length() * Width() * Height() / 3.0;
    return Pyramid::volume;
}

// Test
int main()
{
    Pyramid pyramid(4.0, 5.0, 6.0);
    assert(pyramid.Length() == 4.0);
    assert(pyramid.Width() == 5.0);
    assert(pyramid.Height() == 6.0);
    assert(pyramid.Volume() == 40.0);

    bool caught{false};
    try
    {
        Pyramid invalid(-1.0, 2.0, 3.0);
    }
    catch (...)
    {
        caught = true;
    }
    assert(caught);
}