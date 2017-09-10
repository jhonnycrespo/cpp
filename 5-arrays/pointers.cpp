/**
 * An array name is a constant pointer to the first element of the array.
 */

#include <iostream>
using namespace std;
 
int main () {
   // an array with 5 elements.
   // balance is a pointer to &balance[0], which is the address of the first element of the array balance.
   double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
   double *p;

   p = balance;
 
   // output each array element's value 
   cout << "Array values using pointer " << endl;
   
   for ( int i = 0; i < 5; i++ ) {
      cout << "*(p + " << i << ") : ";
      cout << *(p + i) << endl;
   }
   cout << "Array values using balance as address " << endl;
   
   for ( int i = 0; i < 5; i++ ) {
      cout << "*(balance + " << i << ") : ";
      cout << *(balance + i) << endl;
   }
 
   return 0;
}