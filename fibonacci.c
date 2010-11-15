
/**
 * Fibonacci Series
 * Vishesh Yadav
 *
 */

#include<stdio.h>

int main()
{
    int past = 0, present = 1, inc, x;
    printf("%4d", past);

    for (inc=0; inc<20; inc++) {
        printf("%4d", present);
        x = present;
        present += past;
        past = x;
    }
    getchar();
    return 0;
}
