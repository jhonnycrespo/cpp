#include <iostream>
#include <cstring>

using namespace std;

/**
 * C++ provides following two types of string representations:
 * The C-style character string.
 * The string class type introduced with Standard C++.
 */

void print(const char* str)
{
   cout << str << endl;
}

int main () {

   // this is placed on the stack. We can write.
   char str1[10] = "Hello";
   char str2[10] = "World";
   char str3[10];
   char str4[] = "Bjarne Stroustrup";
   
   // this will place "pulp fiction" in the read-only parts of the memory.
   // Any writing operation is illegal.
   const char* s1 = "pulp fiction";
   // warning: deprecated conversion from string constant to char*
   // es permitido por motivos de compatibilidad con C.
   char* s2 = "A perfect circle";

   // Si el signature de la function es void print(char* str)
   // sale invalid conversion from "const char*" to "char*"
   print(s1);
   print(s2);

   int  len ;

   // copy str1 into str3
   strcpy(str3, str1);
   cout << "strcpy( str3, str1) : " << str3 << endl;

   // concatenates str1 and str2
   strcat( str1, str2);
   cout << "strcat( str1, str2): " << str1 << endl;

   // copy str2 to str4
   strcpy(str4, str2);
   cout << "strcpy(str4, str2): " << str4 << " - strlen(str4): " << strlen(str4) << endl;

   // total lenghth of str1 after concatenation
   len = strlen(str1);
   cout << "strlen(str1) : " << len << endl;

   return 0;
}