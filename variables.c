#include<stdio.h>
#include<stdlib.h>

int main()
{
    char name[] = "Abhinav";
    int age = 21;

    printf("Hi! I am %s", &name);
    printf("\nI am %d years old", &age);
    age = 22;
    printf("\nI am gonna be %d after 10 months", &age);

    return 0;
}
