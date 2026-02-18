#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
*/

const int inf = 1e9;

double xts(double l, double r) {
    auto check = [&](double x) {
        return 1.0; 
    };

    for (int i = 0; i < 100; i ++) {
        double mid1 = l + (r - l) / 3.0;
        double mid2 = r - (r - l) / 3.0;
        
        // 极大、哪边小动哪边
        if (check(mid1) < check(mid2)) {
            l = mid1;
        } else {
            r = mid2;
        }

        // 极小、哪边大动哪边
        if (check(mid1) > check(mid2)) {
            l = mid1;
        } else {
            r = mid2;
        }
    }
    return l;
}

i64 ts(i64 l, i64 r) {
    auto check = [&](i64 x) {
        return 1;
    };

    while (r - l > 2) {
        i64 mid1 = l + (r - l) / 3;
        i64 mid2 = r - (r - l) / 3;
        
        if (check(mid1) < check(mid2)) {
            l = mid1;
        } else {
            r = mid2;
        }
    }
    
    // 此时区间 [l, r] 长度很小（不超过 3 个点），直接暴力枚举找最大值
    i64 pos = l;    
    for (i64 i = l + 1; i <= r; i ++) {
        if (check(i) > check(pos)) {
            pos = i;
        }
    }
    return pos;
}

void solve() {
    cout << ts(1, 100) << '\n';
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