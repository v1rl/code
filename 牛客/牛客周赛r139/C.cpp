#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

const int mod = 1e9 + 7;

void solve() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    vector<int> stk;
    queue<int> q;


    vector<int> res1, res2;
    while(t --) {
        int op;
        cin >> op;
        if(op == 1) {
            int x;
            cin >> x;
            stk.push_back(x);
            q.push(x);
        } else {
            res1.emplace_back(stk.back());
            stk.pop_back();
            res2.emplace_back(q.front());
            q.pop();
        }
    }

    bool ok1 = true, ok2 = true;
    for(int i = 0; i < n; i ++) {
        ok1 &= (a[i] == res1[i]);
        ok2 &= (a[i] == res2[i]);
    }

    if(ok1 && ok2) {
        cout << "both" << '\n';
    } else if(ok1) {
        cout << "stack" << '\n';
    } else if(ok2) {
        cout << "queue" << '\n';
    } else {
        cout << -1 << '\n';
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
