#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;

    int k = n - 2;
    vector<int> a {1, k, 1, 0};
    int cur = 2 * k;

    while(cur > m) {
        cur --;
        a[1] --, a[3] ++;
    }

    for(int i = 0; i < 4; i ++) {
        while(a[i] --) {
            char c = 'a' + i;
            cout << c;
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;

    while(t --) {
        solve();
    }
    return 0;
}