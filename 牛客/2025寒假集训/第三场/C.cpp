#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*

*/

const int mod = 998244353;
const int inf = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = string(n, '1');
    string res1 = t, res2 = t;
    for(int i = 0; i < n; i += 2) {
        res1[i] = '0';
    }
    for(int i = 1; i < n; i += 2) {
        res2[i] = '0';
    }

    // cout << res1 << ' ' << res2 << '\n';

    auto work = [&](string res) -> int {
        string nd;
        for(int i = 0; i < n; i ++) {
            if(s[i] != res[i]) {
                nd += s[i];
            }
        }

        int f[2] = {0, 0};
        for(auto c : nd) {
            if(c == '1') {
                if(f[0]) {
                    f[0] --;
                    f[1] ++;
                } else {
                    f[1] ++;
                }
            } else {
                if(f[1]) {
                    f[0] ++;
                    f[1] --;
                } else {
                    f[0] ++;
                }
            }
        }

        return f[0] + f[1];
    };


    cout << min(work(res1), work(res2)) << '\n';
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