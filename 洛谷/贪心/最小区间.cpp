#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://leetcode.cn/problems/smallest-range-covering-elements-from-k-lists/description/

const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> sel(n, inf);

    vector<array<int, 2>> a;
    a.reserve(n * 50);

    for(int i = 0; i < n; i ++) {
        int m;
        cin >> m;
        for(int j = 0; j < m; j ++) {
            int x;
            cin >> x;
            a.push_back({x, i});
        }
    }

    sort(a.begin(), a.end());
    multiset<int> S;
    
    int mn = inf;
    int L = 0, R = 0;
    for(auto [x, id] : a) {
        if(sel[id] != inf) {
            S.erase(S.find(sel[id]));
        }
        sel[id] = x;
        S.insert(x);

        if(S.size() == n) {
            int l = *S.begin(), r = *(-- S.end());
            if(r - l + 1 < mn) {
                mn = r - l + 1;
                L = l, R = r;
            }
        }
    }

    cout << L << ' ' << R << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}