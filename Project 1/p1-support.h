#ifndef CMSC257_P1SUPPORT_INCLUDED
#define CMSC257_P1SUPPORT_INCLUDED
////////////////////////////////////////////////////////////////////////
//
//  File          	: p1support.h
//  Description    	: Headers of general-purpose utility functions 
//					we use for the 257 project #1.
//  Author					: Jordan Dube
//	Date						:03/13/2021
//	Notes						:
////////////////////////////////////////////////////////////////////////
//	Add comments for each function below in the following format
///////////////////////////////////////////////////////////////////////
//
// 	Function     : display_array
// 	Description  : Prints out an array of integers on a single line
// 
// 	Inputs       : an array of 10 integers
// 	Outputs      : void
////////////////////////////////////////////////////////////////////////
//
// 	Function     : count_set_bits
// 	Description  : returns the number of 1s in a number
// 
// 	Inputs       : an unsigned integer
// 	Outputs      : an unsigned integer
////////////////////////////////////////////////////////////////////////
//
//	Function     : reverse_bitwise
//	Description  : returns the number whose bits are reversed (i.e. leftmost bit becomes rightmost and so on)
//
//	Inputs       : an unsigned integer to reverse
//	Outputs      : an unsigned integer
////////////////////////////////////////////////////////////////////////
//
//	Function     : binary_string
//	Description  : Fills the string with a binary representation of the number suitable for printing
//
//	Inputs       : a pointer to a string, and an unsigned integer
//	Outputs      : void
////////////////////////////////////////////////////////////////////////
//
//	Function     : bitwise_mod64
//	Description  : returns the result of modding the input by 64
//
//	Inputs       : an integer
//	Outputs      : an integer
////////////////////////////////////////////////////////////////////////
//
//	Fuction      : bitwise_abs
//	Description  : returns the absolute value of input integer
//
//	Inputs       : an integer
//	Outputs      : an integer
////////////////////////////////////////////////////////////////////////
//
//	Function     : bit_get
//	Description  : extracts the specified bit from a given number
//
//	Inputs       : two integers
//	Outputs      : an integer
////////////////////////////////////////////////////////////////////////
//
//	Function     : odd_or_even
//	Description  : returns 1 if the input integer is odd and 0 if the input is even
//
//	Inputs       : an unsigned integer
//	Outputs      : an integer
////////////////////////////////////////////////////////////////////////
//
//	Function     : swap_ints
//	Description  : swaps the given numbers without a temp variable
//
//	Inputs       : 2 integer pointers 
//	Outputs      : void
///////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////
// Functional Prototypes
////////////////////////////////////////////////////////////////////////

// This function prints out the array of integer values
void display_array(unsigned int*, int);

// This function returns the number of 1s in bitwise representation of a number
unsigned int count_set_bits(unsigned int);

// This funtion returns the number whose bits are reversed
unsigned int reverse_bitwise(unsigned int);

// This function fills the text string with a binary representation of the number suitable for printing
void binary_string(char*, unsigned int);

// This function returns the input modular divided by 64
int bitwise_mod64(int);

// This function returns the absolute value of the input integer
int bitwise_abs(int);

// This function extracts the specified bit from a given number
int bit_get(int, int);

// This function returns 1 if the unsigned integer input is odd and 0 if the input is even
int odd_or_even(unsigned int);

// This function swaps the input numbers without using a temp variable
void swap_ints(int*, int*);


#endif // CMSC257_P1SUPPORT_INCLUDED
