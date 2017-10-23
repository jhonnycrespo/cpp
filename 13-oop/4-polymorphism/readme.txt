Virtual Constructors?
=====================

No hay constructores virtuales.


When to use virtual destructors?
================================

https://stackoverflow.com/questions/461203/when-to-use-virtual-destructors


Virtual destructors are useful when you can delete an instance of a derived
class through a pointer to the base class.

Always make base classes' destructors virtual when they're meant to be manipulated polymorphically.

No es necesario marcar el destructor de una clase hija como virtual.
De hecho, no es necesario declarar el destructor a no ser que exista algun puntero como variable miembro que deba ser liberado.