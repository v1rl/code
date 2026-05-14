#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

void solve() {
    auto dfs = [&](auto &&self, int op, int x) {
        if(x <= 0) {
            return false;
        }
        bool ok = true;
        if(!op) {
            ok &= self(self, op ^ 1, x - 1);
            ok &= self(self, op ^ 1, x - 2);
        } else {
            ok &= self(self, op ^ 1, x - 1);
            ok &= self(self, op ^ 1, x - 3);            
        }
        return !ok;
    };

    for(int i = 1; i < 45; i ++) {
        cout << i << ' ';
        if(dfs(dfs, 0, i)) {
            cout << "xiaocheng" << '\n';
        } else {
            cout << "xiaoju" << '\n';
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
