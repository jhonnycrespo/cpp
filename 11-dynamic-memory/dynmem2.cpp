/**
 * Dynamic memory allocation for arrays
 */

char* pvalue  = NULL;         // Pointer initialized with null
pvalue  = new char[20];       // Request memory for the variable

delete [] pvalue;             // Delete array pointed to by pvalue


/**
 * Following the similar generic syntax of new operator, you can allocate for a multi-dimensional array
 */

double** pvalue  = NULL;      // Pointer initialized with null 
pvalue  = new double [3][4];  // Allocate memory for a 3x4 array 

delete [] pvalue;            // Delete array pointed to by pvalue