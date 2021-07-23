#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    int areas[n];

    // i=0,1,2
    for (int i=0; i<n; i++) {
        float a = (tr[i].a+tr[i].b+tr[i].c)/2.0;
        areas[i] = (a*(a-tr[i].a)*(a-tr[i].b)*(a-tr[i].c));
    }

    for (int i=n-1; i>=1; i--) {
        for(int j=1; j<=i; j++){
            if(areas[j-1] > areas[j]) {
                int temp = areas[j-1];
                areas[j-1] = areas[j];
                areas[j] = temp;

                temp=tr[j].a;
                tr[j].a=tr[j-1].a;
                tr[j-1].a=temp;

                temp=tr[j].b;
                tr[j].b=tr[j-1].b;
                tr[j-1].b=temp;

                temp=tr[j].c;
                tr[j].c=tr[j-1].c;
                tr[j-1].c=temp;

            }

        }
    }

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
