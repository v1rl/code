#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<i64, int> PII;

/*
可以使用双队列优化成单log做法
*/

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    for(int i = 0; i < n; i ++) {
        int c, w;
        cin >> c >> w;
        heap.push({w, c});
    }

    i64 ans = 0;
    while(1) {
        auto [w, c] = heap.top();
        heap.pop();

        if(c == 1 && heap.empty()) {
            break;
        }

        int h = c / 2;
        if(h) {
            ans += w * 2 * h;
            ans %= mod;
            heap.push({w * 2, h});
        }

        if(c & 1) {
            auto [nw, nc] = heap.top();
            heap.pop();
            ans += nw + w;
            ans %= mod;
            heap.push({nw + w, 1});
            if(nc - 1) {
                heap.push({nw, nc - 1});
            }
        }
    }

    cout << ans << '\n';
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
