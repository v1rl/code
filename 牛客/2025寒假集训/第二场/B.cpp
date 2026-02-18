#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/

const int mod = 998244353;
const int inf = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    int mx = *max_element(a.begin(), a.end());
    int cnt = count(a.begin(), a.end(), mx);

    for(int i = 0; i < n; i ++) {
        if(a[i] == mx) {
            cout << (cnt & 1);
        } else {
            cout << (~cnt & 1);
        }
        // cout << ((a[i] != mx) + cnt) % 2;
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