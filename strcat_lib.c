/**
  * String Operation: strcat
  * Vishesh yadav
  *
  */

#include<stdio.h>
#include<string.h>

#define MAX 50

int main(void)
{
    char s1[MAX], s2[50];

    printf("Enter s1: ");
    gets(s1);
    printf("Enter s2: ");
    gets(s2);
    printf("\t s1=%s \n\t s2=%s \n",s1,s2);

    printf("Concatanating s1 and s2 to s1. Now,\n");
    strcat(s1,s2);
    printf("\t s1=%s \n\t s2=%s \n",s1,s2);

    return 0;
}

