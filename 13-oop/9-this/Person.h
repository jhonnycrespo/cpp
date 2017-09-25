#ifndef PERSON_H
#define PERSON_H

class Person
{
private:
    int age;
    double height;

public:
    Person();
    Person(int age, double height);
    // copy constructor
    Person(const Person& p);
    // equal operator
    Person& operator=(const Person& p);
    int get_age();
    void set_age(int age);
    double get_height();
    Person& get_copy_as_reference();
    Person* return_pointer_to_current_object();
    const Person* return_pointer_to_current_object() const;
    Person& return_reference_to_current_object();
    const Person& return_reference_to_current_object() const;
    Person return_copy_of_current_object() const;
    Person operator+(const Person& p) const;
    ~Person();


    // Person& operator=(const Person& src);
};


#endif