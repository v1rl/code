#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://leetcode.cn/problems/jian-sheng-zi-ii-lcof/description/

const int mod = 1e9 + 7;

i64 qmi(i64 a, i64 b) {
    i64 res = 1;
    while(b) {
        if(b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    if(n == 2) {
        cout << 1 << '\n';
    } else if(n == 3) {
        cout << 2 << '\n';
    }
    int lst = n % 3;
    int d = n / 3;
    if(lst == 0) {
        cout << qmi(3, d) << '\n';
    } else if(lst == 1) {
        cout << qmi(3, d - 1) * 4 % mod << '\n';
    } else {
        cout << qmi(3, d) * 2 % mod << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}