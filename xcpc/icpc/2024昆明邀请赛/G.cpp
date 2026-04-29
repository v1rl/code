#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const i64 inf = 1e18;

void solve() {
    int n;
    cin >> n;
    if(n == 1 || n % 4 == 0) {
        cout << "impossible" << '\n';
    } else {
        vector<int> a(n);
        iota(a.begin(), a.end(), 0);
        swap(a[0], a[1]);
        for(int i = 4; i < n; i += 4) {
            swap(a[i], a[i - 1]);
        }
        for(auto c : a) {
            cout << c << ' ';
        }
        cout << '\n';
    }
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
