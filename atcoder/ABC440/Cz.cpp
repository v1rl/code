#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
将长度为n的序列拆分成多个大小为2*w的环（最后一个可能不足2*w），然后从环中选取连续的w个数
注意到：每次选取的连续w个数，它们mod(2*w)后的得到的下标集合是相同的
我们可以直接维护下标为mod(2*w)的数组s，得到取模后的下标对应原序列中所有数的总和
然后通过差量法遍历所有连续的w，取其中最小的情况
*/

void solve() {
    int n, w;
    cin >> n >> w;
    vector<i64> s(2 * w);
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        s[i % (2 * w)] += x;
    }

    i64 res = 0;
    for(int i = 0; i < w; i ++) {
        res += s[i];
    }

    i64 ans = res;

    for(int i = 0; i < 2 * w; i ++) {
        res -= s[i];
        res += s[(i + w) % (2 * w)];
        ans = min(ans, res);
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
