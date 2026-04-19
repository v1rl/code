#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int inf = 1e9;
const int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    vector<int> l(n, -1), r(n, n);
    vector<int> stk;
    for(int i = 0; i < n; i ++) {
        while(!stk.empty() && a[stk.back()] <= a[i]) {
            stk.pop_back();
        }
        if(!stk.empty()) {
            l[i] = stk.back();
        }
        stk.push_back(i);
    }    
    stk.clear();
    for(int i = n - 1; i >= 0; i --) {
        while(!stk.empty() && a[stk.back()] < a[i]) {
            stk.pop_back();
        }
        if(!stk.empty()) {
            r[i] = stk.back();
        }
        stk.push_back(i);
    }

    auto calc = [&](int a, int b, int x, int y) {
        if(a > x + y - 1) {
            return 0;
        }

        auto g = [&](int k) -> int {
            if(k >= 1 && k <= x) {
                return k;
            } else if(k > x && k <= y) {
                return x;
            } else if(k > y && k <= x + y - 1) {
                return x + y - k;
            }
            return 0;
        };

        auto get = [&](int l, int r) -> int {
            if(l > r) {
                return 0;
            }
            int L = g(l);
            int R = g(r);
            return 1ll * (L + R) * (r - l + 1) / 2 % mod;
        };

        int res = 0;
        res = (res + get(max(1, a), min(x, b))) % mod;
        res = (res + get(max(x + 1, a), min(y, b))) % mod;
        res = (res + get(max(y + 1, a), min(x + y - 1, b))) % mod;
        return res;
    };

    int ans = 0;
    for(int i = 0; i < n; i ++) {
        int cl = l[i], cr = r[i];
        int x = i - cl, y = cr - i;
        if(x > y) {
            swap(x, y);
        }
        for(int l = 1, d = 1; l <= n; l *= 10, d ++) {
            int r = min(n, l * 10 - 1);
            ans = (ans + 1ll * calc(l, r, x, y) * a[i] % mod * d % mod) % mod;
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
