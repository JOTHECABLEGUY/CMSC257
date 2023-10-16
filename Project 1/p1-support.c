#include "p1-support.h"
#include <stdio.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////
//
//  File          	: p1support.c
//  Description    	: This is a set of general-purpose utility functions 
//					we use for the 257 project #1.
//  Author					: Jordan Dube
//	Date						: 03/13/2021
//	Notes						: 


////////////////////////////////////////////////////////////////////////
//// Function Definitions
////////////////////////////////////////////////////////////////////////

//function definitions as decribed in the project manual 

//Shortly describe function here
void display_array(unsigned int* arr, int size){
int i;
printf("{ ");
for(i = 0; i < size; i++){
printf("%10d, ", *(arr+i));
}
printf(" }");	
//Implement the function
}	
unsigned int mask = 00000000000000000000000000000001;
unsigned int count_set_bits(unsigned int u_int){
unsigned int num1s = 0;
while(u_int > 00000000000000000000000000000000){
if ((u_int & mask))
	num1s++;
u_int>>=1;
}
return num1s;
}
void binary_string(char* s, unsigned int decimal_int){
int i; 
char str[8*sizeof(unsigned int)+1] = {0};
for(i = 0; i<8*sizeof(unsigned int)+1; i++){
str[i] = (decimal_int << i) & (1 << (8*sizeof(unsigned int)-1)) ? '1' : '0';
}
//for (i = 0; i < 8*sizeof(unsigned int)+1; i++){
for(i = 31; i >= 0; i--){
str[i+2] = str[i];
}
str[34] = '\0';
str[0] = '0';
str[1] = 'b';
printf("%10s", str);
}  
int bitwise_abs(int x){
if(bit_get(x, 31) == 0)
	return x;
else {
return  (~(x))+1; 
}
}
int odd_or_even(unsigned int r){
int end = bit_get(r, 0);
if(end == 0)
return 0;
else 
return 1;
}
int bitwise_mod64(int num){
int b = 0b111111; 
return (num & b);
}
int bit_get(int num, int location){
int i = 0;
for (i = 0; i <location; i++){
num>>=1;
}
return num & mask;
}
unsigned int reverse_bitwise(unsigned int u){
unsigned int t;
t = u;
unsigned int result;
while(t>0){
result<<=1;
if((t&1) == 1)
result = (result^1);
t>>= 1;
}
return (unsigned int) (bitwise_abs(result));
}
void swap_ints(int* ptr1, int* ptr2){
*ptr1 += *ptr2;
*ptr2 = *ptr1-*ptr2;
*ptr1 = *ptr1 - *ptr2;
}


//Additional function definitions for helper functions




