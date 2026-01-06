#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
0000 0001       0010 0011 0100 0101       0110 0111 1000 1001

15 * 4 + 7 * 4 + 2
30 + 60
90


i从大到小遍历，找到当前最右侧与pow(2, i) - 1之间有多少个数，用(pow(2, i + 1) - 1) * 2累计答案，当前位置变成pos - 个数
*/

void solve() {
    int n;
    cin >> n;
    while(n --) {
        int l, r;
        cin >> l >> r;

        vector<int> a(r + 1);
        i64 ans = 0;
        for(int i = 20; i >= 0; i --) {
            int pos = pow(2, i) - 1;
            int dis = r - pos;
            if(dis <= 0) {
                continue;
            }
            ans += 1ll * dis * (pow(2, i + 1) - 1) * 2;
            for(int j = r, p = pos - dis + 1, k = 1; k <= dis * 2; k ++, j --, p ++) {
                a[p] = j;
            }
            r = pos - dis;
        }

        cout << ans << '\n';
        for(auto c : a) {
            cout << c << ' ';
        }
        cout << '\n';
    }
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