/**
 * However, pointers and arrays are not completely interchangeable.
 *
 * It is perfectly acceptable to apply the pointer operator * to var but it is illegal 
 * to modify var value. The reason for this is that var is a constant that points to the 
 * beginning of an array and can not be used as l-value.
 */

#include <iostream>
 
using namespace std;
const int MAX = 3;
 
int main () {
   int  var[MAX] = {10, 100, 200};
 
   for (int i = 0; i < MAX; i++) {
      *var = i;    // This is a correct syntax
      var++;       // This is incorrect.
   }
   
   return 0;
}

/**
 * Because an array name generates a pointer constant, it can still be used in pointer-style 
 * expressions, as long as it is not modified. For example, the following is a valid statement
 */

// *(var + 2) = 500;