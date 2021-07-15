#include <stdio.h>
#include <stdlib.h>

int count = 0;

int runner()
{
    count++;
    return count;
}

int main()
{
    printf("%d ", runner());
    printf("%d ", runner());
    return 0;
}
