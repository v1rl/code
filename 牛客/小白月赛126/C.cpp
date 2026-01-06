#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

void solve() {
    int n, k, p;
    cin >> n >> p >> k;
    map<string, int> mp;

    vector<int> num(n);
    i64 sum = 0;
    for(int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        mp[s] = i;
        cin >> num[i];
        sum += num[i];
    }

    i64 mn = (sum + p - 1) / p;
    int mx = 1e9;
    for(int i = 0; i < k; i ++) {
        string s;
        cin >> s;
        mx = min(mx, num[mp[s]]);
    }
    
    if(k > p) {
        cout << -1 << '\n';
        return;
    }

    if(mn <= mx) {
        cout << mn << ' ' << mx << '\n';
    } else {
        cout << -1 << '\n';
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
