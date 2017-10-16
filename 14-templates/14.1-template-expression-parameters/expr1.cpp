#include <iostream>

using namespace std;

/**
 * http://www.learncpp.com/cpp-tutorial/134-template-expression-parameters/
 * 
 * A template expression parameter is a special type of parameter that does not
 * substitute for a type, but is instead replaced by a value. An expression parameter
 * can be any of the following:
 * 
 * A value that has an integral type or enumeration
 * A pointer or reference to a class object
 * A pointer or reference to a function
 * A pointer or reference to a class member function
 */

// size is the expression parameter
template <class T, int size>
class StaticArray
{
private:
    // the expression parameter controls the size of the array
    T m_array[size];

public:
    T* getArray();

    T& operator[](int index)
    {
        return m_array[index];
    }
};

template <class T, int size>
T* StaticArray<T, size>::getArray()
{
    return m_array;
}

int main()
{
    // declare an integer array with room for 12 integers
    StaticArray<int, 12> intArray;

    for (int count = 0; count < 12; ++count)
        intArray[count] = count;

    for (int count = 11; count >= 0; --count)
        cout << intArray[count] << " ";
    cout << '\n';


    StaticArray<double, 4> doubleArray;

    for (int count = 0; count < 4; ++count)
        doubleArray[count] = 4.4 + 0.1 * count;

    for (int count = 0; count < 4; ++count)
        cout << doubleArray[count] << ' ';

    return 0;
}