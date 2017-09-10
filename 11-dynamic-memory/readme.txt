Memory in your C++ program is divided into two parts:
    - The stack − All variables declared inside the function will take up memory from the stack.
    - The heap − This is unused memory of the program and can be used to allocate the memory dynamically when program runs.

Many times, you are not aware in advance how much memory you will need to store particular information in a defined variable and the size of required memory can be determined at run time.

You can allocate memory at run time within the heap for the variable of a given type using a special operator in C++ which returns the address of the space allocated. This operator is called "new" operator.

If you are not in need of dynamically allocated memory anymore, you can use "delete" operator, which de-allocates memory that was previously allocated by "new" operator.




The malloc() function from C, still exists in C++, but it is recommended to avoid using malloc() function. 
The main advantage of new over malloc() is that new doesn't just allocate memory, it constructs objects which 
is prime purpose of C++.