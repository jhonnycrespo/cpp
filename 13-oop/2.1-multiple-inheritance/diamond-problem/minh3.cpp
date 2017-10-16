#include <iostream>

using namespace std;

/**
 *  The constructor of ‘Person’ is called once. One important thing to note in the below output is, 
 *  the default constructor of ‘Person’ is called. When we use ‘virtual’ keyword, the default 
 *  constructor of grandparent class is called by default even if the parent classes explicitly 
 *  call parameterized constructor.
 */

class Person
{
public:
    Person()
    {
        cout << "Person::Person() called" << endl;
    }

    Person(int x)
    {
        cout << "Person::Person(int) called" << endl;
    }
};

class Faculty: virtual public Person
{
public:
    Faculty(int x): Person(x)
    {
       cout<<"Faculty::Faculty(int) called"<< endl;
    }
};

class Student: virtual public Person
{
public:
    Student(int x): Person(x)
    {
        cout<<"Student::Student(int) called"<< endl;
    }
};

class TA: public Faculty, public Student
{
public:
    TA(int x): Student(x), Faculty(x)
    {
        cout<<"TA::TA(int) called"<< endl;
    }
};

int main()
{
    TA ta1(30);
}
