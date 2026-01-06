#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
1 2
2 4
4 3

1~环大小-1的求和
*/

const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> pos(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    i64 ans = 0;
    vector<int> st(n + 1);
    for(int i = 1; i <= n; i ++) {
        if(a[i] == i) {
            continue;
        }
        if(!st[i]) {
            int cnt = 0;
            int x = i;
            while(!st[x]) {
                st[x] = true;
                x = pos[x];
                cnt ++;
            }
            ans += 1ll * cnt * (cnt - 1) / 2;
        }
    }
    cout << ans << '\n';
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
