// angled brackets are used to tell the compiler that we are including a header
// file that was included with the compiler, so it should look for that header
// file in the system directories.
// Use angled brackets to include header files that come with the compiler.
#include <iostream>
// The doubled-quotes tell the compiler that this is a header file we are suplying,
// so it should look for that header file in the current directory countaining our source
// code. If it doesn't find the header file there, it will check any other include paths that
// we've specified as part of the compiler settings.
// Use double quotes to include any other header file.
#include "add.hpp"
 
int add(int x, int y); // forward declaration using function prototype
 
int main()
{
    std::cout << "The sum of 3 and 4 is " << add(3, 4) << std::endl;
    return 0;
}