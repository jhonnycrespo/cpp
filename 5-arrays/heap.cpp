#include <iostream>

using namespace std;

/**
 * No compilar este codigo, solo sirve de referencia.
 *
 * https://stackoverflow.com/questions/4264304/how-to-return-an-array-from-a-function
 */

// no podemos hacer esto, devolver un puntero a un array creado de forma
// local, por que al terminar la funcion todo lo que se creo adentro es liberado.
int* createArray()
{
    int arr[5];

    for (int i = 0; i < 5; i++)
    {
        arr[i] = i * 10;
    }

    return arr;
}

// esta es la forma correcta, pero tiene el problema de que el usuario debe
// saber el tamanio del arreglo para crearlo. y luego debe liberarlo
int* createArray(size_t s)
{
    int* arr = new int[s];

    for (int i = 0; i < s; i++)
    {
        arr[i] = i * 10;
    }

    return arr;
}

int main()
{
    int* other = createArray(5);
    delete[] other;
}