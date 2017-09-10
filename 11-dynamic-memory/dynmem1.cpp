#include <iostream>
using namespace std;

int main () {
   double* pvalue  = NULL; // Pointer initialized with null
   pvalue  = new double;   // Request memory for the variable

   // The memory may not have been allocated successfully, if the free store had been 
   // used up. So it is good practice to check if new operator is returning NULL pointer 
   // and take appropriate action.
   if(!(pvalue)) {
   cout << "Error: out of memory." <<endl;
   exit(1);
}
 
   *pvalue = 29494.99;     // Store value at allocated address
   cout << "Value of pvalue : " << *pvalue << endl;

   delete pvalue;         // free up the memory.

   return 0;
}