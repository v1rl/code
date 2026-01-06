#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
1  2  3  4  5  6  7  8
 1  2  3  2  1   0  1
1  2  3  4
  1  0  1


1 0 1 0 1 0 1 0 1 0 1
1 2 1 0 1 2 1 0 1 2 1
1 2 3 2 1 0 1 2 3 2 1
1 2 3 4 3 2 1 0 1 2 1


每次我们对差分数组的权值总情况是固定的
问题在于怎么分配
我们总是不会拆分梯子形区间的，所以问题在于，我们把小区间放在最后还是开始
这似乎只有两种情况？
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n * 2 + 1);
    for(int i = 1; i <= n * 2; i ++) {
        cin >> a[i];
    }
    for(int i = 2 * n; i >= 2; i --) {
        a[i] -= a[i - 1];
    }

    for(int i = 1; i <= n; i ++) {
        vector<int> w(n * 2 - 1);
        int cur = 1;
        int op = 1;
        if(cur == i) {
            op = -op;
        }
        for(int j = 0; j <= n * 2 - 2; j ++) {
            w[j] = cur;
            cur += op;
            if(cur == i || cur == 0) {
                op = -op;
            }
        }

        // for(auto c : w) {
        //     cout << c << ' ';
        // }
        // cout << '\n';

        i64 ans1 = 0;
        for(int j = 2; j <= n * 2; j ++) {
            ans1 += 1ll * a[j] * w[j - 2];
        }
        i64 ans2 = 0;
        reverse(w.begin(), w.end());
        for(int j = 2; j <= n * 2; j ++) {
            ans2 += 1ll * a[j] * w[j - 2];
        }
        cout << max(ans1, ans2) << ' ';
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
