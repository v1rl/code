#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int inf = 1e9 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    vector<int> b(n);
    auto check = [&](int x) {
        for(int i = 0; i < n; i ++) {
            b[i] = (a[i] >= x);
        }

        vector<int> stk;
        for(int i = 0; i < n; i ++) {
            stk.push_back(b[i]);
            if(stk.size() >= 3) {
                int m = stk.size();
                if(stk[m - 2] == 0 && stk[m - 3] == 0) {
                    stk.pop_back();
                    stk.pop_back();
                }
            }
        }

        int cnt1 = count(stk.begin(), stk.end(), 1);
        int cnt0 = stk.size() - cnt1;
        return cnt1 > cnt0;
    };

    int l = 1, r = 1e9;
    while(l < r) {
        int mid = l + r + 1 >> 1;
        if(check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << '\n';
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
