#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t ;
    cin >> t;
    string s = "aoeiu";
    while(t --)
    {
        int n;
        cin >> n;
        string ans;
        for(int i = 0; i < 5; i ++)
        {
            int num = n / (5 - i);
            ans += string(num, s[i]);
            n -= num;
        }
        cout << ans << '\n';
    }
}