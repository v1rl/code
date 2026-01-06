#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    cin >> n;
    int res = 1ll * n * (n + 1) / 2;
    int a = 1, b = 1;
    for(int i = 2; i * i <= res; i ++) {
        if(res % i == 0) {
            a = i;
            b = res / i;
        }
    }
    cout << a * 2 + b * 2 << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
}