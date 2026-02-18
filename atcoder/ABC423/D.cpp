#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
5 4 3 2 1
  4 3 2 1
    3 2 1 
      2 1
        1
10 18 24 28 30
*/

typedef pair<i64, int> PII;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    i64 curT = 0, curN = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    for(int i = 0; i < n; i ++) {
        curT = max<i64>(curT, a[i]);
        while(curN + c[i] > k) {
            auto [time, cnt] = heap.top();
            heap.pop();
            curT = max<i64>(curT, time);
            curN -= cnt;
        }
        curN += c[i];
        heap.push({curT + b[i], c[i]});
        cout << curT << '\n';
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