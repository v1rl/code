#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), mx(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        mx[i] = max(mx[i - 1], a[i] + i);
    }    

    auto check = [&](int mid) {
        int r = 1;
        int t = k;
        while(r <= n) {
            while(r <= n && a[r] == 0) {
                r ++;
            }

            if(r > n) {
                return true;
            }
            
            if(t > 0) {
                t --;
            } else {
                return false;
            }

            int cnt = mid;
            while(r < n && cnt --) {
                if(mx[r] == r) {
                    break;
                }
                r = mx[r];
            }

            r ++;
        }
        return true;
    };

    int l = 0, r = n;
    while(l < r) {
        int mid = l + r >> 1;
        if(check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << (l == n ? -1 : l) << '\n';
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