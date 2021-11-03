
#include <stdio.h>
#include <string.h>

struct struct_ex
{
    int integer;
    char name[20];
    float fl;
};

union union_ex
{
    int integer;
    char name[20];
    float fl;
};

void main()
{
    struct struct_ex s={18,"geeksforgeeks",12.3};
  
    
    union union_ex u={18,"geeksforgeeks",13.3};
  
}
