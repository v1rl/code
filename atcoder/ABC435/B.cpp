#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int l = 0; l < n - 1; l ++) {
        for(int r = l + 1; r < n; r ++) {
            int sum = 0;
            for(int i = l; i <= r; i ++) {
                sum += a[i];
            }
            bool f = true;
            for(int i = l; i <= r; i ++) {
                if(sum / a[i] * a[i] == sum) {
                    f = false;
                    break;
                }
            }
            if(f) {
                ans ++;
            }
        }
    }
    cout << ans << '\n';
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
