#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

/*
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    a[n] = n;
    for(int i = n - 1; i >= 1; i --) {
        if((n - i) & 1) {
            a[i] = a[i + 1] - i;
        } else {
            a[i] = a[i + 1] + i;
        }
    } 

    for(int i = 1; i <= n; i ++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
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