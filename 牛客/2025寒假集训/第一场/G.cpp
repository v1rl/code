#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

i64 get(i64 x) {
    string s = to_string(x);
    while(!s.empty() && s.back() == '0') {
        s.pop_back();
    }
    reverse(s.begin(), s.end());
    return stoll(s);
}

void solve() {
    i64 l, r;
    cin >> l >> r;
    i64 ans = get(r);

    if(l == r) {
        cout << ans << '\n';
        return;
    }

    i64 p = 1;
    while(r / p != 0) {
        p *= 10;
    }
    p /= 10;
    if(r == p) {
        cout << r - 1 << '\n';
        return;
    }

    l = max(l, p);
    p = 1;
    while(l / p != r / p) {
        p *= 10;
    }
    p /= 10;

    ans = max(ans, get(r / p * p - 1));
    cout << ans << '\n';
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