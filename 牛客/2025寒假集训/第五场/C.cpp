#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<i64, i64> PII;

/*
*/

const double eps = 1e-9;

void solve() {
    int n, m, h, c;
    cin >> n >> m >> h >> c;
    vector<int> p(n), v(n);
    for(int i = 0; i < n; i ++) {
        cin >> p[i] >> v[i];
    }


    auto check = [&](double mid) {
        vector<array<double, 2>> a;
        for(int i = 0; i < n; i ++) {
            double rad = v[i] * mid;
            if(rad > h) {
                double len = sqrt(rad * rad - (double)h * h);
                double L = p[i] - len;
                double R = p[i] + len;
                a.push_back({L, R});
            }
        }
        sort(a.begin(), a.end());

        double lst = 0, nxt = 0;
        int res = 0;
        for(auto [l, r] : a) {
            if(l > lst) {
                if(nxt < l) {
                    return false;
                }
                lst = nxt;
                res ++;
            }

            nxt = max(nxt, r);

            // if(lst > c) {
            //     return res <= m;
            // }

            // 直接判定当前维护量，注意此时实际次数是多1的
            if(nxt > c) {
                return res < m;
            }
        }
        // lst = nxt;
        // res ++;
        // if(lst > c) {
        //     return res <= m;
        // }
        return false;
    };

    double l = 0, r = 2e6;
    while(fabs(r - l) > eps) {
        double mid = (l + r) / 2;
        if(check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << fixed << setprecision(15);
    cout << l << '\n';
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
