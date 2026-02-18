#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
*/
const int inf = 1e9 + 10;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    map<int, int> mp;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            int x;
            cin >> x;
            if(x > 0) {
                mp[x] ++;

            }
        }
    }

    int a = 0, b = 0;
    for(auto [x, t] : mp) {
        if(t / 2) {
            a += t / 2;
            mp[x + 1] += t / 2;
            if(x >= k - 1) {
                b += t / 2;
            }            
        }
    }

    cout << a << ' ' << b << '\n';
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