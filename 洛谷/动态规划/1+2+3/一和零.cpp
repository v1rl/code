#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/ones-and-zeroes/description/

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> n0(n + 1), n1(n + 1);
    for(int i = 1; i <= n; i ++) {
        string s;
        cin >> s;
        for(auto c : s) {
            if(c == '0') {
                n0[i] ++;
            } else {
                n1[i] ++;
            }
        }
    }

    int m0, m1;
    cin >> m0 >> m1;

    vector f(m0 + 1, vector(m1 + 1, 0));
    for(int i = 1; i <= n; i ++) {
        for(int j = m0; j >= 0; j --) {
            for(int k = m1; k >= 0; k --) {
                if(j - n0[i] >= 0 && k - n1[i] >= 0) {
                    f[j][k] = max(f[j][k], f[j - n0[i]][k - n1[i]] + 1);
                }
            }
        }
    }

    cout << f[m0][m1] << '\n';
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
