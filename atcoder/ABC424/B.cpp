#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
*/

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> s(n + 1);
    int bs = (1 << m) - 1;
    while(k --) {
        int a, b;
        cin >> a >> b;
        s[a] |= (1 << (b - 1));
        if(s[a] == bs) {
            cout << a << ' ';
        }
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