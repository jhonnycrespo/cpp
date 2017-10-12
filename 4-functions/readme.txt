https://stackoverflow.com/questions/334856/are-there-benefits-of-passing-by-pointer-over-passing-by-reference-in-c
https://stackoverflow.com/questions/57483/what-are-the-differences-between-a-pointer-variable-and-a-reference-variable-in


PASSING BY POINTER OR PASSING BY REFERENCE
===========================================

A pointer can receive a NULL parameters, a reference parameter cannot. If there's ever
a chance that you could want to pass "no object", then use a pointer insted of a reference.

Passing by pointer
==================

