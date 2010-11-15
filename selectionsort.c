
/**
  * Selection Sort
  * Vishesh yadav
  *
  */

#include<stdio.h>

#define MAX_ELEMENTS 10

typedef enum { false, true } bool;

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

void selectionSort(int arr[], int n)
{
    int i, j, minIndex, tmp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        if (minIndex != i) {
            tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;
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
    selectionSort(a, MAX_ELEMENTS);
    print_array(a, MAX_ELEMENTS);
}