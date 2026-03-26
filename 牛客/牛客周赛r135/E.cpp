#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i ++) {
        cin >> b[i];
    }
    for(int i = 0; i < n; i ++) {
        cin >> c[i];
    }

    i64 ans = 0;
    for(int i = 0; i < n; i ++) {
        if(a[i] == a[i + 1]) {
            int L = 0;
             
        } 
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
