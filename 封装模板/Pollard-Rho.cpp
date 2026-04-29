#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
const int mod = 998244353;
i64 ans = 0;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

i64 qmi(i128 a, i64 b, i64 mod) {
    i64 res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

i64 Pollard_Rho(i64 x) {
    i64 s = 0, t = 0;
    i64 c = rng() % (x - 1) + 1;
    i64 step = 0, goal = 1;
    i64 val = 1;
    for(goal = 1; ; goal <<= 1, s = t, val = 1) {
    for(step = 1; step <= goal; step ++) {        
        t = ((i128)t * t % x + c) % x;
        val = (i128)val * abs(t - s) % x;
        if ((step % 127) == 0) {
        i64 d = gcd(val, x);
        if (d > 1) return d;
        }
    }
    i64 d = gcd(val, x);
    if (d > 1) return d;
    }
}

bool millerRabin(i64 n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    i64 d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d /= 2;
        s ++;
    }

    for (auto a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (a >= n) continue;
        i64 x = qmi(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool f = true;
        for (int i = 0; i < s - 1; ++i) {
            x = (i128)x * x % n;
            if (x == n - 1) {
                f = false;
                break;
            }
        }
        if (f) return false;
    }
    return true;
}

void work(i64 n, auto &ans) {
    if(n <= 1) return;
    if(millerRabin(n)) {
        ans.emplace_back(n);
        return;
    }
    i64 x = n;
    while(x == n) {
        x = Pollard_Rho(n);
    }
    work(x, ans), work(n / x, ans);
}

void solve() {
    i64 a;
    cin >> a;
    vector<i64> ans;
    work(a, ans);
    int n = ans.size();
    if(n <= 2) {
        cout << "No" << '\n';
    } else {
        cout << (n % 2 == 1 ? "Yes" : "No") << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
}