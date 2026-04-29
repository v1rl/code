#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

void solve() {
    double atk, t, d, p;
    cin >> atk >> t >> d >> p;
    int n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;

    for(int i = 0; i < n1; i ++) {
        double x;
        cin >> x;
        atk += x;
    }

    double sum = 0;
    for(int i = 0; i < n2; i ++) {
        double x;
        cin >> x;
        sum += x;
    }
    atk = (1 + sum) * atk;

    for(int i = 0; i < n3; i ++) {
        double x;
        cin >> x;
        atk += x;
    }

    for(int i = 0; i < n4; i ++) {
        double x;
        cin >> x;
        atk *= x;
    }

    double f;
    cin >> f;
    atk = max(0.05 * atk, atk - f);


    cout << fixed << setprecision(2);
    cout << (int)(t / d) * p * atk << '\n';
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
