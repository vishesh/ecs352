
/**
  * Merge Sort
  * Vishesh yadav
  *
  */


#include<stdio.h>
#include<stdlib.h>

#define MAX_ELEMENTS 10

void print_array(int *a, int len)
{
    int i;
    printf("\n--------\n");
    for (i=0; i<len; i++)
        printf("%d - ", a[i]);
    printf("\n--------\n");
}

void get_array(int *a, int len)
{
    int i;
    printf("\n\nArray Input: \n");
    for (i=0; i<len; i++) {
        printf("Enter array[%d]: ", i);
        scanf("%d", &a[i]);
    }
    printf("\n");
}


void merge ( int a[], int first, int mid, int last )
{
    int i = first, j = mid, k = 0;
    int *save = malloc ( ( last - first ) * sizeof *save );

    while ( i < mid && j < last ) {
        if ( a[i] <= a[j] )
            save[k++] = a[i++];
        else
            save[k++] = a[j++];

    }

    while ( i < mid )
        save[k++] = a[i++];

    while ( j < last )
        save[k++] = a[j++];

    for ( i = 0; i < ( last - first ); i++ )
        a[first + i] = save[i];

    free ( save );
}

void mergesort_r ( int a[], int first, int last )
{
    if ( first < last - 1 ) {
        int mid = ( first + last ) / 2;
        mergesort_r ( a, first, mid );
        mergesort_r ( a, mid, last );
        merge ( a, first, mid, last );
    }
}

void mergesort ( int a[], int n )
{
    mergesort_r ( a, 0, n );
}

int main()
{
    int a[MAX_ELEMENTS];
    get_array(a, MAX_ELEMENTS);
    printf("You Entered: ");
    print_array(a, MAX_ELEMENTS);
    printf("After Sorting: ");
    mergesort(a, MAX_ELEMENTS);
    print_array(a, MAX_ELEMENTS);
}

