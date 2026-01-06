#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        int n, m;
        cin >> n >> m;
        vector<int> s(n + 2);
        for(int i = 1; i <= n; i ++) cin >> s[i];
        s[n + 1] = m;
        n ++;

        for(int i = n; i >= 1; i --) s[i] -= s[i - 1];
        vector<int> a = s;
        a.emplace_back(0);

        for(int i = 1; i <= n; i ++)
            if(i > 1) 
                s[i] += s[i - 2];

        int odd, even;
        if(n & 1) odd = n, even = n - 1;
        else even = n, odd = n - 1;

        int sum = s[odd];
        for(int i = 1; i <= n; i ++)
            if(i % 2 == 0 && a[i] > 0)
                sum = max(sum, s[i - 1] + s[even] - s[i - 2] - 1);
        cout << sum << '\n';
    }
}
  