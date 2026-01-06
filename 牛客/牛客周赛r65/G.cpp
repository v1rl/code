#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    i64 n, m;
    cin >> n >> m;
    vector<i64> a(n);
    if(m < n / 2) 
    {
        cout << "-1" << '\n';
        return 0;
    }
    m -= n / 2;
    if(n % 2 == 0)
    {
        if(m % 2) 
        {
            cout << "-1" << '\n';
            return 0;
        }
        else
        {
            i64 k = m / n;
            int last = m % n;
            for(int i = 0; i < n; i ++)
            {
                a[i] = k + (i & 1);
            }
            for(int i = 0; i < n; i ++)
            {
                if(last == 0) break;
                if(i % 2 == 0)
                {
                    a[i] += 2;
                    last -= 2;
                }
            }
        }
    }
    else
    {
        if(m % 2)
        {
            m -= 1;
            i64 k = m / n;
            int last = m % n;
            if(last & 1) k --, last += n;
            for(int i = 0; i < n; i ++)
            {
                a[i] = k + 1 - (i & 1);
            }
            for(int i = 0; i < n; i ++)
            {
                if(last == 0) break;
                if(i % 2 == 1)
                {
                    a[i] += 2;
                    last -= 2;
                }
            }
            for(int i = 0; i < n; i ++)
            {
                if(last == 0) break;
                if(i % 2 == 0)
                {
                    a[i] += 2;
                    last -= 2;
                }
            }
        }
        else
        {
            i64 k = m / n;
            int last = m % n;
            if(last & 1) k --, last += n;
            for(int i = 0; i < n; i ++)
            {
                a[i] = k + (i & 1);
            }
            for(int i = 0; i < n; i ++)
            {
                if(last == 0) break;
                if(i % 2 == 0)
                {
                    a[i] += 2;
                    last -= 2;
                }
            }
            for(int i = 0; i < n; i ++)
            {
                if(last == 0) break;
                if(i % 2 == 1)
                {
                    a[i] += 2;
                    last -= 2;
                }
            }
        }
    }
    for(int i = 0; i < n; i ++)
    {
        cout << a[i] << ' ';
    }
    return 0;
}