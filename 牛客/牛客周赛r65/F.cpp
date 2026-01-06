#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 5e8;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];

    vector<int> b = a;
    for(int i = 0; i < n; i ++)
    {
        if(a[i] == -999999999)
        {
            if(i && a[i - 1] >= -N + x) a[i] = a[i - 1] - x;
            else a[i] = N;
        }
    }

    int mx = 0;
    for(int i = 0; i < n - 1; i ++)
    {
        if(a[i] - a[i + 1] >= x) mx ++;
    }

    for(int i = 0; i < n; i ++)
    {
        if(b[i] == -999999999)
        {
            if(i && b[i - 1] >= -N + x) b[i] = b[i - 1] - x + 1;
            else b[i] = -N;
        }
    }

    int mn = 0;
    for(int i = 0; i < n - 1; i ++)
    {
        if(b[i] - b[i + 1] >= x) mn ++;
    }

    cout << mx << ' ' << mn << '\n';
}