#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;
typedef pair<int, int> PII;
const int inf = 2e9;

// https://www.acwing.com/problem/content/5528/

void solve()
{
    int n, stt;
    cin >> n >> stt;
    vector<array<int, 2>> p(n + 1);
    for(int i = 1; i <= n; i ++)
        cin >> p[i][0] >> p[i][1];

    vector<int> st(n + 1);
    vector<int> jup(n + 1);     //当前点的上一次跳跃能力
    int pos = stt;  //当前位置
    int t = 1;      //方向
    int k = 1;      //跳跃能力
    int ans = 0;
    while(pos >= 1 && pos <= n)
    {
        auto [op, v] = p[pos];
        if(op == 1)
        {
            if(!st[pos] && k >= v)
            {
                ans ++;
                st[pos] = true;
            } 
        }
        else
        {
            t = -t;
            k += v;
            if(k == jup[pos]) break;
            jup[pos] = k;
        }
        pos += t * k;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while(t --)
    {
        solve();
    }
}