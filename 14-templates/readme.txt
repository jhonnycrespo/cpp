Templates
=========

http://www.geeksforgeeks.org/templates-cpp/
https://www.tutorialspoint.com/cplusplus/cpp_templates.htm


Template is simple and yet very powerful tool in C++. The simple idea is to pass data type as a parameter 
so that we don’t need to write same code for different data types.


* How templates work?
- Templates are expended at compiler time. This is like macros. The difference is, compiler does type 
checking before template expansion. The idea is simple, source code contains only function/class, but 
compiled code may contain multiple copies of same function/class.


* Can we specify default value for template arguments?
- Yes, like normal parameters, we can specify default arguments to templates.


* What is the difference between function overloading and templates?
- Both function overloading and templates are examples of polymorphism feature of OOP. Function overloading 
is used when multiple functions do similar operations, templates are used when multiple functions do identical operations.


* What happens when there is static member in a template class/function?
- Each instance of a template contains its own static variable.


* What is template specialization?
- Template specialization allows us to have different code for a particular data type.