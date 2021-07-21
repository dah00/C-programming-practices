#include <stdio.h>
#include <stdlib.h>

int main()
{
    int intarray[5] = {10, 20, 30, 40, 50};

    for(int i=0; i<5; i++)
        printf("intarray[%d] has value %d - and address @ %x\n", i, intarray[i], &intarray[i]);

    int *intpointer = &intarray[2]; // point to the 3th element in the array
    printf("address: %x - has value %d\n", intpointer, *intpointer);

    intpointer += 2;    // Shift by 2 to the point's address so it points to the 5th element
    printf("address: %x - has value %d\n", intpointer, *intpointer); //  print the address of the 5th element

    return 0;
}
