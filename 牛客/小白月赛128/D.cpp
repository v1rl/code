#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
typedef pair<int, int> PII;
const int inf = 1e9;

/*

*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i][0];
        a[i][1] = i;
    }


    vector<i64> ans(n);
    sort(a.begin(), a.end());
    vector<i64> suf(n + 2, 0);
    for(int i = n; i >= 1; i --) {
        suf[i] = suf[i + 1] + a[i - 1][0];
    }

    for(int i = 0; i < n; i ++) {
        array<int, 2> t = {m - a[i][0], inf};
        int pos = upper_bound(a.begin(), a.end(), t) - a.begin();
        int L = pos, R = n - pos;
        if(i < L) {
            L --;
        } else {
            L ++;
        }

        ans[a[i][1]] = 1ll * L * a[i][0] - suf[n - R + 1];
    }

    for(auto c : ans) {
        cout << c << ' ';
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