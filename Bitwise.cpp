#include <iostream>
using namespace std;

int main()
{
    int i = 6;
    cout << "Var: " << i << endl;
    cout << "LShift: " << (i << 2) << endl; // left shift
    cout << "RShift: " << (i >> 2) << endl; // right shift
    cout << "XOR: " << (i ^ 2) << endl;     // left shift
    cout << "AND: " << (i & 2) << endl;     // AND
    cout << "OR: " << (i | 2) << endl;      // OR
    cout << "1 << 5 " << (1 << 5) << endl;
    cout << "0x05 " << (0x05) << endl;
    cout << "^ " << ((0x05) ^ (1 << 5)) << endl;
    return 0;
}