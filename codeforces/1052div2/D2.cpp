#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
0000 0001       0010 0011 0100      0101        0110 0111 1000 1001 1010


0110 0111 1000 1001     1010 1011 1100 1101 1110

15 * 4 + 7 * 4 + 2
30 + 60
90


i从大到小遍历，找到当前最右侧与pow(2, i) - 1之间有多少个数，用(pow(2, i + 1) - 1) * 2，当前位置变成pos - 个数

从右往左这一部分大概不需要修改，因为它们已经满了
所以，目前只需要考虑最后有空缺那一块
如果最后得到的pos - dis才小于l，那么能匹配多少匹配多少，随后得到剩余区间；如果得到的pos就小于l，那么直接得到剩余区间
对于剩余区间，一定有相同的最高位，我们将当前l和r都减去最高位，然后重复
*/

void solve() {
    int n;
    cin >> n;

    while(n --) {
        int l, r;
        cin >> l >> r;
        vector<int> a(r - l + 1);
        auto work = [&](int base, int& ll, int& rr) {
            i64 res = 0;
            for(int i = 30; i >= 0; i --) {
                if(ll == rr && ll == 0) {
                    res += base;
                    a[base - l] = base;
                    break;
                }
                int pos = pow(2, i) - 1;
                int dis = rr - pos;
                if(dis <= 0) {
                    continue;
                }
                if(pos < ll) {
                    return res;
                }
                if(pos - dis + 1 <= ll) {
                    dis = pos - ll + 1;
                    res += 1ll * dis * (pow(2, i + 1) - 1 + base) * 2;
                    for(int j = ll + dis * 2 - 1, p = ll, k = 1; k <= dis * 2; k ++, j --, p ++) {
                        a[p + base - l] = j + base;
                    }
                    ll += dis * 2;
                    return res;
                }
                res += 1ll * dis * (pow(2, i + 1) - 1 + base) * 2;
                for(int j = rr, p = pos - dis + 1, k = 1; k <= dis * 2; k ++, j --, p ++) {
                    a[p + base - l] = j + base;
                }
                rr = pos - dis;
            }
            return res;
        };

        int ll = l, rr = r;
        int bs = 0;
        i64 ans = 0;
        while(ll != 0) {
            ans += work(bs, ll, rr);
            int cnt = 0;
            int x = ll;
            while(x) {
                cnt ++;
                x /= 2;
            }
            int dis = pow(2, cnt - 1);
            bs += dis;
            ll -= dis;
            rr -= dis;
        }
        ans += work(bs, ll, rr);

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