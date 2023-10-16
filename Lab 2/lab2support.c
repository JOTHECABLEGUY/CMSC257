// Include Files
#include <stdio.h>
// Project Includes
#include "lab2header.h"
// Function Implementations

int reverse_number(int num)
{
	int reversed = 0;
while(num > 0)
{
reversed = reversed * 10 + num % 10;
num = num / 10;
}
return reversed;
}
int even_odd(int num)
{
	int result = 0;
	result = num % 2;
	return result;
}


int is_prime(int num){
    int i,m=0;    
    
    m=num/2;    
    for(i=2;i<=m;i++)    
    {    
        if(num%i==0)    
        {    
            return 1;    
        }    
    }
    return 0;
 }   
