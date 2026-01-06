#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
向上传递时
map合并
将小的合并到最大的那里面去
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++) {
        cin >> b[i];
    }
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    vector<int> siz(n + 1, 1);
    auto dfs1 = [&](auto &&self, int x, int p) -> void {
        for(auto y : adj[x]) {
            if(y == p) {
                continue;
            }
            self(self, y, x);
            siz[x] += siz[y];
        }
    };
    dfs1(dfs1, 1, -1);

    vector<int> num(n + 1);
    vector<int> res(n + 1);
    vector<int> ans(n + 1);
    vector<int> tans(n + 1);
    auto dfs = [&](auto &&self, int x, int p, map<int, int> &mma, map<int, int> &mmb) -> void{
        int mx = -1;
        int t = 0;
        for(auto y : adj[x]) {
            if(y == p) {
                continue;
            }
            if(siz[y] > mx) {
                mx = siz[y];
                t = y;
            }
        }

        if(mx != -1) {
            self(self, t, x, mma, mmb);
            res[x] += res[t];
            num[x] += num[t];
        }

        for(auto y : adj[x]) {
            if(y == p || y == t) {
                continue;
            }
            map<int, int> mpa, mpb;
            self(self, y, x, mpa, mpb);

            for(auto [c, d] : mpa) {
                if(mmb[c] > 0) {
                    int ch = min(mmb[c], d);
                    int th = d - mmb[c];
                    res[x] += ch;
                    mmb[c] -= ch;

                    if(th > 0) {
                        mma[c] += th;
                    }
                } else {
                    mma[c] += d;
                }
            }
            for(auto [c, d] : mpb) {
                if(mma[c] > 0) {
                    int ch = min(mma[c], d);
                    int th = d - mma[c];
                    res[x] += ch;
                    mma[c] -= ch;

                    if(th > 0) {
                        mmb[c] += th;
                    } 
                } else {
                    mmb[c] += d;
                }
            }
            res[x] += res[y];
            num[x] += num[y];
        }


        if(b[x] == 0) {
            num[x] ++;
        } else {
            if(mma[b[x]] > 0) {
                res[x] ++;
                mma[b[x]] --;
            } else {
                mmb[b[x]] ++;
            }
        }
        if(a[x] == 0) {
            num[x] ++;
        } else {
            if(mmb[a[x]] > 0) {
                res[x] ++;
                mmb[a[x]] --;
            } else {
                mma[a[x]] ++;
            }
        }

        ans[x] = res[x] + num[x];
        if(ans[x] >= siz[x]) {
            tans[x] = 1;
        } else {
            tans[x] = 0;
        }
    };

    map<int, int> mpa, mpb;
    dfs(dfs, 1, -1, mpa, mpb);

    for(int i = 1; i <= n; i ++) {
        cout << tans[i];
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