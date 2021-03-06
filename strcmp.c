/**
  * String Operation: strcmp[user defined]
  * Vishesh yadav
  *
  */

#include<stdio.h>

int strcmp(char *s, char *t)
{
    for ( ; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}

#define MAX 50

int main(void)
{
    char s1[MAX], s2[50];

    printf("Enter s1: ");
    gets(s1);
    printf("Enter s2: ");
    gets(s2);

    printf("\t s1=%s \n\t s2=%s \n",s1,s2);

    printf("strcmp over s1 and s2=%i",strcmp(s1,s2));

    return 0;
}

