#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
设计一种生成顺序，使得每一种合法的状态只会被生成一次，从而不需要使用stl去重
于是，我们考虑设计一种转移逻辑，让每一个状态都有且仅有一个固定的来源，就可以避免去重操作
注意到：初始时所有饼干都属于a[0]，所有种类饼干的被选状态即{k,0,0,0...}
注意到：只让最右侧的饼干执行转入和转出，由于最右边的非零位置是唯一的，所以每个状态的来源也就是唯一的，因而可以不重不漏的表示所有状态
于是，我们只需要记录{总和，最右侧的位置，最右侧位置上饼干数量，最右侧的上一位上饼干数量}即可
*/

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater());

    priority_queue<tuple<i64, int, int, int>> heap;
    heap.push({k * a[0], 0, k, 0});
    while(x --) {
        auto [sum, pos, num, pnum] = heap.top();
        heap.pop();
        cout << sum << '\n';

        if(pnum > 0) {
            heap.push({sum - a[pos - 1] + a[pos], pos, num + 1, pnum - 1});
        }
        if(pos + 1 < n) {
            heap.push({sum - a[pos] + a[pos + 1], pos + 1, 1, num - 1});
        }
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
