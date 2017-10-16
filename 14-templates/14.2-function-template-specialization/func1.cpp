#include <iostream>

using namespace std;

/**
 * http://www.learncpp.com/cpp-tutorial/13-5-function-template-specialization/
 * 
 * When instantiating a function template for a given type, the compiler stencils out a copy of the templated 
 * function and replaces the template type parameters with the actual types used in the variable 
 * declaration. This means a particular function will have the same implementation details for each instanced 
 * type (just using different types). While most of the time, this is exactly what you want, occasionally 
 * there are cases where it is useful to implement a templated function slightly different for a specific data type.
 *
 * Template specialization is one way to accomplish this.
 */

template <class T>
class Storage
{
private:
    T m_value;

public:
    Storage(T value)
    {
        m_value = value;
    }

    void print()
    {
        cout << m_value << '\n';
    }

    ~Storage()
    {

    }
};

/**
 * Now, let’s say we want double values (and only double values) to output in scientific notation. To do so, we can use a function 
 * template specialization (sometimes called a full or explicit function template specialization) to create a specialized version 
 * of the print() function for type double.
 *
 * When the compiler goes to instantiate Storage<double>::print(), it will see we’ve already explicitly defined that function, 
 * and it will use the one we’ve defined instead of stenciling out a version from the generic templated class.
 *
 * The template <> tells the compiler that this is a template function, but that there are no template 
 * parameters (since in this case, we’re explicitly specifying all of the types). Some compilers may 
 * allow you to omit this, but it’s proper to include it.
 */

template <>
void Storage<double>::print()
{
     cout << scientific << m_value << '\n';
}

/**
 *  Instead of doing a pointer copy, we’d really like our constructor to make a copy of the input string. So let’s write 
 *  a specialized constructor for datatype char* that does exactly that:
 *
 * Now when we allocate a variable of type Storage<char*>, this constructor will get used instead of the default one. 
 * As a result, m_value will receive its own copy of string. Consequently, when we delete string, m_value will be unaffected.
 */

template <>
Storage<char*>::Storage(char* value)
{
    // figure out how long the string in value is
    int length = 0;

    while (value[length] != '\0')
        ++length;

    // +1 to account for the null terminator
    ++length;

    // allocate memory to hold the value string
    m_value = new char[length];

    // copy the actual value string into the m_value memory we just allocated
    for (int count = 0; count < length; ++count)
        m_value[count] = value[count];
}

/**
 * However, this class now has a memory leak for type char*, because m_value will not be deleted when a Storage 
 * variable goes out of scope. As you might have guessed, this can also be solved by specializing the Storage<char*> destructor:
 */

template <>
Storage<char*>::~Storage()
{
    delete[] m_value;
}

int main()
{
    Storage<int> nValue(5);
    Storage<double> dValue(6.7);

    nValue.print();
    dValue.print();

    /**
     * Consider what happens if we try to use our templated Storage class with datatype char*
     */

    // dynamically allocate a temporary string
    char* string = new char[48];

    cout << "Enter your name: ";
    cin >> string;

    // store the name
    Storage<char*> value(string);

    // delete the temporary string
    delete[] string;

    // print the value
    value.print();
}