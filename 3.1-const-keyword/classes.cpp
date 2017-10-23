#include <iostream>

using namespace std;

class Point
{
private:
    int x;
    int y;
    int* z;
    mutable int w;

public:
    // const aqui significa que el metodo no modifica nada de la clase (variables miembro).
    int GetX() const
    {
        // error
        // x = 7;
        // una variable mutable si se puede modficiar desde un metodo const.
        w = 48;
        return x;
    }

    const int GetY()
    {
        return y; 
    }

    // 1er const: retornamos un puntero que no puede ser modificado.
    // 2do const: el contenido de la direccion de memoria que contiene el puntero no puede ser modificado.
    // 3er const: este metodo no modifica la clase.
    const int* const GetZ() const
    {
        return z;   
    }
};

void PrintX(const Point& p)
{
    cout << p.GetX() << endl;
}

// esto no funciona. Por que??
// Porque el metodo GetY() no nos garantiza q no modificara la clase.
// y en al decir "const Point& p" nosotros decimos que no modificaremos la referencia.
void PrintY(const Point& p)
{
    cout << p.GetY() << endl;
}

int main()
{

}