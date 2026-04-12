#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://www.luogu.com.cn/problem/P2602

const int mod = 1e9 + 7;

void solve() {
    i64 l, r;
    cin >> l >> r;
    l --;
    string num1 = to_string(l);
    string num2 = to_string(r);

    /*
    vector<i64> p10(13);
    p10[0] = 1;
    for(int i = 1; i <= 12; i ++) {
        p10[i] = p10[i - 1] * 10;
    }

    auto calc = [&](string num) {
        int m = num.size();
        array<i64, 10> cnt;
        cnt.fill(0);
        for(int i = 0; i <= 9; i ++) {
            for(int j = 0; j < m; j ++) {
                string sl, sr;
                sl = num.substr(0, j), sr = num.substr(j + 1);
                i64 l = 1, r = 1;
                if(sl.size()) {
                    l = stoll(sl);
                    l ++;
                }
                if(sr.size()) {
                    r = stoll(sr);
                    r ++;
                }

                int ch = num[j] - '0';
                if(i != 0) {
                    if(i < ch) {
                        cnt[i] += l * p10[m - j - 1];
                    } else if(i == ch) {
                        cnt[i] += (l - 1) * p10[m - j - 1] + r;
                    } else {
                        cnt[i] += (l - 1) * p10[m - j - 1];
                    }                    
                } else {
                    if(i < ch) {
                        cnt[i] += (l - 1) * p10[m - j - 1];
                    } else if(i == ch) {
                        cnt[i] += (l - 2) * p10[m - j - 1] + r;
                    }
                }
            }
        }
        return cnt;
    };

    auto ans1 = calc(num1);
    auto ans2 = calc(num2);
    for(int i = 0; i < 10; i ++) {
        cout << ans2[i] - ans1[i] << ' ';
    }
    cout << '\n';
    */

    auto calc = [&](string num) {
        int m = num.size();
        array<i64, 10> cnt;
        cnt.fill(0);

        vector f(m, vector(m, (i64)-1));
        auto dfs = [&](auto &&self, int u, int x, int s, bool limit, bool zero) -> i64 {
            if(u == m) {
                return s;
            }
            if(!limit && !zero && f[u][s] != -1) {
                return f[u][s];
            }

            i64 res = 0;
            int up = limit ? num[u] - '0' : 9;
            int stt = 0;
            if(x == 0 && zero) {
                res += self(self, u + 1, x, s, false, true);
                stt ++;
            }

            for(int i = stt; i <= up; i ++) {
                res += self(self, u + 1, x, s + (i == x), limit && i == up, zero && i == 0);
            }

            if(!limit && !zero) {
                f[u][s] = res;
            }
            return res;
        };

        for(int i = 0; i < 10; i ++) {
            cnt[i] = dfs(dfs, 0, i, 0, true, true);
        }
        return cnt;
    };

    auto ans1 = calc(num1);
    auto ans2 = calc(num2);
    for(int i = 0; i < 10; i ++) {
        cout << ans2[i] - ans1[i] << ' ';
    }
    cout << '\n';
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
