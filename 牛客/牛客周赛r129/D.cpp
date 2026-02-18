#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
*/
const int inf = 1e9 + 10;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n + 1);
    for(int i = n - 1; i >= 1; i --) {
        a[i] = a[i + 1] + (s[i - 1] == s[i]);
    }

    i64 res = 0;
    for(int i = 1; i < n; i ++) {
        if(s[i] == s[i - 1]) {
            res += n - i - 1 - a[i + 1];
        } else {
            res += a[i + 1];
        }
    }

    cout << res + 1 << '\n';

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