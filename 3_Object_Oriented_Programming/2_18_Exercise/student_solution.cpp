#include <cassert>
#include <stdexcept>
#include <string>

using std::string;

// TODO: Define "Student" class
class Student
{
public:
    // constructor
    Student(string name, int grade, float gpa) : name_(name), grade_(grade), gpa_(gpa) { Validate(); }

    /* THIS GIVES ERROR *****************************************************************
    // Student(string name, int grade, float gpa)
    // {   
    //     Name(name);
    //     Grade(grade);
    //     GPA(gpa);
    //     Validate();
    // }
    *************************************************************************************
    */
    // accessors
    string Name() const { return name_; }
    int Grade() const { return grade_; }
    float GPA() const { return gpa_; }

    // mutators
    void Name(string name)
    {
        name_ = name;
        Validate();
    }
    void Grade(int grade)
    {
        grade_ = grade;
        Validate();
    }
    void GPA(float gpa)
    {
        gpa_ = gpa;
        Validate();
    }

private:
    string name_;
    int grade_;
    float gpa_;
    void Validate()
    {
        if (Grade() < 0 || Grade() > 12 || GPA() < 0.0 || GPA() > 4.0)
            throw std::invalid_argument("argument out of bounds");
    }
};

// TODO: Test
int main()
{
    Student david("David Silver", 10, 4.0);
    assert(david.Name() == "David Silver");
    assert(david.Grade() == 10);
    assert(david.GPA() == 4.0);

    bool caught{false};
    try
    {
        david.Grade(20);
    }
    catch (...)
    {
        caught = true;
    }
    assert(caught);
}