#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
考虑容斥反向求解
找到一条非严格单调递增的费用最大的链，这条链上的点保持不变，其他点全部改变
用总费用减去它即可得到答案
f[i]维护以i结尾的子串中非严格单调递增的链的最大费用(可以类比最大长度，即最长不下降子序列)
*/

const i64 inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), w(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++) {
        cin >> w[i];
    }
    vector<i64> f(n + 1);
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j < i; j ++) {
            if(a[j] <= a[i]) {
                f[i] = max(f[i], f[j] + w[i]);
            }
        }
    }

    cout << accumulate(w.begin() + 1, w.end(), 0ll) - *max_element(f.begin(), f.end()) << '\n';
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