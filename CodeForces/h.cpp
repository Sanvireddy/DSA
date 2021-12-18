#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    std::cout << sizeof(int) << std::endl;
    int x = 0x1000;
    x = x << 32;
    std::cout << hex << x << std::endl;
    return 0;
}