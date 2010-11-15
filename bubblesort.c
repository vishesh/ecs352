
/**
  * Bubble Sort
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

void bubbleSort(int arr[], int n)
{
    bool swapped = true;
    int j = 0, i;
    int tmp;
    while (swapped) {
        swapped = false;
        j++;
        for (i = 0; i < n - j; i++) {
            if (arr[i] > arr[i + 1]) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                swapped = true;
            }
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
    bubbleSort(a, MAX_ELEMENTS);
    print_array(a, MAX_ELEMENTS);
}