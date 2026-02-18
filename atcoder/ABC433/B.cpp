#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    vector<int> stk;
    for(int i = 0; i < n; i ++) {
        while(stk.size() && a[stk.back()] <= a[i]) {
            stk.pop_back();
        }
        if(stk.size()) {
            cout << stk.back() + 1 << '\n';
        } else {
            cout << -1 << '\n';
        }
        stk.push_back(i);
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