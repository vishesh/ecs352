
/**
 * Factorial
 * Vishesh Yadav
 *
 */

#include<stdio.h>

int main()
{
    int a, fact = 1;
    printf("\nEnter number: ");
    scanf("%d", &a);

    int i;
    for (i=1; i<=a; i++) {
        fact *= i;
    }

    printf("Factorial is: %d", fact);
    getchar();
    getchar();
    return 0;
}
