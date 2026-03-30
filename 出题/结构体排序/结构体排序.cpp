#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://www.luogu.com.cn/problem/P1776

/*
*/

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<tuple<string, int, int, int>> a(n);
    for(int i = 0; i < n; i ++) {
        string name;
        int x, y, z;
        cin >> name >> x >> y >> z;
        a[i] = {name, x, y, z};
    }

    sort(a.begin(), a.end(), 
        [&](auto &x, auto &y) {
            if(get<1>(x) != get<1>(y)) {
                return get<1>(x) > get<1>(y);
            }
            if(get<2>(x) != get<2>(y)) {
                return get<2>(x) > get<2>(y);
            }
            if(get<3>(x) != get<3>(y)) {
                return get<3>(x) > get<3>(y);
            }
            return get<0>(x) < get<0>(y);
        });

    for(auto &[s, _1, _2, _3] : a) {
        cout << s << '\n';
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
