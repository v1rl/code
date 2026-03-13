#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    vector<int> z(n);
    for(int i = 1; i < n; i ++) {
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i] ++;
        }
    }

    for(int i = 0; i < n; i ++) {
        cout << z[i] << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while(t --) {
        solve();
    }
    return 0;
}