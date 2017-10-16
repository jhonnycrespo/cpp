#include <iostream>

using namespace std;

// size is the expression parameter
template <class T, int size>
class StaticArray_Base
{
protected:
    T m_array[size];

public:
    T* getArray()
    {
        return m_array;
    }

    T& operator[](int index)
    {
        return m_array[index];
    }

    // print is now a member function of the class. So what happens when we want to partially
    // specialize print()?
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << m_array[i] << ' ';
        }
        cout << '\n';
    }
};

/**
 * You might try this:
 *
 * Unfortunately, this doesn’t work, because we’re trying to partially specialize a function, which is disallowed.
 *
 * So how do we get around this? One obvious way is to partially specialize the entire class. While it works, it isn't
 * a great solution, because we had to duplicate a lot of code.
 *
 * If only there were some way to reuse the code in StaticArray<T, size> in StaticArray<double, size>. Sounds like a job for inheritance!
 */

/*template <int size>
void StaticArray<double, size>::printArray()
{
    for (int i = 0; i < size; i++)
        cout << std::scientific << m_array[i] << " ";
    cout << "\n";
}*/


template <class T, int size>
class StaticArray: public StaticArray_Base<T, size>
{
public:
    StaticArray()
    {

    }
};

template <int size>
class StaticArray<double, size>: public StaticArray_Base<double, size>
{
public:
    void print()
    {
        for (int i = 0; i < size; i++)
            cout << scientific << StaticArray_Base<double, size>::m_array[i] << " ";
            // note: gcc requires the StaticArray_Base<double, size>:: prefix in the above line.  Still not sure why.
        cout << "\n";
    }
};

int main()
{
    // declare an integer array with room for 12 integers
    StaticArray<int, 6> intArray;
 
    // Fill it up in order, then print it backwards
    for (int count = 0; count < 6; ++count)
        intArray[count] = count;
    intArray.print();
    // declare a double buffer with room for 4 doubles
    StaticArray<double, 4> doubleArray;
 
    for (int count = 0; count < 4; ++count)
        doubleArray[count] = (4. + 0.1*count);
    doubleArray.print();
 
    return 0;
}
