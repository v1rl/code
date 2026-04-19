#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using i128 = __int128;

const int mod = 998244353;
void chadd(int &x, int y) {
    x = (x + y) % mod;
    if(x < 0) {
        x += mod;
    }
}

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
    vector<int> card(14, 4);
    auto get = [&](string s) {
        if(s[0] == 'A') {
            return 1;
        } else if(s[0] == 'J') {
            return 11;
        } else if(s[0] == 'Q') {
            return 12;
        } else if(s[0] == 'K') {
            return 13;
        }
        return stoi(s);
    };

    vector<int> a(5);
    for(int i = 0; i < 5; i ++) {
        string s;
        cin >> s;
        a[i] = get(s);
        card[get(s)] --;
    }

    vector<int> v;
    for(int i = 1; i <= 13; i ++) {
        while(card[i] --) {
            v.emplace_back(i);
        }
    }

    int n = v.size();
    vector f(6, vector(65, vector(6, vector(65, 0))));
    f[0][0][0][0] = 1;

    for(int i = 0; i < n; i ++) {
        for(int k = 5; k >= 0; k --) {
            for(int x = 64; x >= 0; x --) {
                for(int j = 5; j >= 0; j --) {
                    for(int y = 64; y >= 0; y --) {
                        int lx = x - v[i];
                        if(lx >= 0 && k > 0) {
                            chadd(f[k][x][j][y], f[k - 1][lx][j][y]);
                        }
                        int ly = y - v[i];
                        if(ly >= 0 && j > 0) {
                            chadd(f[k][x][j][y], f[k][x][j - 1][ly]);
                        }
                    }
                }
            }
        }
    }

    sort(a.begin(), a.end());
    int sum = accumulate(a.begin(), a.end(), 0);
    for(int k = 1; k <= 5; k ++) {
        sum -= a[k - 1];
        int ans = 0;
        int bs = 0;
        for(int x = 64; x >= 0; x --) {
            for(int y = 64; y >= 0; y --) {
                bs = (bs + f[k][x][5][y]) % mod;
            }
        }
        bs = qmi(bs, mod - 2);

        for(int x = 0; x <= 64; x ++) {
            for(int y = 0; y <= 64; y ++) {
                if(sum + x > y) {
                    chadd(ans, 1ll * bs * f[k][x][5][y] % mod * k % mod);
                } else if(sum + x < y) {
                    chadd(ans, 1ll * bs * f[k][x][5][y] % mod * -k % mod);
                }
            }
        }

        cout << ans << '\n';
    }
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
