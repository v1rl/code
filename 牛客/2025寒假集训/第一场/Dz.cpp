#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), mx(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        mx[i] = max(mx[i - 1], min(n, a[i] + i));
    }

    int K = __lg(n);
    vector jp(n + 1, vector(K + 1, 0));
    for(int i = 1; i <= n; i ++) {
        jp[i][0] = mx[i];
    }

    for(int j = 1; j <= K; j ++) {
        for(int i = 1; i <= n; i ++) {
            jp[i][j] = jp[ jp[i][j - 1] ][j - 1];
        }
    }

    vector<int> ne(n + 2);
    ne[n + 1] = n + 1;
    for(int i = n; i >= 1; i --) {
        ne[i] = (a[i] > 0 ? i : ne[i + 1]);
    }


    auto check = [&](int mid) {
        int r = 1;
        int t = k;
        while(r <= n) {
            r = ne[r];

            if(r > n) {
                return true;
            }

            if(t > 0) {
                t --;
            } else {
                return false;
            }

            for(int j = 0; j <= K; j ++) {
                if(mid >> j & 1) {
                    r = jp[r][j];
                }
            }

            r ++;
        }
        return true;
    };

    int l = 0, r = n;
    while(l < r) {
        int mid = l + r >> 1;
        if(check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << (l == n ? -1 : l) << '\n';
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