#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/largest-number/description/

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i ++) {
        cin >> s[i];
    }
    sort(s.begin(), s.end(), 
        [&](string x, string y) {
            return x + y > y + x;
        });

    for(auto c : s) {
        cout << c;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}