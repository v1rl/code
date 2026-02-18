#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/

const int inf = 1e9 + 10;
const int mod = 998244353;


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
    int m;
    cin >> m;
    vector<int> p(8);
    vector<int> y(8), n(8);
    i64 inv = qmi(100, mod - 2);
    for(int i = 1; i <= 7; i ++) {
        cin >> p[i];
        y[i] = p[i] * inv % mod;
        n[i] = (100 - p[i]) * inv % mod;
    }

    vector<i64> light(10, 1);
    for(auto i : {2, 5, 3, 6}) {
        light[0] *= y[i];
        light[0] %= mod;
    }
    for(auto i : {1, 4, 7}) {
        light[0] *= n[i];
        light[0] %= mod;
    }

    for(auto i : {3, 6}) {
        light[1] *= y[i];
        light[1] %= mod;
    }
    for(auto i : {1, 2, 4, 5, 7}) {
        light[1] *= n[i];
        light[1] %= mod;
    }

    for(auto i : {1, 3, 4, 5, 7}) {
        light[2] *= y[i];
        light[2] %= mod;
    }
    for(auto i : {2, 6}) {
        light[2] *= n[i];
        light[2] %= mod;
    }

    for(auto i : {1, 3, 4, 6, 7}) {
        light[3] *= y[i];
        light[3] %= mod;
    }
    for(auto i : {2, 5}) {
        light[3] *= n[i];
        light[3] %= mod;
    }

    for(auto i : {2, 3, 4, 6}) {
        light[4] *= y[i];
        light[4] %= mod;
    }
    for(auto i : {1, 5, 7}) {
        light[4] *= n[i];
        light[4] %= mod;
    }

    for(auto i : {1, 2, 4, 6, 7}) {
        light[5] *= y[i];
        light[5] %= mod;
    }
    for(auto i : {3, 5}) {
        light[5] *= n[i];
        light[5] %= mod;
    }

    for(auto i : {1, 2, 4, 5, 6, 7}) {
        light[6] *= y[i];
        light[6] %= mod;
    }
    for(auto i : {3}) {
        light[6] *= n[i];
        light[6] %= mod;
    }

    for(auto i : {1, 3, 6}) {
        light[7] *= y[i];
        light[7] %= mod;
    }
    for(auto i : {2, 4, 5, 7}) {
        light[7] *= n[i];
        light[7] %= mod;
    }

    for(auto i : {1, 2, 3, 4, 5, 6, 7}) {
        light[8] *= y[i];
        light[8] %= mod;
    }

    for(auto i : {1, 2, 3, 4, 6, 7}) {
        light[9] *= y[i];
        light[9] %= mod;
    }
    for(auto i : {5}) {
        light[9] *= n[i];
        light[9] %= mod;
    }

    i64 ans = 1;
    for(int i = 0; i <= m; i ++) {
        i64 res = 1;
        int j = m - i;
        int x = i, y = j;
        while(x) {
            res = (res * light[x % 10]) % mod;
            x /= 10;
        }
        while(y) {
            res = (res * light[y % 10]) % mod;
            y /= 10;            
        }
        ans = (ans * res) % mod;
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