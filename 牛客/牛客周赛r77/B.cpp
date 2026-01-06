#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int ceil(int n, int m)
{
    return (n + m - 1) / m;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> st(10);
    for(int i = 1; i <= n; i ++)
    {
        int x;
        cin >> x;
        st[x] ++;
    }
    for(int i = 1; i <= 9; i ++)
    {
        if(st[i] == ceil(n, 9) || st[i] == ceil(n, 9) - 1) ;
        else
        {
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';
    return 0;
}