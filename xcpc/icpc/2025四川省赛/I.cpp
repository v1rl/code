#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

const u64 mod = (1ULL << 61) - 1;
const u64 base = 13331;

u64 mul(u64 a, u64 b) {
    u128 c = (u128)a * b;
    u64 res = (u64)(c >> 61) + (u64)(c & mod);
    if(res >= mod) {
        res -= mod;
    }
    return res;
}

u64 add(u64 a, u64 b) {
    a += b;
    if(a >= mod) {
        a -= mod;
    }
    return a;
}

void solve() {
    int n;
    cin >> n;
    set<u64> S;

    for(int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());

        int m = s.size();
        s = '#' + s;
        vector<u64> p(m + 1);
        for(int i = 1; i <= m; i ++) {
            p[i] = add(mul(p[i - 1], base), s[i]);
            S.insert(p[i]);
        }
    }

    cout << S.size();
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