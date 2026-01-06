#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long

/*
找第k大数且k的范围很大，显然需要一个log级别的算法，不难联想到二分
此时，我们考虑题目是否具备二分的单调性
我们注意到，如果我们以最终第k大的那个数为界做分割，其中所有对右侧部分的删除操作是无所谓的，不影响答案k的
我们对上界p进行二分答案，check执行x次删除后还剩数的个数，显然剩余数的个数具备单调性
我们取剩余数的个数恰好为k的最小的p，这个p就是需要的答案

取最小的p能保证我们得到的p不会在过程中被删除
因为如果最大值p在被删除情况下剩余k个数，不断令p-=1，一定会出现p本身不会被删除且剩余数个数仍然为k的p
*/

const i64 inf = 1e18;

void solve() {
    int x, y;
    i64 k;
    cin >> x >> y >> k;
    i64 l = 1, r = 1e12 + 1;

    auto check = [&](i64 mid) {
        int t = x;
        while(t --) {
            mid -= mid / y;
        }
        return mid >= k;
    };

    while(l < r) {
        i64 mid = l + r >> 1;
        if(check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << (l == 1e12 + 1 ? -1 : l) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
