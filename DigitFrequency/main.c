#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
        Find the frequency of each digit in the given string
        Sample input : a11472o5t6
        Sample output : 0 2 1 0 1 1 1 1 0 0
    */

    char s[256];
    scanf("%s", s);

    for(int i=0; i<strlen(s); i++)
        printf("%c\n", s[i]);


    char str;
    int arr[10];

    /*for(int i=0; i<10; i++)
        arr[i] = 0;

    while (scanf("%c", &str) == 1) {
        if (str>='0' && str<='9') {
            arr[str-'0']++;
        }
    }

    for (int i=0; i<10; i++) {
        printf("%d ", arr[i]);
    }*/

    return 0;
}
