#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
总是拿多的
相等的情况下从少的开始拿
6 5 3 2

3 3 2 2
6 4

4 4 3 3
8 6

4 4 4 3 3 
8 10

4 3 3 2
6 5 5 4 3 2 1 

按照相等个数从多到少计数
每次轮流拿
*/

void solve() {
    map<int, int> mp;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        mp[x] ++;
    }
    vector<array<int, 2>> a;
    for(auto [x, y] : mp) {
        a.push_back({y, x});
    }
    i64 ans1 = 0, ans2 = 0;
    sort(a.begin(), a.end(), greater());
    int cur = 1;
    for(auto [x, y] : a) {
        if(cur) {
            ans1 += 1ll * (y + 1) / 2 * x;
            ans2 += 1ll * y / 2 * x;
        } else {
            ans2 += 1ll * (y + 1) / 2 * x;
            ans1 += 1ll * y / 2 * x;
        }
        if(y & 1) {
            cur ^= 1;
        }
    }
    cout << ans1 << ' ' << ans2 << '\n';
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