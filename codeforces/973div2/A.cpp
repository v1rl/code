#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int ceil(int n, int m)
{
    return (n + m - 1) / m;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        int x;
        cin >> x;
        int n, m;
        cin >> n >> m;
        cout << ceil(x, min(n, m)) << '\n';
    }
}