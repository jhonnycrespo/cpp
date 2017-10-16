#include <iostream>
#include <cstring>

using namespace std;

/**
 * http://www.learncpp.com/cpp-tutorial/137-partial-template-specialization/
 */

template <class T, int size>
class StaticArray
{
private:
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
};

/**
 * Now, let’s say we wanted to write a function to print out the whole array. Although we could implement 
 * this as a member function, we’re going to do it as a non-member function instead because it will make 
 * the successive examples easier to follow.
 */

template <typename T, int size>
void print(StaticArray<T, size>& array)
{
    for (int count = 0; count < size; ++count)
        cout << array[count] << ' ';
}

// Override print() for fully specialized StaticArray<char, 14>
template <>
void print(StaticArray<char, 14>& array)
{
    for (int count = 0; count < 14; ++count)
        cout << array[count];
}

// size is still a templated expression parameter
template <int size>
void print(StaticArray<char, size>& array)
{
    for (int count = 0; count < size; ++count)
        cout << array[count];
}

int main()
{
    // declare an int array
    StaticArray<int, 4> int4;
    int4[0] = 0;
    int4[1] = 1;
    int4[2] = 2;
    int4[3] = 3;
    // Print the array
    print(int4);



    StaticArray<char, 14> char14;
    strcpy(char14.getArray(), "Hello, world!");
    // Print the array
    print(char14);


    // Now declare an char array of size 12
    StaticArray<char, 12> char12;
    strcpy(char12.getArray(), "Hello, mom!");
    // Print the array
    print(char12);
 
    return 0;
}