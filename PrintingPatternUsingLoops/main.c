#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
      int count = n;
      int indStart = 0;
      int indEnd = (n*2)-2;
      int array[indEnd+1][indEnd+1];
      while(count>=1){
        for (int i=indStart; i<=indEnd; i++){
            array[i][indStart] = count;
            array[indStart][i] = count;
            array[i][indEnd] = count;
            array[indEnd][i] = count;
        }
        indStart++;
        indEnd--;
        count--;
      }

      for (int i=0; i<(n*2)-1; i++){
        for (int j=0; j<(n*2)-1; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
      }


    return 0;
}
