int main()
{
    const int MAX_AGE = 90;
    int aux = 30;

    // creamos un entero en el heap
    // no podemos modificar el contenido de la memoria a la que apunta el puntero.
    const int* a = new int;
    // esto es lo mismo que arriba.
    // int const* a = new int;
    // *a = 34;

    // pero si podemos cambiar hacia donde apunta el puntero.
    a = &aux;


    // no podemos cambiar hacia donde apunta el puntero
    int* const c = new int;
    // c = &aux;
    // pero si podemos cambiar el contenido de la memoria a la que apunta el puntero
    *c = 64;


    // no podemos cambiar hacia donde apunta el puntero, ni el contenido de la memoria
    // a la que apunta.
    const int* const d = new int;



    const int b = 5;

    // no podemos cambiar el valor de b
    // b = 10; 
}