#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    string a, b;
    cin >> a >> b;

    int n = a.size(), m = b.size();

    // a = '#' + a;
    // b = '#' + b;

    // vector<int> ne(m + 1);
    // for(int i = 2, j = 0; i <= m; i ++)
    // {
    //     while(j && b[i] != b[j + 1]) j = ne[j];
    //     if(b[i] == b[j + 1]) j ++;
    //     ne[i] = j;
    // }

    // for(int i = 1, j = 0; i <= n; i ++)
    // {
    //     while(j && a[i] != b[j + 1]) j = ne[j];
    //     if(a[i] == b[j + 1]) j ++;
    //     if(j == m) 
    //     {
    //         cout << i - m + 1 << '\n';
    //         j = ne[j];
    //     }
    // }

    // for(int i = 1; i <= m; i ++)
    // {
    //     cout << ne[i] << ' ';
    // }

    vector<int> ne(m + 1);
    for(int i = 1, j = 0; i < m; i ++)
    {
        while(j && b[i] != b[j]) j = ne[j - 1];
        if(b[i] == b[j]) j ++;
        ne[i] = j;
    }

    for(int i = 0, j = 0; i < n; i ++)
    {
        while(j && a[i] != b[j]) j = ne[j - 1];
        if(a[i] == b[j]) j ++;
        if(j == m)
        {
            cout << i - m + 2 << '\n';
            j = ne[j - 1];
        }
    }

    for(int i = 0; i < m; i ++)
        cout << ne[i] << ' ';
}

