#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int num = 0;
    for(auto c : s) {
        if(c == '?') {
            num ++;
        }
    }

    auto check = [&](int mid) {
        i64 ans = 0;
        int cnt = 0;
        int cur = 0;
        for(auto c : s) {
            if(c == '1') {
                cnt ++;
            } else if(c == '0') {
                ans += cnt;
            } else {
                if(cur < mid) {
                    cnt ++;
                    cur ++;
                } else {
                    ans += cnt;
                }
            }
        }
        return ans;
    };

    int l = 0, r = num;
    while(r - l > 2) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        if(check(mid1) < check(mid2)) {
            l = mid1;
        } else {
            r = mid2;
        }
    }

    i64 ans = 0;
    for(int i = l; i <= r; i ++) {
        ans = max(ans, check(i));
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;

    while(t --) {
        solve();
    }
    return 0;
}