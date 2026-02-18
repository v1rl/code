#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<int, int> PII;

/*

*/

const int mod = 1e9 + 7;

i64 qmi(i64 a, i64 b) {
    i64 res = 1;
    while(b) {
        if(b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    i64 k;
    cin >> k;

    auto calc = [&](i64 x) -> i64 {
        i64 ans = 3 * x + 1;

        for(i64 i = x / 2; i; i /= 2) {
            ans += i;
        }

        for(i64 y = max(1ll, x - 70); y <= x; y ++) {
            ans += min(0ll, x - y - 1 - __builtin_ctzll(y));
        }
        return ans;
    };

    i64 l = 0, r = 1e18;
    while(l < r) {
        i64 mid = l + r >> 1;
        if(calc(mid) >= k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    i64 x = l;
    if(x) {
        k -= calc(x - 1);
    }

    k --;
    if(k == 0) {
        cout << qmi(10, x) << '\n';
        return;
    }

    k --;
    if(k == 0) {
        cout << (qmi(10, x) + 1) % mod << '\n';
        return;
    }

    for(i64 y = max(1ll, x - 70); y < x; y ++) {
        if(y + __builtin_ctzll(y) + 1 >= x) {
            k --;
            if(k == 0) {
                cout << (qmi(10, x) + qmi(10, y)) % mod << '\n';
                return;
            }
        }
    }
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
