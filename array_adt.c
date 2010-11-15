
/**
  * Array Insertion and Deletion
  * Vishesh yadav
  *
  */


#include <stdio.h>

void array_print(int *a, int size)
{
    while (size--)
        printf("%i ",*a++);
}

int array_insert(int *a, int size, int element, int position)
{
    int *p;
    if (position >=size) {
        fprintf(stderr,"\narray_insert: The specified position %i is not less than the"
                " size of the array which is %i\n",position,size);
        return 0;
    }
    p=a+position;
    a+=size;
    while (a>p)    *(a)=*(a-1),a--;
    *a=element;
    return 1;
}

int array_delete(int *a, int size, int position)
{
    int *last;
    if (position >=size) {
        fprintf(stderr,"\narray_delete: The specified position %i is not less than the"
                " size of the array which is %i\n",position,size);
        return 0;
    }
    last=a+size-1;// points to the last element
    a+=position;//a now points to the position of the deltetion
    while (a<last) *(a)=*(a+1),a++;
    return 1;
}

void array_reverse(int *a, int size)
{
    int i,t;
    for (i=0; i < size/2 ; i++) {
        t=a[i];
        a[i]=a[size-i-1];
        a[size-i-1]=t;
    }
}

void input_array(int *a, int size)
{
    while (size--)
        scanf("%i",a++);
}

#define MAX 20

int main()
{
    int a[MAX];
    int s;
    char i;
    int e;
    int p;

    printf("With How many numbers do you wanto start with?");
    scanf("%i", &s);
    printf("Enter the array:");
    input_array(a,s);

    do {
        printf("\nWhat do you want to do?"
               "\n 1. Insert an element.\n 2. Delete an element \n 3. Reverse"
               "\n 4. Display \n 5. Exit\n");
        fflush(stdin);
        scanf("%c", &i);
        switch (i) {
        case '1': {
            printf("Enter the Position (zero-based) and the element to be inserted:");
            scanf("%i%i",&p,&e);
            array_insert(a,s,e,p);
            s++;
            printf("Done!\n");
            break;
        }
        case '2': {
            printf("Enter the position at which you want to delete the element:");
            scanf("%i",&p);
            array_delete(a,s,p);
            s--;
            printf("Done!\n");
            break;
        }
        case '3': {
            array_reverse(a,s);
            printf("Done!\n");
            break;
        }
        case '4': {
            printf("\n");
            array_print(a,s);
            printf("\n\n");
            break;
        }
        }
    } while (i!='5');
    return 0;
}
