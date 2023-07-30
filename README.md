# Introduction
Balanced binary representation (BBR) is a positional numeral system for integers with base 2 and digits -1, 0, 1. The BBR representation of a number is in the form of a non-adjacent form (NAF) if non-zero digits are not adjacent to each other.

Each integer has exactly one BBR-NAF representation without leading zeros. For 0, it is empty. For a non-zero x, the least significant digit c is:

0 if x is even,
1 if x - 1 is divisible by 4,
-1 if x + 1 is divisible by 4.
The more significant digits of the BBR representation of x form the representation of the number (x - c) / 2.

The BBR-NAF representation minimizes the Hamming weight of the number, which is the number of non-zero digits, among all binary representations. For example, Mersenne prime numbers have a Hamming weight of 2 in this representation. BBR-NAF is used in elliptic curve cryptography, including implementations of the Bitcoin cryptocurrency and the Ethereum platform.

# Description
This task involves implementing the representation of BBR-NAF, allowing efficient arithmetic operations on large integers with a small Hamming weight.

The representation is based on the arithmeticæ localis number system, described by John Napier in 1617 in his treatise Rabdologiæ. It is a binary, but non-positional, additive system.

In positional systems, the value of a number is determined by the sequence of digits in its representation, taking into account their positions. In additive systems, the value of a number is the sum of the values of its digits.

In arithmeticæ localis, letters represent powers of two, serving as "digits". In our representation, which we will call Napier-NAF, the digits are integers representing powers of two and their negations. The representation of a digit with a value of 2 ** n is a non-negative integer n, and the representation of a digit with a value of -(2 ** n) is a negative integer -n - 1.

The Napier-NAF representation of an integer x is an array of integers, the length of which is the Hamming weight of the BBR-NAF representation of x. In the array:

A negative number n indicates the occurrence of the digit -1 at position -n - 1 in the BBR-NAF representation of x.
A non-negative number n indicates the occurrence of the digit 1 at position n in the BBR-NAF representation of x.
Information about the digits is ordered from least significant to most significant, and positions are numbered starting from 0.
Task
In the header file napiernaf.h, there is an interface to the module for arithmetic operations on integers in the Napier-NAF representation:

Function void iton(int x, int **a, int *n); stores the representation of the number x in a dynamically allocated array *a of size *n.

Function int ntoi(int *a, int n); returns the value of the number represented by the n-element array a or 0 if the value does not fit in the int data type.

Function void nadd(int *a, int an, int *b, int bn, int **c, int *cn); stores the sum of the numbers represented by the an-element array a and the bn-element array b in a dynamically allocated array *c of size *cn.

Function void nsub(int *a, int an, int *b, int bn, int **c, int *cn); stores the difference of the numbers represented by the an-element array a and the bn-element array b in a dynamically allocated array *c of size *cn.

Function void nmul(int *a, int an, int *b, int bn, int **c, int *cn); stores the product of the numbers represented by the an-element array a and the bn-element array b in a dynamically allocated array *c of size *cn.

Function void nexp(int *a, int an, int *b, int bn, int **c, int *cn); stores the result of the exponentiation, with the base represented by the an-element array a and the non-negative exponent represented by the bn-element array b, in a dynamically allocated array *c of size *cn.

Function void ndivmod(int *a, int an, int *b, int bn, int **q, int *qn, int **r, int *rn); divides the number represented by the an-element array a by the non-zero number represented by the bn-element array b. It stores the integer quotient in a dynamically allocated array *q of size *qn and the remainder in a dynamically allocated array *r of size *rn.

The function gives a result consistent with the Euclidean division algorithm. The result of integer division of a number a by a non-zero integer b is an integer quotient q and an integer remainder r, satisfying the conditions:

a = b * q + r,
0 <= r < abs(b),

where abs(b) is the absolute value of b.

# Task
Write a module napiernaf.c implementing the napiernaf.h interface.

# Examples
Examples of programs using the napiernaf.c module and the expected output are provided in the files przyklad1.c with the output in przyklad1.out, przyklad2.c with the output in przyklad2.out, przyklad3.c with the output in przyklad3.out, and przyklad4.c with the output in przyklad4.out.
