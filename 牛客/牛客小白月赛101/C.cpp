#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    int ans;
    if(n == 1) ans = 0;
    else if(n == 2) ans = 2;
    else if(n == 3) ans = 4;
    else if(!(n & 1)) ans = 4;
    else if(n & 1) ans = 6;
    cout << ans << '\n';
}