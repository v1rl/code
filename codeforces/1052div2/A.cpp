#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

void solve() {
    int n;
    cin >> n;
    vector<int> st(n + 1);
    int cnt = 0;
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        st[x] ++;
    }

    int mx = 0;
    for(int x = 1; x <= n; x ++) {
        int res = 0;
        for(int i = 1; i <= n; i ++) {
            if(st[i] < x) {
                continue;
            }
            res += min(st[i], x);
        }
        mx = max(mx, res);
    }

    cout << mx << '\n';


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