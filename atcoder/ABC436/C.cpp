#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

void solve() {
    int n, m;
    cin >> n >> m;
    set<array<int, 2>> S;
    int cnt = 0;
    while(m --) {
        int x, y;
        cin >> x >> y;
        if(S.count({x, y}) || S.count({x + 1, y}) || S.count({x, y + 1}) || S.count({x + 1, y + 1})) {
            continue;
        }
        S.insert({x, y});
        S.insert({x + 1, y});
        S.insert({x, y + 1});
        S.insert({x + 1, y + 1});
        cnt ++;
    }
    cout << cnt << '\n';
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
