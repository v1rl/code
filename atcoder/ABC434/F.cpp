#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

typedef pair<string, vector<int>> PSV;

vector<int> zFunction(string s) {
    int n = s.size();
    vector<int> z(n);
    for(int i = 1, l = 0, r = 0; i < n; i ++) {
        if(i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }

        while(i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            z[i] ++;
        }

        if(i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

void solve() {
    int n;
    cin >> n;

    vector<PSV> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i].first;
        a[i].second = zFunction(a[i].first);
    }

    sort(a.begin(), a.end(),
        [&](const auto &x, const auto &y) {
            const auto &[sx, zx] = x;
            const auto &[sy, zy] = y;
            int xS = sx.size(), yS = sy.size();
            if(xS >= yS) {
                for(int i = 0; i < yS; i ++) {
                    if(sx[i] != sy[i]) {
                        return sx[i] < sy[i];
                    }
                }

                if(xS != yS && zx[yS] < xS - yS) {
                    return sx[yS + zx[yS]] < sx[zx[yS]];
                }

                int bs = xS - yS;
                for(int i = 0; i < yS; i ++) {
                    if(sy[i] != sx[i + bs]) {
                        return sy[i] < sx[i + bs];
                    }
                }
            } else {
                for(int i = 0; i < xS; i ++) {
                    if(sx[i] != sy[i]) {
                        return sx[i] < sy[i];
                    }
                }

                if(zy[xS] < yS - xS) {
                    return sy[zy[xS]] < sy[xS + zy[xS]];
                }

                int bs = yS - xS;
                for(int i = 0; i < xS; i ++) {
                    if(sx[i] != sy[i + bs]) {
                        return sy[i + bs] < sx[i];
                    }
                }
            }
            return false;
        });

    if(n == 2) {
        cout << a[1].first + a[0].first << '\n';
        return;
    }

    for(int i = 0; i < n - 1; i ++) {
        if(a[i].first + a[i + 1].first == a[i + 1].first + a[i].first) {
            for(auto &x : a) {
                cout << x.first;
            }
            cout << '\n';
            return;
        }
    }

    string ans1, ans2;
    swap(a[n - 1], a[n - 2]);
    for(auto &x : a) {
        ans1 += x.first;
    }
    swap(a[n - 1], a[n - 2]);
    swap(a[n - 2], a[n - 3]);
    for(auto &x : a) {
        ans2 += x.first;
    }

    cout << min(ans1, ans2) << '\n';
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
