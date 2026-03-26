#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

/*
给定一个数组nums，其中可能有正、负、0
每个魔法卷轴可以把nums中连续的一段全变成0
你希望数组整体的累加和尽可能大
卷轴使不使用、使用多少随意，但一共只有2个魔法卷轴
请返回数组尽可能大的累加和
*/

const int inf = 1e9;

int solve1(vector<int> &a) {
    int n = a.size();

    int pre = -inf, mx = -inf;
    for(int i = 0; i < n; i ++) {
        pre = max(a[i], pre + a[i]);
        mx = max(pre, mx);
    }

    int ans = mx;

    vector<int> fp(n);
    pre = a[0];
    mx = max(0, a[0]);
    for(int i = 1; i < n; i ++) {
        fp[i] = max(fp[i - 1] + a[i], mx);
        pre = max(a[i], pre + a[i]);
        mx = max(mx, pre);
    }

    ans = max(ans, fp[n - 1]);

    vector<int> fs(n);
    int suf = a[n - 1];
    mx = max(0, a[n - 1]);
    for(int i = n - 2; i >= 0; i --) {
        fs[i] = max(fs[i + 1] + a[i], mx);
        suf = max(a[i], suf + a[i]);
        mx = max(mx, suf);
    }

    for(int i = 0; i < n - 1; i ++) {
        ans = max(ans, fp[i] + fs[i + 1]);
    }

    return ans;
}

int solve2(vector<int> &a) {
    int n = a.size();

    int pre = -inf, mx = -inf;
    for(int i = 0; i < n; i ++) {
        pre = max(a[i], pre + a[i]);
        mx = max(pre, mx);
    }
    int ans = mx;

    for(int l1 = 0; l1 < n; l1 ++) {
        for(int r1 = l1; r1 < n; r1 ++) {
            for(int l2 = r1; l2 < n; l2 ++) {
                for(int r2 = l2; r2 < n; r2 ++) {
                    int pre = -inf, mx = -inf;
                    for(int i = 0; i < n; i ++) {
                        int x = a[i];
                        if((i >= l1 && i <= r1) || (i >= l2 && i <= r2)) {
                            x = 0;
                        }
                        pre = max(pre + x, x);
                        mx = max(mx, pre);
                    }
                    ans = max(ans, mx);
                }
            }
        }
    }

    return ans;
}

void checker() {
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    for(int i = 0; i < 5; i ++) {
        int n = rng() % 50 + 1;
        vector<int> a(n);
        for(int j = 0; j < n; j ++) {
            a[j] = rng() % 1000 - 500;
        }
        int ans1 = solve1(a), ans2 = solve2(a);
        if(ans1 != ans2) {
            cout << "WA ON TEST" << ' ' << i + 1 << '\n';
            for(int j = 0; j < n; j ++) {
                cout << a[j] << " \n"[j == n - 1];
            }
            cout << ans1 << ' ' << ans2 << '\n';
            break;
        }
    }
    cout << "Accepted!";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t --) {
        checker();
    }

    return 0;
}
