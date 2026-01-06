#include<bits/stdc++.h>
using namespace std;

void pp(int** b)
{
    *b = new int[2];
    **b = 3;
    *(*b + 1) = 4;
    cout << **b << '\n';
}

int main()
{
    int a = 5;
    int *b = &a;
    pp(&b);
    cout << *(b + 1);
}