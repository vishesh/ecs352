
/**
 * Average
 * Vishesh Yadav
 *
 */

#include<stdio.h>

int main()
{
    int a, b, c;
    char d;
    float e;

    printf("Enter numbers(a, b, c): ");
    scanf("%d  %d  %d", &a, &b, &c);

    e = (float)(a+b+c)/3;

    printf("Average: %f", e);
    printf("\nSum: %d", a+b+c);
}
