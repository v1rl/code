#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int mod = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = '#' + s;

    // dp[i]当前以i所代表字符为结尾的本质不同子序列个数
    // f[i]前i个中本质不同的子序列个数
    vector<int> dp(26);
    vector<int> f(n + 1);
    for(int i = 1; i <= n; i ++) {
        int ch = s[i] - 'a';
        f[i] = (f[i - 1] + (f[max(0, i - k - 1)] + 1 - dp[ch] + mod) % mod) % mod;
        dp[ch] = (f[max(0, i - k - 1)] + 1) % mod;

    }

    cout << f[n] << '\n';
    
    /*
    // dp[i]当前以i结尾的新增的本质不同子序列个数
    // sum[i]前i个中本质不同的子序列个数
    vector<int> lst(26);
    vector<int> dp(n + 1);
    vector<int> sum(n + 1);
    auto get = [&](int x) {
        return x < 0 ? 0 : sum[x];
    };

    for(int i = 1; i <= n; i ++) {
        int ch = s[i] - 'a';
        if(lst[ch] == 0) {
            dp[i] = (1 + get(i - k - 1)) % mod;
        } else {
            dp[i] = ((get(i - k - 1) + 1) - (get(lst[ch] - k - 1) + 1) + mod) % mod;
        }

        sum[i] = (sum[i - 1] + dp[i]) % mod;
        lst[ch] = i;
    }

    cout << sum[n] << '\n';
    */
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}
