#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://leetcode.cn/problems/ipo/description/

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i][0] >> a[i][1];
    }
    sort(a.begin(), a.end(), 
        [&](auto x, auto y) {
            return x[1] < y[1];
        });
    int k, w;
    cin >> k >> w;
    int j = 0;
    priority_queue<int> heap;
    for(int i = 0; i < k; i ++) {
        while(j < n && a[j][1] <= w) {
            heap.push(a[j][0]);
            j ++;
        }

        if(heap.size()) {
            w += heap.top();
            heap.pop();
        } else {
            break;
        }
    }
    cout << w << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}