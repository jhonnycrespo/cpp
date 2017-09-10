/**
 * Overloading
 *
 * C++ allows you to specify more than one definition for a function name or an operator 
 * in the same scope, which is called function overloading and operator overloading respectively.
 *
 * When you call an overloaded function or operator, the compiler determines the most appropriate 
 * definition to use, by comparing the argument types you have used to call the function or operator 
 * with the parameter types specified in the definitions.
 */

#include <iostream>
using namespace std;
 
class printData {
   public:
      void print(int i) {
        cout << "Printing int: " << i << endl;
      }
      void print(double  f) {
        cout << "Printing float: " << f << endl;
      }
      void print(char* c) {
        cout << "Printing character: " << c << endl;
      }
};

int main(void) {
   printData pd;
 
   // Call print to print integer
   pd.print(5);
   
   // Call print to print float
   pd.print(500.263);
   
   // Call print to print character
   pd.print("Hello C++");
 
   return 0;
}