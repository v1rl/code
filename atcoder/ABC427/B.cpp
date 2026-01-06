#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    a[0] = 1;
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j < i; j ++) {
            i64 res = 0;
            int x = a[j];
            while(x) {
                res += (x % 10);
                x /= 10;
            }
            a[i] += res;
        }
    }
    cout << a[n] << '\n';
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
