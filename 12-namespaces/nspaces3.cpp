/**
 * The using directive can also be used to refer to a particular item within a namespace.
 *
 * Subsequent code can refer to cout without prepending the namespace, but other items 
 * in the std namespace will still need to be explicit.
 */

#include <iostream>
using std::cout;

int main () {
 
   cout << "std::endl is used with std!" << std::endl;
   
   return 0;
}