#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<i64, i64> PII;

/*
*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= n; i ++) {
        int x, y;
        cin >> x >> y;
        if(x) {
            adj[i].emplace_back(x);
            adj[i].emplace_back(y);
        }
    }

    vector<int> siz(n + 1, 1);
    vector<int> dep(n + 1, 0);

    vector v(n + 1, vector(20, 0ll));
    vector f(n + 1, vector(20, 0));
    vector sl(n + 1, vector(20, 0));
    vector sr(n + 1, vector(20, 0));

    auto init = [&](auto &&self, int x) -> void {
        // cerr << 'h';
        for(auto y : adj[x]) {
            // cerr << 'g';
            dep[y] = dep[x] + 1;
            self(self, y);
            siz[x] += siz[y];
        }
    };

    init(init, 1);


    for(int i = 0; i < 20; i ++) {
        v[1][i] = (siz[1] - 1) * 2 + 1;
        f[1][i] = 0;
    }

    vector<int> ls(n + 1);
    // vector<i64> pls(n + 1);
    auto dfs = [&](auto &&self, int x) -> void {
        ls[x] = x;
        for(auto y : adj[x]) {

            f[y][0] = x;
            v[y][0] = (siz[y] - 1) * 2 + 1;
            for(int i = 1; i < 20; i ++) {
                f[y][i] = f[f[y][i - 1]][i - 1];
                v[y][i] = v[y][i - 1] + v[f[y][i - 1]][i - 1];
            }

            self(self, y);
            if(ls[x] == x) {
                ls[x] = ls[y];
            }

            // if(!pls[x]) {
            //     pls[x] = pls[y] + (siz[x] - 1) * 2 + 1;
            // }

            if(!sl[x][0]) {
                sl[x][0] = y;
                for(int i = 1; i < 20; i ++) {
                    sl[x][i] = sl[sl[x][i - 1]][i - 1];
                }                
            } else {
                sr[x][0] = y;
                for(int i = 1; i < 20; i ++) {
                    sr[x][i] = sr[sr[x][i - 1]][i - 1];
                } 
            }
        }
    };

    dfs(dfs, 1);

    // cout << v[4][0] << '\n'; 
    // cout << dep[4] << ' ' << dep[3] << '\n';

    // cout << v[1][0] << '\n';
    // cout << v[3][1] << '\n';

    // cerr << v[1][0] << '\n';
    // cerr << v[1][0] << '\n';
    // cerr << v[3][1] << '\n';
    // cerr << f[3][0] << '\n';
    // cerr << pls[2] << '\n';


    while(m --) {
        int x, k;
        cin >> x >> k;

        // cerr << 'h';

        for(int i = 19; i >= 0; i --) {
            int y = f[x][i];
            i64 val = v[x][i];
            // cerr << y << ' ' << val << ' ' << i << '\n';
            if(k >= val) {
                k -= val;
                x = y;
                // cerr << x << ' ' << 'h' << ' ' << i << '\n';
            }
        }

        // cerr << x << ' ' << k << '\n';


        while(k) {
            int l = 0, r = dep[ls[x]] - dep[x];

            auto check = [&](int mid) {
                int p = x;
                for(int i = 19; i >= 0; i --) {
                    if(mid >> i & 1) {
                        p = sl[p][i];
                    }
                }
                return (siz[p] - 1) * 2 + dep[p] - dep[x] >= k;
            };

            while(l < r) {
                int mid = l + r + 1 >> 1;
                if(check(mid)) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }

            // cerr << l << ' ' << x << ' ' << k << '\n';

            if(k <= dep[ls[x]] - dep[x]) {
                // cerr << 'h';
                for(int i = 19; i >= 0; i --) {
                    if(k >> i & 1) {
                        x = sl[x][i];
                    }
                }
                break;
            } else {
                int t = x;
                for(int i = 19; i >= 0; i --) {
                    if(l >> i & 1) {
                        x = sl[x][i];
                    }
                }

                if(k == (siz[x] - 1) * 2 + dep[x] - dep[t]) {
                    break;
                }

                k -= (siz[adj[x][0]] - 1) * 2 + 2 + dep[x] - dep[t];
                if(k) {
                    x = adj[x][1];
                    k --;
                }
            }



        }

        cout << x << ' ';
    }
    cout << '\n';

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
