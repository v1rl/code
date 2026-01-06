#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> day(n + 1);
    vector<int> stt(n + 1);
    vector<int> w(n + 1);
    for(int i = 1; i <= n; i ++) cin >> stt[i];

    i64 sum = 0;
    for(int i = 1; i <= n; i ++)
    {
        int l, r;
        cin >> l >> r;
        sum += r;
        if(l >= r) continue;
        day[stt[i]].emplace_back(r - l);
    }

    vector<i64> dp(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        dp[i] = max(dp[i], dp[i - 1]);
        for(auto x : day[i])
        {
            dp[i + m - 1] = max(dp[i - 1] + x, dp[i + m - 1]);
        }
    }

    // for(int i = 1; i <= n; i ++) cout << dp[i] << ' ';
    //     cout << '\n';
    // cout << dp[n] << '\n';

    cout << sum - dp[n] << '\n';
}

