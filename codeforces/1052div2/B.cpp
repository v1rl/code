#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
先全部拿
再判断能不能丢两个
*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector a(n + 1, vector(1, 0));
    vector<int> st(m + 1);
    for(int i = 1; i <= n; i ++) {
        int num;
        cin >> num;
        a[i].resize(num + 1);
        for(int j = 1; j <= num; j ++) {
            cin >> a[i][j];
            st[a[i][j]] ++;
        }
    }

    for(int i = 1; i <= m; i ++) {
        if(!st[i]) {
            cout << "NO" << '\n';
            return;
        }
    }

    int num = 0;
    for(int i = 1; i <= n; i ++) {
        map<int, int> mp;
        for(int j = 1; j < a[i].size(); j ++) {
            mp[a[i][j]] ++;
        }

        bool f = true;
        for(auto [x, t] : mp) {
            if(st[x] - t == 0) {
                f = false;
                break;
            }
        }

        if(f) {
            num ++;
        }
        if(num == 2) {
            cout << "YES" << '\n';
            return;
        }
    }

    cout << "NO" << '\n';
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