#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
关键词：贪心，优先队列，中点

贪心地想：如果只放一个，一定放在两个最远距离的中间
对于放多个数，我们可以用优先队列来不断维护和取得当前的最短距离
另外，若当前距离是奇数，可以放两个，偶数，可以放一个
放完后距离权值若奇数-2，若偶数-1
对于首位和末位做特判

最后还有剩，直接放在点上
*/

struct Node {
    int l, r;
    int d;
    int num;

    bool operator < (const Node &W) const {
        return d < W.d;
    }
};

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    priority_queue<Node> heap;
    for(int i = 1; i < n; i ++) {
        heap.push({a[i - 1], a[i], a[i] - a[i - 1], 0});
    }
    heap.push({-1, a[0], a[0] * 2, 0});
    heap.push({a[n - 1], x + 1, (x - a[n - 1]) * 2, 0});

    while(k > 0) {
        auto [l, r, d, num] = heap.top();
        if(d <= 1) {
            break;
        }

        heap.pop();

        // cerr << l << ' ' << r << ' ' << d << ' ' << num << '\n';

        if(l == -1 || r == x + 1) {
            num += 1;
            d -= 2;
            k --;
        } else {
            if(d & 1) {
                int c = min(k, 2);
                num += c;
                d -= 2;
                k -= c;
            } else {
                num += 1;
                d -= 1;
                k --;
            }            
        }
        heap.push({l, r, d, num});


    }

    vector<int> ans;
    while(heap.size()) {
        auto [l, r, d, num] = heap.top();
        heap.pop();

        if(l == -1) {
            for(int i = 0; i < num; i ++) {
                ans.emplace_back(i);
            }
        } else if(r == x + 1) {
            for(int i = x; num > 0; i --, num --) {
                ans.emplace_back(i);
            }
        } else {
            int mid = l + r >> 1;
            for(int i = mid - (num - 1) / 2; num > 0; i ++, num --) {
                ans.emplace_back(i);
            }            
        }
    }

    // cerr << k << '\n';

    int cnt = 0;
    while(k > 0) {
        ans.emplace_back(a[cnt ++]);
        while(a[cnt] == a[cnt - 1]) {
            cnt ++;
        }
        k --;
    }

    sort(ans.begin(), ans.end());
    for(auto c : ans) {
        cout << c << ' ';
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