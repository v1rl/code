#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
1号除非初始是黑色不然无法涂黑

维护一个理应被涂黑的格子
默认跨度为1
若上一次最后执行B操作，下一个理应被涂黑的白色格子跨度变成2
被跳过的格子若为黑色则继续跳过
当前最后为A，则维护点就到当前格子，当前最后为B，则维护点继续若为黑色则跳过
*/

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    set<int> S;
    for(int i = 0; i < m; i ++) {
        int x;
        cin >> x;
        S.insert(x);
    }

    int cur = 2;
    for(int i = 0; i < n; i ++) {
        if(s[i] == 'B') {
            while(S.count(cur)) {
                cur ++;
            }
            S.insert(cur);
            cur ++;
            while(S.count(cur)) {
                cur ++;
            }
            cur ++;
        } else {
            S.insert(cur);
            cur ++;
        }
    }

    cout << S.size() << '\n';
    for(auto c : S) {
        cout << c << ' ';
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
