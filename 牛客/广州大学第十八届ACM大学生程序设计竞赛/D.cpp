#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;
const int inf = 2e9;

/*
求和符合条件的区间可以通过O(n)双指针得到
问题在于每次区间的mex求和是多少
我们知道可以通过维护vis数组 O(n)求出只有一端移动的mex
但本题两端都会移动，我们注意到mex的变化总是和数的第一次出现有关
于是我们考虑转而维护每个数出现的位置的桶队列q，第一次出现即为队首
维护这个队列，我们就可以在O(n * n)的复杂度下得到答案
我们另外注意到：若区间[l, r]的 mex 为 d，则 0、1、2...d - 1 必定出现在区间[l, r]中
设区间和为sum，则总是有(d - 1) * d / 2 < sum，得到mex最大值d与区间和sum的关系
而本题还有sum < x
于是d <= sqrt(2 * x)
*/

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    int m = sqrt(2 * x);
    vector<queue<int>> q(m + 1);
    i64 ans = 0;
    i64 sum = 0;
    for(int l = 0, r = 0; l < n; l ++) {
        while(l == r || (r < n && sum + a[r] <= x)) {
            sum += a[r];
            if(a[r] <= m) {
                q[a[r]].push(r);
            }
            r ++;
        }
        int lst = l;
        int mx = 0;
        for(int i = 0; i <= m; i ++) {
            int cur;
            if(q[i].size()) {
                cur = q[i].front();
                if(cur >= lst) {
                    ans += 1ll * (cur - lst) * i;
                    lst = cur;
                }
            } else {
                mx = i;
                break;
            }
        }
        ans += 1ll * (r - lst) * mx;

        if(a[l] <= m) {
            q[a[l]].pop();
        }
        sum -= a[l];
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while(t --) {
        solve();
    }
}