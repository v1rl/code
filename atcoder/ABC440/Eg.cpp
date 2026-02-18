#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
设计一种生成顺序，使得每一种合法的状态只会被生成一次，从而不需要使用stl去重
初始时所有饼干都属于a[0]，已选饼干的状态即{0,0,0,0...}
注意到：我们可以引入"当前正在维护的值"这一变量到heap的存储中，来保证有序集不会重复
集合中顺序排不并不影响结果，所以我们需要维护的是无序集，因此我们需要对同一集合的不同顺序有序集进行去重
注意到：只要保证任何时候已完成维护的值至少为1，且已完成维护的部分状态集是单调不减的，就可以保证无序集不会重复
于是，我们只需要记录{总和，当前正在维护的位置，当前位置的值(+1了多少次)}即可
对于无需集，后方的变化的当前下一位的变化是等价的，所以递进变化时只需要考虑下一位即可
*/

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater());

    priority_queue<tuple<i64, int, int>> heap;
    heap.push({k * a[0], 1, 0});
    while(x --) {
        auto [sum, cur, pos] = heap.top();
        heap.pop();
        cout << sum << '\n';

        if(cur < k && pos) {
            heap.push({sum - a[0] + a[pos], cur + 1, pos});
        }
        if(pos + 1 < n) {
            heap.push({sum - a[pos] + a[pos + 1], cur, pos + 1});
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
