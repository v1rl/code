#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/

const int inf = 1e9 + 10;
const int mod = 998244353;

void solve() {
    int n;
    cin >> n;

    vector<int> a(1 << n);
    iota(a.begin(), a.end(), 0);

    vector<int> p2(n + 1);
    p2[0] = 1;
    for(int i = 1; i <= n; i ++) {
        p2[i] = p2[i - 1] * 2;
    }

    auto calc = [&](auto &&self, int k, int pre) -> void {
        if(k == -1) {
            return;
        }
        self(self, k - 1, pre + p2[k]);
        self(self, k - 1, pre);
        reverse(a.begin() + pre, a.begin() + pre + p2[k]);
    };

    calc(calc, n - 1, 0);

    for(int i = 0; i < (1 << n); i ++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
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
