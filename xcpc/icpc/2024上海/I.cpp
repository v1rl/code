#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

const int inf = 1e9, mod = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater());

    bool f = true;
    i64 ans = 1;
    for(int i = 0; i < k; i ++) {
        if(a[i] == 0) {
            f = false;
            break;
        }
        ans *= a[i];
        ans %= mod;
    }
    if(!f) {
        cout << a[0] % mod << '\n';
        return;
    }

    int l = k;
    while(l + k - 1 <= n) {
        int r = l + k - 1;
        i64 res = 1;
        bool f = true;
        for(int i = l; i < r; i ++) {
            if(a[i] == 0) {
                f = false;
                break;
            }
            res *= a[i];
            res %= mod;
        }
        if(f) {
            ans *= res;
            ans %= mod;
        } else {
            break;
        }
        l = r;
    }
   
    cout << ans % mod << '\n';
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