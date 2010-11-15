
/**
  * Binary Search
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

int binary_search(int *arr, int len, int data)
{
    int min = 0, max = len;
    while ( min<max ) {
        int mid = (min+max)/2;
        if (arr[mid]<data)
            min = mid+1;
        else if (arr[mid]>data)
            max = mid-1;
        else if (arr[mid]==data)
            return mid;
    }
    return -1;
}

int main()
{
    int a[MAX_ELEMENTS], element, result;
    get_array(a, MAX_ELEMENTS);
    printf("You Entered: ");
    print_array(a, MAX_ELEMENTS);
    printf("What to search: ");
    scanf("%d", &element);
    result = binary_search(a, MAX_ELEMENTS, element);
    if (result<0)
        printf("\nElement Not Found");
    else
        printf("\nElement found at: %d", result);
}

