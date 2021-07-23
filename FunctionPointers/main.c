#include <stdio.h>
#include <stdlib.h>

void someFunction(int arg){
    printf("This is someFunction being called and arg is: %d\n", arg);
    printf("Whoops leaving the function now!\n");
}

int main()
{
    void (*pf)(int);
    pf = &someFunction;
    printf("We are about to call someFunction() using a pointer!\n");
    (pf)(5);
    printf("Wow that was cool. Back to the main now!\n");

    return 0;
}
