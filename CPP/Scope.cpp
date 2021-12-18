#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int global = 60;

void print()
{
    cout << global << endl;
}

int main()
{
    int global = 9;
    global = 10;
    // local variable gets updated

    // we can't use a C++ keywork as a variable name
    char a = 'd';

    /* "<<" is called insertion operator & ">>" is extraction operator */
    cout << "The value of a is: " << a << endl;

    // local and global variable can be of same name
    // local variable takes the precedence
    cout << "The value of global is: " << global << endl;

    // this goes to function and checks if the variable is present
    // if not it checks globally and return it
    cout << "The value of global in function is: ";
    print();

    // if we want the global value
    // we use scope resolution operator
    cout << "the value of global variable is: " << ::global << endl;

    // if we want to have different names for a single variable
    float ref_var = 4;
    // we make copy of ref_var
    float &same_var = ref_var;
    cout << "Value of ref_var is " << ref_var << " and same_var is " << same_var << endl;
    return 0;
}