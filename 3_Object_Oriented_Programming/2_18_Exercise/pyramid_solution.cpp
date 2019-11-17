#include <cassert>
#include <stdexcept>

// TODO: Define class Pyramid
class Pyramid
{
public:
    // constructor
    Pyramid(int length, int width, int height)
        : length_(length), width_(width), height_(height)
    {
        Validate();
    }

    // accessors
    int Length() const { return length_; }
    int Width() const { return width_; }
    int Height() const { return height_; }

    // mutators
    void Length(int length)
    {
        length_ = length;
        Validate();
    }
    void Width(int width)
    {
        width_ = width;
        Validate();
    }
    void Height(int height)
    {
        height_ = height;
        Validate();
    }

    // public Volume() function
    float Volume() const { return Length() * Width() * Height() / 3.0; }

    // private class members
private:
    int length_;
    int width_;
    int height_;
    void Validate()
    {
        if (length_ <= 0 || width_ <= 0 || height_ <= 0)
            throw std::invalid_argument("negative dimension");
    }
};

// Test
int main()
{
    Pyramid pyramid(4, 5, 6);
    assert(pyramid.Length() == 4);
    assert(pyramid.Width() == 5);
    assert(pyramid.Height() == 6);
    assert(pyramid.Volume() == 40);

    bool caught{false};
    try
    {
        Pyramid invalid(-1, 2, 3);
    }
    catch (...)
    {
        caught = true;
    }
    assert(caught);
}