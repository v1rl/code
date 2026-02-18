#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
红1黄2 / 红2黄1
白2(最多m个)
若无变化，简单双指针解决
有变化，统计个数的同时用双指针解决
*/

const int inf = 1e9;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    if(k == 0) {
        cout << 1 << '\n';
        return;
    }
    array<int, 3> num;
    num.fill(0);
    int ans = inf;
    for(int l = 0, r = 0; r < s.size(); r ++) {
        if(s[r] == 'r') {
            num[0] ++;
        } else if(s[r] == 'y') {
            num[1] ++;
        } else {
            num[2] ++;
        }

        int val = max(num[0] * 2 + num[1], num[1] * 2 + num[0]) + min(num[2], m) * 2;
        if(val >= k) {
            while(1) {
                if(s[l] == 'r') {
                    num[0] --;
                } else if(s[l] == 'y') {
                    num[1] --;
                } else {
                    num[2] --;
                }
                int val = max(num[0] * 2 + num[1], num[1] * 2 + num[0]) + min(num[2], m) * 2;
                l ++;
                if(val < k) {
                    break;
                }
            }
            ans = min(ans, r - l + 2);
        }
    }

    cout << (ans == inf ? -1 : ans) << '\n';
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
