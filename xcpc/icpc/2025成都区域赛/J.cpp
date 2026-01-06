#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
总分小于k
总分+小数-大数大于k
*/

void solve() {
    int n, m, k, b;
    cin >> n >> m >> k >> b;
    vector<int> sum(n);
    vector<int> bg(n), sm(n);
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            int x;
            cin >> x;
            if(x <= 0) {
                sm[i] ++;
            } else {
                bg[i] ++;
            }
            sum[i] += x;
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i ++) {
        if(sum[i] >= k) {
            ans ++;
        } else {
            if(b > 0 && sum[i] + sm[i] - bg[i] >= k) {
                ans ++;
                b --;
            }
        }
    }
    cout << ans << '\n';
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