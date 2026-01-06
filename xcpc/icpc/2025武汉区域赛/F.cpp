#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
右端点排序
如果当前右端点对应区间没被标记过，标记该区间，并同时标记所有左端点<=它的区间
看看需要根据右端点标记多少次
输出答案除2上取整
*/ 

const int inf = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> ls, rs;
    for(int i = 0; i < m; i ++) {
        int l, r;
        cin >> l >> r;
        ls.push_back({l, i});
        rs.push_back({r, i});
    }

    sort(rs.begin(), rs.end());
    sort(ls.begin(), ls.end());
    vector<int> st(m + 1);
    int ans = 0;
    for(int i = 0, j = 0; i < m; i ++) {
        int mk = rs[i][1];
        if(!st[mk]) {
            ans ++;
            while(j < m && ls[j][0] <= rs[i][0]) {
                st[ls[j][1]] = true;
                j ++;
            }
        }
    }
    cout << __lg(ans) + 1 << '\n';
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