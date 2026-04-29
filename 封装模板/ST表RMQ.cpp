#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    vector<int> lg(n + 1);
    for(int i = 2; i <= n; i ++) {
        lg[i] = lg[i >> 1] + 1;
    }
    int K = lg[n] + 1;
    vector stmin(K, vector(n, 0));
    vector stgcd(K, vector(n, 0));
    stmin[0] = stgcd[0] = a;
    for(int i = 1; i < K; i ++) {
        int len = 1 << i;
        int half = len >> 1;
        for(int j = 0; j + len <= n; j ++) {
            stmin[i][j] = min(stmin[i - 1][j], stmin[i - 1][j + half]);
            stgcd[i][j] = gcd(stgcd[i - 1][j], stgcd[i - 1][j + half]);
        }
    }

    auto queryMin = [&](int l, int r) {
        int i = lg[r - l + 1];
        l --, r --;
        return min(stmin[i][l], stmin[i][r - (1 << i) + 1]);
    };
    auto queryGcd = [&](int l, int r) {
        int i = lg[r - l + 1];
        l --, r --;
        return gcd(stgcd[i][l], stgcd[i][r - (1 << i) + 1]);
    };

    while(q --) {
        int l, r;
        cin >> l >> r;
        if(l == r) {
            cout << 0 << '\n';
            continue;
        }
        cout << queryMin(l, r) << ' ' << queryGcd(l, r) << '\n';
    }
}