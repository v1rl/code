#include <bits/stdc++.h>
using namespace std;
#define int long long
int num[6];

int get(int num1, int x)
{
    return num1 / (6 - x + 1);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        for(int i = 1; i <= 5; i ++) cin >> num[i];
        int ans = 0;
        for(int i = 1, j = 5; i < j; i ++, j --)
        {
            int d = min(num[i], num[j]);
            num[i] -= d;
            num[j] -= d;
            ans += d;
        }
        ans += num[3] / 2;
        num[3] %= 2;
        
        if(num[1] && num[4])
        {
            int a = num[1], b = num[4];
            int d = min(num[1] / 2 , num[4]);
            a -= d * 2;
            b -= d;
            ans += d;
            if(a) 
            {
                if(num[3] && a >= 3) ans ++, a -= 3;
                ans += a / 6; 
            }
            if(b)
            {
                if(a) b ++;
                if(num[3]) b ++;
                ans += get(b, 4);
            }
        }
        else if(num[4] && num[5])
        {
            int a = num[4], b = num[5];
            if(num[3]) b -= 1, ans ++;
            int d4 = min(a, b);
            ans += d4;
            b -= d4;
            a -= d4;
            if(a) ans += get(a, 4);
            if(b) ans += get(b, 5);
        }
        else if(num[2] && num[1])
        {
            int a = num[1], b = num[2];
            if(num[3])
            {
                a --, b --, ans ++;
                ans += b / 3;
                b %= 3;
                a += b * 2;
                ans += a / 6;
            }
            else
            {
                ans += b / 3;
                b %= 3;
                a += b * 2;
                ans += a / 6;
            }
        }
        else if(num[2] && num[5])
        {
            int a = num[2], b = num[5];
            if(num[3]) ans ++, b -= 1;
            int d2 = min(a, b);
            ans += d2;
            a -= d2;
            b -= d2;
            if(a) ans += a / 3;
            if(b) ans += get(b, 5);
        }
        else
        {
            if(num[1] >= 3)
            {
                if(num[3]) num[1] -= 3, ans ++; 
                ans += num[1] / 6;
            }
            else if(num[2]) 
            {
                ans += num[2] / 3;
                if(num[3] && num[2] % 3 == 2) ans ++; 
            }
            else if(num[4])
            {
                if(num[3]) num[4] ++;
                ans += get(num[4], 4);
            }
            else if(num[5])
            {
                if(num[3]) num[5] ++;
                ans += get(num[5], 5);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
