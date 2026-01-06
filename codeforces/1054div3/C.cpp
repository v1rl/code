#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;
/*
小于的数不存在，就要考虑变
大于等于的数存在，也要考虑变
*/

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> st(n + 1);
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        st[x] ++;
    }
    int res = 0;
    for(int i = 0; i <= k - 1; i ++) {
        if(!st[i]) {
            res ++;
        }
    }
    cout << max(res, st[k]) << '\n';
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