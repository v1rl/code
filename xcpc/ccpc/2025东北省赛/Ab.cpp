#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector<int> lg(n + 1);
    for(int i = 2; i <= n; i ++) {
        lg[i] = lg[i >> 1] + 1;
    }
    int K = lg[n] + 1;

    vector stmin(K, vector(n + 1, 0));
    vector stgcd(K, vector(n + 1, 0));
    stmin[0] = stgcd[0] = a;

    for(int i = 1; i < K; i ++) {
        int len = 1 << i;
        int half = len >> 1;
        for(int j = 1; j + len - 1 <= n; j ++) {
            stmin[i][j] = min(stmin[i - 1][j], stmin[i - 1][j + half]);
            stgcd[i][j] = gcd(stgcd[i - 1][j], stgcd[i - 1][j + half]);
        }
    }

    auto queryMin = [&](int l, int r) {
        int i = lg[r - l + 1];
        return min(stmin[i][l], stmin[i][r - (1 << i) + 1]);
    };
    auto queryGcd = [&](int l, int r) {
        int i = lg[r - l + 1];
        return gcd(stgcd[i][l], stgcd[i][r - (1 << i) + 1]);
    };

    auto get1 = [&](int stt, int l, int r, int tar) {
        while(l < r) {
            int mid = l + r + 1 >> 1;
            if(queryGcd(stt, mid) == tar) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    };
    auto get2 = [&](int stt, int l, int r, int tar) {
        while(l < r) {
            int mid = l + r >> 1;
            if(queryMin(stt, mid) <= tar) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };

    i64 ans = 0;
    for(int x = 1; x <= n; x ++) {
        int y = x;
        while(y <= n) {
            int tar = queryGcd(x, y);
            int pos1 = get1(x, y, n, tar);
            int pos2 = get2(x, y, pos1 + 1, tar);
            int d = max(0, pos1 - pos2 + 1);
            ans += d;
            y = pos1 + 1;
        }
    }
    cout << ans << '\n';
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
