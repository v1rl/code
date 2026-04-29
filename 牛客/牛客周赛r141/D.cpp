#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(32);
    vector<int> a(n);
    multiset<int> S;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        if(a[i] < 32) {
            cnt[a[i]] ++;
        }
        S.insert(a[i]);
    }

    if(cnt[1] >= 2) {
        cout << "YES" << '\n';
        return;
    }

    for(int i = 0; i < n; i ++) {
        if(a[i] == 1) {
            continue;
        }
        if(cnt[1] && S.count(a[i]) >= 2) {
            cout << "YES" << '\n';
            return;
        }
        for(int j = 2; j < 32; j ++) {
            if(cnt[j] == 0) {
                continue;
            }
            i64 x = a[i];
            i64 p = pow(x, j);
            if(p > inf) {
                break;
            }
            if(S.count(p)) {
                cout << "YES" << '\n';
                return;
            }
        }
    }

    cout << "NO" << '\n';

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
