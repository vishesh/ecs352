/**
  * String Operation: strlen[user defined]
  * Vishesh yadav
  *
  */

#include<stdio.h>

int strlen(char *s)
{
    char* t=s;
    while (*t++);
    t--;
    return t-s;
}

#define MAX 50

int main(void)
{
    char s1[MAX];

    printf("Enter s1: ");
    gets(s1);

    printf("length of s1 = %d", strlen(s1));

    return 0;
}

