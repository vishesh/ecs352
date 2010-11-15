/**
  * String Operation: strrev[user defined]
  * Vishesh yadav
  *
  */

#include<stdio.h>

char* strrev(char* s)
{
    int l=-1, i=0;
    while (s[++l]);
    for (i=0; i<l/2; ++i) {
        char t=s[i];
        s[i]=s[l-i-1];
        s[l-i-1]=t;
    }
    return s;
}

#define MAX 50

int main(void)
{
    char s1[MAX];

    printf("Enter s1: ");
    gets(s1);

    printf("reverse of s1 = %s", strrev(s1));

    return 0;
}

