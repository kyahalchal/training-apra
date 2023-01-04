#include <stdio.h>
#include <string.h>

void ar(float x);

float calc(char op, float num)
{
    switch (op)
    {
    case '+':
        return num + num;
    case '-':
        return num - num;
    case '*':
        return num * num;
    case '/':
        return num / num;
    default:
        return 123456;
    }
}

struct Student
{
    /* data */
    char name[50];
    int age;
    double gpa;
};

int main()
{
    // ar(9);
    // printf("%f",calc('/',6));
    struct Student stu1;
    stu1.age = 12;
    stu1.gpa = 4;
    strcpy(stu1.name, "Jim"); // -----------> must include <string.h>
    printf("Hello!!");
    // FILE * fp = fopen("temp.txt","w");
    // FILE * fp = fopen("temp.txt","a");
    // fprintf(fp, "sgfkjsahjk\nsjfkjshfkjs");
    char line[255];
    FILE *fp = fopen("temp.txt", "r");
    fgets(line, 255, fp);
    printf("%s", line);
    fgets(line, 255, fp);
    fgets(line, 255, fp);
    fgets(line, 255, fp);
    printf("%s", line);
    fclose(fp);
    return 0;
}

void ar(float x)
{
    float a[] = {1, 2, 4, 5};
    printf("%f", a[2]);
    a[2] = 8;
    printf("\n%f", a[2]);
    a[2] = x;
    printf("\n%f", a[2]);
}