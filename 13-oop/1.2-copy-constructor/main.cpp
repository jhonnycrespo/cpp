#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Point
{
    double x;
    double y;
};


class String
{
private:
    char* m_buffer;
    unsigned int m_size;

public:
    String(const char* string)
    {
        m_size = strlen(string);
        m_buffer = new char[m_size + 1];
        memcpy(m_buffer, string, m_size);
        m_buffer[m_size] = 0;
    }

    // copy constructor
    // c++ by default, creates a copy constructor
    String(const String& other): m_size(other.m_size)
    {
        cout << "copying string" << endl;
        // allocate a new buffer
        m_buffer = new char[m_size + 1];
        memcpy(m_buffer, other.m_buffer, m_size + 1);
        // aqui no es necesario agregar el caracter 0, porq del que se copia ya lo contiene
    }

    ~String()
    {
        delete[] m_buffer;
    }

    char& operator[](unsigned int index)
    {
        return m_buffer[index];
    }

    friend ostream& operator<<(ostream& stream, const String& );
};

ostream& operator<<(ostream& stream, const String& string)
{
    stream << string.m_buffer;
    return stream;
}

// esto hace una copia
// void PrintString(String str)
// es mejor pasar por referencia
void PrintString(const String& str)
{
    cout << str << endl;
}

int main()
{
    int a = 2;
    // copying
    int b = a;

    Point c = {2, 3};
    // copying c to d.
    Point d = c;
    c.x = 9;

    Point* pa = new Point();
    // copying the pointer
    Point* pb = pa;
    pb->y = 8;



    String s1 = "Stephen";
    // copy string. Takes the members values and copies them
    // into a new memory address.
    String s2 = s1;
    s2[2] = 'a';

    PrintString(s1);
    PrintString(s2);
}