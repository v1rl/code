#include <bits/stdc++.h>
using namespace std;

// https://www.nowcoder.com/practice/1ae8d0b6bb4e4bcdbf64ec491f63fc37

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i][1] >> a[i][0];
    }
    sort(a.begin(), a.end());
    priority_queue<int> heap;
    int res = 0;
    for(auto [lastD, len] : a) {
        if(lastD - res >= len) {
            heap.push(len);
            res += len;
        } else {
            if(heap.size() && heap.top() > len) {
                res -= heap.top();
                heap.pop();
                heap.push(len);
                res += len;
            }
        }
    }

    cout << heap.size() << '\n';
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