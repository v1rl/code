#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

/*
*/

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int cnt = 0, lst = -1;
    for(int i = 0; i < n; i ++) {
        if(a[i] - lst >= cnt) {
            cnt ++;
            lst = a[i];
        }
    }

    cout << cnt << '\n';

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
