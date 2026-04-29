#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    int t = sqrtl(n);
    if(t * t == n) {
        string s1 = to_string(n);
        string s2 = to_string(t);
        bool ok1 = true, ok2 = true;
        for(int i = 0, j = s1.size() - 1; i < j; i ++, j --) {
            ok1 &= s1[i] == s1[j];
        }
        for(int i = 0, j = s2.size() - 1; i < j; i ++, j --) {
            ok2 &= s2[i] == s2[j];
        }
        if(ok1 && ok2) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    } else {
        cout << "NO" << '\n';
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
