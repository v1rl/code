#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
考虑每个点作为首位时产生的贡献
值位当前贡献的情况数（左侧合法扩张个数） * 当前贡献的值（当前右侧扩张次数）
注意到：可以对当前点的所有右侧贡献做一个求和，求和公式恰好为1~n的求和公式
*/

const int mod = 998244353;
const int inf = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    vector<int> lst(n + 1);
    vector<i64> res(n + 1);
    for(int i = 1; i <= n; i ++) {
        res[i] = res[i - 1] + i;
    }

    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        if(mp.count(a[i])) {
            lst[i] = mp[a[i]];
        }
        mp[a[i]] = i;
    }

    i64 ans = 0;
    for(int i = 1; i <= n; i ++) {
        ans += 1ll * res[n - i + 1] * (i - lst[i]);
    }

    cout << ans << '\n';
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