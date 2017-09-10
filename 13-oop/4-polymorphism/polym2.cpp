/**
 * Polymorphism
 *
 * Let's make a slight modification in our program and precede the declaration of area() 
 * in the Shape class with the keyword virtual.
 *
 * This time, the compiler looks at the contents of the pointer instead of it's type. 
 * Hence, since addresses of objects of tri and rec classes are stored in *shape the respective 
 * area() function is called.
 *
 * As you can see, each of the child classes has a separate implementation for the function area(). 
 * This is how polymorphism is generally used.
 *
 * A virtual function is a function in a base class that is declared using the keyword virtual. 
 * Defining in a base class a virtual function, with another version in a derived class, signals 
 * to the compiler that we don't want static linkage for this function.
 */

#include <iostream> 
using namespace std;
 
class Shape {
   protected:
      int width, height;
      
   public:
      Shape( int a = 0, int b = 0){
         width = a;
         height = b;
      }
      virtual int area() {
         cout << "Parent class area :" <<endl;
         return 0;
      }
};
class Rectangle: public Shape {
   public:
      Rectangle( int a = 0, int b = 0):Shape(a, b) { }
      
      int area () { 
         cout << "Rectangle class area :" <<endl;
         return (width * height); 
      }
};

class Triangle: public Shape {
   public:
      Triangle( int a = 0, int b = 0):Shape(a, b) { }
      
      int area () { 
         cout << "Triangle class area :" <<endl;
         return (width * height / 2); 
      }
};

// Main function for the program
int main() {
   Shape *shape;
   Rectangle rec(10,7);
   Triangle  tri(10,5);

   // store the address of Rectangle
   shape = &rec;
   
   // call rectangle area.
   shape->area();

   // store the address of Triangle
   shape = &tri;
   
   // call triangle area.
   shape->area();
   
   return 0;
}