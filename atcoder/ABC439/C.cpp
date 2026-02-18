#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 1e7 + 10;
int a[N];

void solve() {
    for(int i = 1; i * i < N; i ++) {
        for(int j = i + 1; i * i + j * j < N; j ++) {
            a[i * i + j * j] ++;
        }
    }

    int n;
    cin >> n;
    int res = 0;
    for(int i = 1; i <= n; i ++) {
        if(a[i] == 1) {
            res ++;
        }
    }
    cout << res << '\n';
    for(int i = 1; i <= n; i ++) {
        if(a[i] == 1) {
            cout << i << ' ';
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
