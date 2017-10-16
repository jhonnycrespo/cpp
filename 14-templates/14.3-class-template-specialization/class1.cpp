#include <iostream>

using namespace std;

/**
 * http://www.learncpp.com/cpp-tutorial/136-class-template-specialization/
 * http://www.learncpp.com/cpp-tutorial/38-bitwise-operators/
 *
 * Consider the case where you want to design a class that stores 8 objects. Here’s a simplified class to do so:
 *
 * While this class is completely functional, it turns out that the implementation of Storage8<bool> is much 
 * more inefficient than it needs to be. Because all variables must have an address, and the CPU can’t address 
 * anything smaller than a byte, all variables must be at least a byte in size. Consequently, a variable of type 
 * bool ends up using an entire byte even though technically it only needs a single bit to store its true or false 
 * value! Thus, a bool is 1 bit of useful information and 7 bits of wasted space. Our Storage8<bool> class, which 
 * contains 8 bools, is 1 byte worth of useful information and 7 bytes of wasted space.
 */

template <class T>
class Storage8
{
private:
    T m_array[8];

public:
    void set(int index, const T& value)
    {
        m_array[index] = value;
    }

    const T& get(int index)
    {
        return m_array[index];
    }
};

/**
 * As it turns out, using some basic bit logic, it’s possible to compress all 8 bools into a single byte, eliminating 
 * the wasted space altogether. However, in order to do this, we’ll need to revamp the class when used with type bool, 
 * replacing the array of 8 bools with a variable that is a single byte in size. While we could create an entirely 
 * new class to do so, this has one major downside: we have to give it a different name. Then the programmer has to 
 * remember that Storage8<T> is meant for non-bool types, whereas Storage8Bool (or whatever we name the new class) is 
 * meant for bools. That’s needless complexity we’d rather avoid. Fortunately, C++ provides us a better method: class template specialization.
 *
 * Class template specialization allows us to specialize a template class for a particular data type (or data types, if there 
 * are multiple template parameters). In this case, we’re going to use class template specialization to write a customized 
 * version of Storage8<bool> that will take precedence over the generic Storage8<T> class. This works analogously to how a 
 * specialized function takes precedence over a generic template function.
 *
 * Class template specializations are treated as completely independent classes, even though they are allocated in the 
 * same way as the templated class. This means that we can change anything and everything about our specialization class, 
 * including the way it’s implemented and even the functions it makes public, just as if it were an independent class. 
 * Here’s our specialized class:
 */

// The template keyword tells the compiler that what follows is templated, and the empty angle braces
// means that there aren't any template parameters.
// Next, we add <bool> to the class name to denote that we're specializing a bool version of the class Storage8.
template <>
class Storage8<bool>
{
private:
    unsigned char m_data;

public:
    Storage8(): m_data(0)
    {

    }

    // Note that this specialization class utilizes a single unsigned char (1 byte) instead of an array of 8 bools (8 bytes).
    void set(int index, bool value)
    {
        // figure out which bit we're setting/unsetting
        // This will put a 1 in the bit we're interested in turning on/off
        unsigned char mask = 1 << index;

        if (value)
            m_data |= mask; // use bitwise-or to turn that bit on
        else
            m_data &= ~mask; // bitwise-and the inverse mask to turn that bit off
    }

    bool get(int index)
    {
        // figure out which bit we're getting
        unsigned char mask = 1 << index;
        // bitwise-and to get the value of the bit we're interested in
        // then implicit cat to boolean
        return (m_data & mask) != 0;
    }
};

/**
 * Now, when we declare a class of type Storage8<T>, where T is not a bool, we’ll get a version stenciled from the 
 * generic templated Storage8<T> class. When we declare a class of type Storage8<bool>, we’ll get the specialized 
 * version we just created. Note that we have kept the publicly exposed interface of both classes the same -- while C++ 
 * gives us free reign to add, remove, or change functions of Storage8<bool> as we see fit, keeping a consistent 
 * interface means the programmer can use either class in exactly the same manner.
 */

int main()
{
    Storage8<int> intStorage;

    for (int count = 0; count < 8; ++count)
        intStorage.set(count, count);
     
    for (int count = 0; count < 8; ++count)
        cout << intStorage.get(count) << '\n';
     

    // Define a Storage8 for bool
    Storage8<bool> boolStorage;

    for (int count = 0; count < 8; ++count)
        boolStorage.set(count, count & 3);
     
    for (int count = 0; count < 8; ++count)
        cout << (boolStorage.get(count) ? "true" : "false") << '\n';
     
    return 0;
}