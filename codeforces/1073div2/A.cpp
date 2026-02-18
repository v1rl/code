#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool f = true;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        if(i > 0) {
            if(a[i] % 2 == a[i - 1] % 2) {
                f = false;
            }
        }
    }
    cout << (f ? "YES" : "NO") << '\n';
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

