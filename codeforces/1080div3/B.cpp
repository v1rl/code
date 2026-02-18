#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<i64, i64> PII;

/*
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n / 2; i += 2) {
        vector<int> v;
        vector<int> vec;
        for(int j = i; j <= n; j *= 2) {
            v.emplace_back(a[j]);
            vec.emplace_back(j);
        }

        sort(v.begin(), v.end());
        int cnt = 0;
        for(auto x : vec) {
            a[x] = v[cnt ++];
        }
    }

    bool ok = true;
    for(int i = 2; i <= n; i ++) {
        ok &= (a[i] > a[i - 1]);
    }

    cout << (ok ? "YES" : "NO") << '\n';
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
