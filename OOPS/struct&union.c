
#include <stdio.h>
#include <string.h>

struct struct_ex
{
    int integer;
    char name[20];
    char character;
};

union union_ex
{
    int integer;
    char name[20];
    char character;
};

void main()
{
    struct struct_ex s={18,"geeksforgeeks",'s'};
  
    
    union union_ex u={18,"geeksforgeeks",'u'};
  
    printf("structure data:\n integer: %d\n"
           "decimal: %.2f\n name: %s\n",
           s.integer, s.name, s.character);
    printf("\nunion data:\n integer: %d\n"
           "decimal: %.2f\n name: %s\n",
           u.integer, u.name, u.character);
}
