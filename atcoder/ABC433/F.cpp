#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
子序列计数问题
考虑寻找具有唯一性的特征点（Pivot），利用特征点结合组合计数解题
注意到：目标子序列具有两段性，以第一段的最后一个点为特征点向左右计数
可以得到一个组合数求和公式，C(p,k-1)*C(q,k)，k为递增未知数
组合数求和优化，考虑范德蒙德卷积，发现将C(q, k)转为C(q, q-k)后，组合数第二项求和为定值q-1
使用范德蒙德卷积转换为C(p+q,q-1)
遍历计数即可
*/

const int mod = 998244353;

vector<int> fact, infact;
void init(int n) {
    fact.resize(n + 1);
    infact.resize(n + 1);

    fact[0] = infact[0] = fact[1] = infact[1] = 1;
    for(int i = 2; i <= n; i ++) {
        fact[i] = 1ll * fact[i - 1] * i % mod;
        infact[i] = 1ll * (mod - mod / i) * infact[mod % i] % mod;
    }
    for(int i = 2; i <= n; i ++) {
        infact[i] = 1ll * infact[i - 1] * infact[i] % mod;
    }
}

int C(int a, int b) {
    // 需要注意，第二项带减法，要考虑其是否会小于0
    if(a < b || b < 0) {
        return 0;
    }
    return 1ll * fact[a] * infact[b] % mod * infact[a - b] % mod;
}

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    init(n);

    vector<int> pre(10);
    vector<array<int, 10>> suf(n + 2);

    for(int i = n - 1; i >= 0; i --) {
        for(int j = 0; j < 10; j ++) {
            suf[i + 1][j] = suf[i + 2][j] + (j == s[i] - '0');
        } 
    }

    int ans = 0;
    for(int i = 0; i < n; i ++) {
        int ch = s[i] - '0';
        if(ch == 9) {
            continue;
        }
        ans += C(pre[ch] + suf[i + 2][ch + 1], suf[i + 2][ch + 1] - 1);
        ans %= mod;
        pre[ch] ++;
    }

    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}