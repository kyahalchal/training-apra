#include <stdio.h>

int main() {
   // printf() displays the string inside quotation
   const int age;
   printf("Age:");
   scanf("%d",&age);
   printf("Age is %d", age);

   char name[20];
   printf("\nName:");
   fgets(name, 20, stdin);
   printf("Name is %s",name);
   return 0;
}
