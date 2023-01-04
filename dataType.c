#include <stdio.h>

int main() {
    int age = 40;
    double gpa = 3.6;
    char grade = 'A';
    char phrase[] = "hey! wyd?"; //immutable
    printf("codes working %d %c %s %lf", age, grade, phrase, gpa);
    
    age = 50;
    gpa = 34.6;
    grade = 'B';
    // char phrase[] = "hey!!!! wyd?"; ----> will cause error since strings are immutable

    printf("\n \"codes working %d %c %s %lf\"", age, grade, phrase, gpa);

   return 0;
}
