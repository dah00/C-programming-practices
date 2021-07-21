#include <stdio.h>
#include <stdlib.h>

unsigned int factorial(unsigned int n);

int main() {
    /* testing code */
    printf("0! = %i\n", factorial(0));
    printf("1! = %i\n", factorial(1));
    printf("3! = %i\n", factorial(3));
    printf("5! = %i\n", factorial(5));
}

/* define your function here (don't forget to declare it) */
unsigned int factorial(unsigned int n){
    if(n==0 || n==1)   {
        return 1;
    }
    else if(n>1){
        return n * factorial(n-1);
    }
}


