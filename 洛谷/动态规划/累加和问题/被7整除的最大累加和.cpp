#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

/*
给定一个非负数组nums，
可以任意选择数字组成子序列，但是子序列的累加和必须被7整除
*/

const int inf = 1e9;

int Mod(int x, int mod) {
    x %= mod;
    if(x < 0) {
        x += mod;
    }
    return x;
}

int solve1(vector<int> &a) {
    int n = a.size();

    vector<array<int, 7>> f(n);
    for(int i = 0; i < n; i ++) {
        f[i].fill(-inf);
    }

    int mx = -inf;
    f[0][Mod(a[0], 7)] = a[0];
    mx = max(mx, f[0][0]);
    for(int i = 1; i < n; i ++) {
        int cur = Mod(a[i], 7);
        f[i][cur] = max(f[i - 1][0] + a[i], a[i]);

        for(int j = 1; j < 7; j ++) {
            int nj = (cur + j) % 7;
            f[i][nj] = f[i - 1][j] + a[i];
        }

        mx = max(mx, f[i][0]);
    }

    if(mx < -inf / 2) {
        return -inf;
    } else {
        return mx;
    }
}

int solve2(vector<int> &a) {
    int n = a.size();

    int mx = -inf;
    for(int i = 0; i < n; i ++) {
        int s = 0;
        for(int j = i; j < n; j ++) {
            s += a[j];
            if(s % 7 == 0) {
                mx = max(mx, s);
            }
        }
    }
    return mx;
}

void checker() {
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    for(int i = 0; i < 100; i ++) {
        int n = rng() % 1000 + 1;
        vector<int> a(n);
        for(int j = 0; j < n; j ++) {
            a[j] = rng() % 1000 - 500;
        }
        int ans1 = solve1(a), ans2 = solve2(a);
        if(ans1 != ans2) {
            cout << "WA ON TEST" << ' ' << i + 1 << '\n';
            return;
        }
    }
    cout << "Accepted!";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t --) {
        checker();
    }

    return 0;
}
