#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
注意到只会是左侧向右侧倒
从左到右维护，浪费的部分可以通过更优策略补上新的缺失
*/

void solve() {
    int n, m;
    cin >> n >> m;
    queue<int> q;
    vector<int> a(n + 1);
    i64 sum = 0;
    i64 cur = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        if(cur > m) {
            cur 
        }
    }
    cout << sum << '\n';
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