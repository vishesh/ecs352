/**
  * String Operation: strrev[user defined]
  * Vishesh yadav
  *
  */

#include<stdio.h>
#include<string.h>

#define MAX 50

int main(void)
{
    char s1[MAX];

    printf("Enter s1: ");
    gets(s1);

    printf("reverse of s1 = %s", strrev(s1));

    return 0;
}

