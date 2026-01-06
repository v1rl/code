#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
char stk[N];
int cnt = 0;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int len;
    string s;
    cin >> len >> s;
    for(auto c : s)
    {
        stk[++ cnt] = c;
        char b = stk[cnt --];
        char a = stk[cnt --];
        if((a == 'f' && b == 'c') || (a == 't' && b == 'b')) continue;
        stk[++ cnt] = a;
        stk[++ cnt] = b;
    }
    cout << cnt << '\n';
    return 0;
}