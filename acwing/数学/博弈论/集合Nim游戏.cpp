#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];

    vector<int> f(1e5 + 10, -1);
    auto sg = [&](auto &&self, int x)->int
    {
        if(f[x] != -1) return f[x];

        unordered_set<int> S;
        for(int i = 0; i < n; i ++)
        {
            if(x >= a[i]) S.insert(self(self, x - a[i]));
        }

        for(int i = 0; ; i ++)
        {
            if(!S.count(i)) return i;
        }
    };

    int m;
    cin >> m;
    int res = 0;
    for(int i = 1; i <= m; i ++)
    {
        int x;
        cin >> x;
        res ^= sg(sg, x);
    }

    if(res) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}