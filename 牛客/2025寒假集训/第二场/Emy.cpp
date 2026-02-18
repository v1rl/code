#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/

const int mod = 998244353;
const int inf = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector g(n + 1, vector(n + 1, 0));
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n - i; j ++) {
            g[i][j] = 1;
        }
    }

    vector ans = g;
    for(int i = 1, l = 1, r = n; l <= r; i ++) {
        if(i & 1) {
            ans[i] = g[l];
            l ++;
        } else {
            ans[i] = g[r];
            r --;
        }
    }

    for(int i = 1, l = 1, r = n; i <= (n + 1) / 2; l ++, r -= 2, i ++) {
        for(int i = 1; i <= n; i ++) {
            swap(ans[i][l], ans[i][r]);
        }
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            cout << ans[i][j];
            if(j == n)cout << '\n';
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