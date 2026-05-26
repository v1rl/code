#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = '#' + s;

    auto work = [&](int l, int r, char a, char b) {
        int m = r - l + 1;
        vector<int> pre(m + 1);

        for(int i = l, j = 1; i <= r; i ++, j ++) {
            pre[j] = pre[j - 1];

            if(s[i] == a) {
                pre[j] ++;
            } else if(s[i] == b) {
                pre[j] --;
            }
        }

        i64 ans = 0;
        sort(pre.begin(), pre.end());
        for(int i = 0; i <= m; i ++) {
            ans += 1ll * i * pre[i];
            ans -= 1ll * (m - i) * pre[i];
        }

        return ans;
    };

    i64 res = (work(1, n, 'a', 'b') + work(1, n, 'a', 'c') + work(1, n, 'b', 'c')) / 2;

    auto cal = [&](int len) {
        return 1ll * len * (len + 1) * (len + 2) / 6;
    };

    auto remove = [&](char a, char b, char c) {
        int i = 1;
        for(int j = 1; j <= n; j ++) {
            if(s[j] == c) {
                if(i < j) {
                    res -= (cal(j - i) - work(i, j - 1, a, b)) / 2;
                }
                i = j + 1;
            }
        }
        if(i <= n) {
            res -= (cal(n - i + 1) - work(i, n, a, b)) / 2;
        }
    };

    remove('a', 'b', 'c');
    remove('a', 'c', 'b');
    remove('b', 'c', 'a');

    int cnt = 0;
    for(int i = 1; i <= n; i ++) {
        if(i != 1 && s[i] != s[i - 1]) {
            res -= cal(cnt);
            cnt = 1;
        } else {
            cnt ++;
        }
    }

    res -= cal(cnt);

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;

    while(t --) {
        solve();
    }
    return 0;
}