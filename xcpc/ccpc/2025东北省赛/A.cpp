#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    vector<int> l(n, -1), r(n, n);
    vector<int> stk;
    for(int i = 0; i < n; i ++) {
        while(!stk.empty() && gcd(a[stk.back()], a[i]) == a[i]) {
            stk.pop_back();
        }
        if(!stk.empty()) {
            l[i] = stk.back();
        }
        stk.push_back(i);
    }
    stk.clear();
    for(int i = n - 1; i >= 0; i --) {
        while(!stk.empty() && a[stk.back()] > a[i] && gcd(a[stk.back()], a[i]) == a[i]) {
            stk.pop_back();
        }
        if(!stk.empty()) {
            r[i] = stk.back();
        }
        stk.push_back(i);
    }

    i64 ans = 0;
    for(int i = 0; i < n; i ++) {
        int L = i - l[i];
        int R = r[i] - i;
        ans += 1ll * (i - l[i]) * (r[i] - i);
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
