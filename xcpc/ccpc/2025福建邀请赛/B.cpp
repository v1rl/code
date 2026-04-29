#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int inf = 1e9 + 10;

void solve() {
    int n, p;
    cin >> n >> p;

    vector<i64> d1(n + 2);
    vector<i64> d3(n + 2);
    vector<i64> d(n + 2);

    for(int g = 0; g * 8 <= n; g ++) {
        int smax = min((n - 8 * g) / 4, n - 4 * g - p);
        if(smax < 0) {
            continue;
        }
        int k = smax + 1;
        int lmin = (n + 1) / 2 - 3 * g - smax;
        int rmin = n - 7 * g - 3 * smax;

        d1[lmin] += 1;
        d1[min(lmin + k, n + 1)] -= 1;

        d3[rmin + 1] -= 1;
        d3[min(rmin + 3 * k + 1, n + 1)] += 1;
    }

    for(int i = 1; i <= n; i ++) {
        d1[i] += d1[i - 1];
    }
    for(int i = 3; i <= n; i ++) {
        d3[i] += d3[i - 3];
    }
    for(int i = 0; i <= n; i ++) {
        d[i] = d1[i] + d3[i];
    }
    for(int i = 1; i <= n; i ++) {
        d[i] += d[i - 1];
    }

    for(int i = 1; i <= n; i ++) {
        cout << d[i] << ' ';
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
