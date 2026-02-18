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
    vector g = {
        "1110111",
        "0010010",
        "1011101",
        "1011011",
        "0111010",
        "1101011",
        "1101111",
        "1010010",
        "1111111",
        "1111011"
    };

    for(int i = 0; i < 10; i ++) {
        for(int j = 0; j < 7; j ++) {
            if(g[i][j] == '0') {
                light[i] *= n[j + 1];
            } else {
                light[i] *= y[j + 1];
            }
            light[i] %= mod;
        }
    }
    

    i64 ans = 0;
    for(int i = 0; i <= m; i ++) {
        i64 res = 1;
        int j = m - i;

        int x = i, y = j;
        for(int i = 0; i < 4; i ++) {
            res = res * light[x % 10] % mod;
            res = res * light[y % 10] % mod;
            x /= 10;
            y /= 10;
        }
        ans = (ans + res) % mod;
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
