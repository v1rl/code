#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);

    unordered_map<int, int> mp;
    auto divide = [&](int x) {
        if(x < 0) x = -x;
        for(int i = 1; i * i <= x; i ++) {
            if(x % i == 0) {
                mp[i] ++;
                if(x / i != i) {
                    mp[x / i] ++;
                }
            }
        }
    };

    bool f = true;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        if(i > 1 && a[i] != a[i - 1]) {
            f = false;
        }
    }
    if(f) {
        cout << 0 << '\n';
        return;
    }

    int cnt = 0;
    int sum = a[n];
    for(int i = n; i >= 1; i --) {
        a[i] = a[i] - a[i - 1];
        if(a[i] != 0) {
            divide(a[i]);
            cnt ++;
        }
    }

    int mx = 0;
    for(auto [v, num] : mp) {
        if(num >= cnt - 1) {
            mx = max(v, mx);
        }
    }

    vector<int> ys;
    for(int i = 1; i * i <= sum; i ++) {
        if(sum % i == 0) {
            ys.emplace_back(i);
            if(sum / i != i) {
                ys.emplace_back(sum / i);
            }
        }
    }

    int mx2 = 0;
    for(auto x : ys) {
        int num = 0;
        int nd[2] = {0, 0};
        for(int i = 1; i <= n; i ++) {
            if(a[i] % x == 0) {
                num ++;
            } else {
                if(nd[0]) {
                    nd[1] = a[i];
                } else {
                    nd[0] = a[i];
                }
            }
        }
        if(num == n - 2) {
            if((nd[0] + nd[1]) % x == 0) {
                mx2 = max(mx2, x);
            }
        }
    }

    cout << max(mx, mx2) << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
}