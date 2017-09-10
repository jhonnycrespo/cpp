/**
 * As you know every variable is a memory location and every memory location 
 * has its address defined which can be accessed using ampersand (&) operator 
 * which denotes an address in memory.
 *
 * A pointer is a variable whose value is the address of another variable.
 */

#include <iostream>

using namespace std;

int main () {
   int  var1;
   char var2[10];

   cout << "Address of var1 variable: ";
   cout << &var1 << endl;

   cout << "Address of var2 variable: ";
   cout << &var2 << endl;

   return 0;
}