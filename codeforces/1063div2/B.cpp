#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    int l = find(a.begin(), a.end(), 1) - a.begin();
    int r = find(a.begin(), a.end(), n) - a.begin();
    if(l > r) {
        swap(l, r);
    }

    string s;
    cin >> s;
    if(s[0] == '1' || s[n - 1] == '1' || s[l] == '1' || s[r] == '1') {
        cout << -1 << '\n';
        return;
    }

    cout << 5 << '\n';
    l ++, r ++;
    cout << 1 << ' ' << l << '\n';
    cout << 1 << ' ' << r << '\n';
    cout << l << ' ' << r << '\n';
    cout << r << ' ' << n << '\n';
    cout << l << ' ' << n << '\n';
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
