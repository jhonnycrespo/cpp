#include "Person.h"
#include <cstdio>
#include <iostream>

using namespace std;

Person::Person()
{
    age = -1;
    height = -1;
}

Person::Person(int age, double height) : age {age}, height {height}
{}

// copy constructor
// Este es el constructor que genera el compilador
Person::Person(const Person& p) : age {p.age}, height {p.height}
{
    puts("copy constructor has been called");
}

// equal operator
// Este es el metodo que genera el compilador
Person& Person::operator=(const Person& p)
{
    puts("operator= method has ben called");
    age = p.age;
    height = p.height;

    return *this;
} 

int Person::get_age()
{
    return age;
}

void Person::set_age(int age)
{
    this->age = age;
}

double Person::get_height()
{
    cout << "height = " << height << endl;
    cout << "this->height = " << this->height << endl;
    cout << "(*this).height = " << (*this).height << endl;

    return height;

}


Person& Person::get_copy_as_reference()
{
    return *this;
}

// Return by pointer needs const and non-const versions

Person* Person::return_pointer_to_current_object()
{
    return this;
}

const Person* Person::return_pointer_to_current_object() const
{
    return this;
}

// Return by reference needs const and non-const versions

Person& Person::return_reference_to_current_object()
{
    return *this;
}

const Person& Person::return_reference_to_current_object() const
{
    return *this;
}

// Return by value only needs one version
Person Person::return_copy_of_current_object() const
{
    return *this;
}

Person Person::operator+(const Person& p) const
{
    Person person;
    person.age = this->age + p.age;

    return person;
}

Person::~Person()
{}

int main()
{
    // calls constructor that receives parameters
    Person person {24, 1.70};
    cout << person.get_age() << endl;
    
    
    Person* person1 = person.return_pointer_to_current_object();
    person1->set_age(26);
    cout << person1->get_age() << endl;

    if (&person == person1)
    {
        cout << "person y person1 apuntan a la misma direccion de memoria" << endl;
    }

    Person person2 = person.return_reference_to_current_object();
    cout << person2.get_age() << endl;

    if (&person == &person2)
    {
        cout << "person y person2 apuntan a la mima direccion de memoria" << endl;        
    }
    else
    {
        cout << "person y person2 no apuntan a la mima direccion de memoria" << endl;
    }

    Person person3 = person.return_copy_of_current_object();
    cout << person3.get_age() << endl;

    if (&person == &person3)
    {
        cout << "person y person3 apuntan a la mima direccion de memoria" << endl;        
    }
    else
    {
        cout << "person y person3 no apuntan a la mima direccion de memoria" << endl;
    }

    Person person4 = person + person; 
    cout << person4.get_age() << endl;

    Person& person5 = person;
    person5.set_age(30);

    if (&person == &person5)
    {
        cout << "person y person5 apuntan a la mima direccion de memoria" << endl;        
    }
    else
    {
        cout << "person y person5 no apuntan a la mima direccion de memoria" << endl;
    }

    cout << person.get_age() << endl;


    // Calls default constructor
    Person person6;

    // This object will be stored in the heap. This is useful if you are using
    // this object long time of period.
    Person* person8 = new Person();

    // calls copy constructor
    Person person9 {person};
    cout << person9.get_age() << endl;

    person9 = person6;
    cout << person9.get_age() << endl;
    cout << person9.get_height() << endl;


    Person& person10 = person9.return_reference_to_current_object();
    person10.set_age(50);
    cout << person9.get_age() << endl;

    if (&person10 == &person9)
    {
        cout << "person9 y person10 apuntan a la mima direccion de memoria" << endl;        
    }
    else
    {
        cout << "person9 y person10 no apuntan a la mima direccion de memoria" << endl;
    }

}