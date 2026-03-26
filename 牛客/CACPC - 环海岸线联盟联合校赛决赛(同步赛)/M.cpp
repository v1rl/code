#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

const int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    set<int> S;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        if(a[i] == 0) {
            S.insert(i);
        }
    }
    while(m --) {
        int op;
        cin >> op;
        if(op == 1) {
            int pos, x;
            cin >> pos >> x;
            if(a[pos] == x) {
                continue;
            }
            a[pos] = x;

            if(x == 1) {
                S.erase(pos);
            } else {    
                S.insert(pos);
            }
        } else {
            int l, r;
            cin >> l >> r;
            if(l == r) {
                cout << a[l] << '\n';
                continue;
            }

            int pos;
            auto it = S.upper_bound(r);
            if(it == S.begin()) {
                pos = l;
            } else {
                it --;
                pos = *it;
                if(pos < l) {
                    pos = l;
                } else if(pos == l) {
                    pos ++;
                }
            }

            int len = r - pos;
            cout << !(len & 1) << '\n';
        }
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
