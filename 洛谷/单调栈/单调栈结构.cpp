#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

// https://www.nowcoder.com/practice/2a2c00e7a88a498693568cef63a4b7bb

const int inf = 1e9;
const int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    vector<int> l(n, -1), r(n, -1);
    vector<int> stk;
    for(int i = 0; i < n; i ++) {
        while(!stk.empty() && a[stk.back()] >= a[i]) {
            stk.pop_back();
        }
        if(!stk.empty()) {
            l[i] = stk.back();
        }
        stk.push_back(i);
    }
    stk.clear();
    for(int i = n - 1; i >= 0; i --) {
        while(!stk.empty() && a[stk.back()] >= a[i]) {
            stk.pop_back();
        }
        if(!stk.empty()) {
            r[i] = stk.back();
        }
        stk.push_back(i);
    }

    for(int i = 0; i < n; i ++) {
        cout << l[i] << ' ' << r[i] << '\n';
    }
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
