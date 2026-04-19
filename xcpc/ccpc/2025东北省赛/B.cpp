#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int inf = 1e9;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    auto smax = a;
    vector<int> vis(n);
    vector<int> ysmax;
    vector<int> nsmax;
    ysmax.emplace_back(n - 1);

    for(int i = n - 2; i >= 0; i --) {
        smax[i] = max(smax[i + 1], smax[i]);
        if(smax[i] != smax[i + 1]) {
            ysmax.emplace_back(i);
        } else {
            nsmax.emplace_back(i);
        }
    }

    int m = nsmax.size();

    vector<int> ans;
    reverse(ysmax.begin(), ysmax.end());

    auto getAns = [&]() {
        for(int i = 0; i < n; i ++) {
            if(!vis[i]) {
                ans.emplace_back(a[i]);
            }
        }
    };

    for(int i = 0, j = k; i < m && j > 0; i ++, j --) {
        vis[nsmax[i]] = true;
    }

    if(k <= m) {
        getAns();
    } else if(m + (k - m) / 2 >= n - 1) {
        ans.emplace_back(smax[0]);
    } else {
        int t = k - m;

        int cur = 1, j = t / 2;
        for(; cur < ysmax.size() && j > 0; cur ++, j --) {
            vis[ysmax[cur]] = true;
        }

        if(t & 1) {
            if(nsmax.size()) {
                vector<int> res1;
                getAns();
                swap(ans[0], ans[1]);  
                res1 = ans;

                ans.clear();

                vector<int> res2;
                vis[nsmax[m - 1]] = false;
                vis[ysmax[cur]] = true;
                getAns();
                res2 = ans;

                ans = min(res1, res2);
            } else {
                getAns();
                swap(ans[0], ans[1]);    
            }
        } else {
            getAns();
        }
    }

    cout << ans.size() << '\n';
    for(auto c : ans) {
        cout << c << ' ';
    }
    cout << '\n';
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