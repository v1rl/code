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
    if(n == 1) {
        cout << "YES" << '\n' << 1 << '\n';
    } else if (n == 3) {
        cout << "YES" << '\n' << 1 << ' ' << 2 << ' ' << 3 << '\n';
    } else {
        cout << "NO" << '\n';
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