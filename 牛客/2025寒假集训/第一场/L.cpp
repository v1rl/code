#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/

const int inf = 1e9 + 10;

void solve() {
    int n;
    cin >> n;
    if(n % 10 == 0) {
        cout << 1 << '\n';
    } else {
        cout << 10 / (gcd(10, n % 10)) << '\n';
    }

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