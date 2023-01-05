#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    int x = 1;
    int * y = &x;
    int * z = &y;
    int * a = &z;
    printf("%d %d %d %d", x, y, z, &a);
    return 0;
}
