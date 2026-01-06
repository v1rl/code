#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
考虑将D1的二分过程通过数论分块优化，但这样依然会超时
考虑直接由k反推我们在D1中假设并进行二分答案的p，这样就可以剩去二分答案的复杂度
在正向二分答案时，我们选取的是最终删除得到k个数的最左侧的p，以此保证p本身一定不会在过程中被删除
因而反推过程中我们认为维护的 l 就是那个不会被删除的结果，
所以反推时的计算是除去 l 的其他数中每有y - 1个就添上1个，从而得到式子(l - 1) / (y - 1)

分子变化的数论分块，关键在于如果q = floor(x / k)，那么x的范围是qk ≤ x ≤ (q + 1)k − 1
因为分子是根据整除得到的结果离散变化，我们会去求[l, r]中有多少个离散值可以得到相同的结果
*/


const i64 inf = 1e12;

void solve() {
    i64 x, y, k;
    cin >> x >> y >> k;
    if(y == 1) {
        cout << -1 << '\n';
        return;
    }

    for(i64 l = k, r; ;) {
        i64 val = (l - 1) / (y - 1);
        if(val == 0) {
            cout << k << '\n';
            return;
        }
        r = (val + 1) * (y - 1) - 1;
        // 需要注意，常规情况下我们是计算[l, r]的跨度r - l，这里加1是因为计算的r相比实际的r有-1的偏移量
        // 需要注意，我们会对结果再执行+1，因为初始就有一次，跨度/val得到的是中间的添头
        i64 cnt = min(x, (r + 1 - l) / val + 1);
        x -= cnt;
        l += cnt * val;
        if(l > inf) {
            cout << -1 << '\n';
            return;
        }
        if(x == 0) {
            cout << l << '\n';
            return;
        }
    }
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
