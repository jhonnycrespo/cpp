#include <iostream>

using namespace std;

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

    ~Storage()
    {

    }

    void print()
    {
        cout << m_value << '\n';
    }
};

// Partial specialization of Storage class for pointers
template <typename T>
class Storage<T*>
{
private:
    T* m_value;

public:
    Storage(T* value)
    {
        m_value = new T(*value);
    }

    ~Storage()
    {
        delete m_value;
    }

    void print()
    {
        cout << *m_value << '\n';
    }
};

// Full specialization of constructor for type char*
template <>
Storage<char*>::Storage(char* value)
{
    int length = 0;

    while (value[length] != '\0')
        ++length;

    ++length; // +1 to account for null terminator

    // Allocate memory to hold the value string
    m_value = new char[length];
 
    // Copy the actual value string into the m_value memory we just allocated
    for (int count = 0; count < length; ++count)
        m_value[count] = value[count];
}

int main()
{
    // Declare a non-pointer Storage.
    Storage<int> myint(5);
    myint.print();

    // Declare a pointer Storage.
    int x = 7;
    Storage<int*> myintptr(&x);
    // if myintptr did a pointer assignment on x, then
    // changing x will change myintptr too.
    x = 9;
    myintptr.print();

    return 0;
}