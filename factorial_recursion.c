
/**
 * Factorial using Recursion
 * Vishesh Yadav
 *
 */

#include<stdio.h>

int factorial(int num)
{
    return (num==1) ?1 :factorial(num-1)*num;
}

int main()
{
    int x;
    printf("\nEnter X: ");
    scanf("%d%*c", &x);
    printf("Factorial is:  %d", factorial(x));
    getchar();
    return 0;
}
