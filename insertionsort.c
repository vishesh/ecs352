
/**
  * Insertion Sort
  * Vishesh yadav
  *
  */

#include<stdio.h>

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

void insertionSort(int arr[], int length)
{
    int i, j, tmp;
    for (i = 1; i < length; i++) {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
    }
}

int main()
{
    int a[MAX_ELEMENTS];
    get_array(a, MAX_ELEMENTS);
    printf("You Entered: ");
    print_array(a, MAX_ELEMENTS);
    printf("After Sorting: ");
    insertionSort(a, MAX_ELEMENTS);
    print_array(a, MAX_ELEMENTS);
}
