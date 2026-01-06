#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
注意到：每次修改总是改一个前缀，起始左端点总是对齐的，每次操作后前缀区间的左端点或右端点总是对齐的
因此，我们考虑维护那些共用一个端点的前缀区间
可以证明，平均每次修改的复杂度在O(3)左右

另外，注意到：初始时编号小的区间总是被编号大的区间完全包围，且每次修改对象都是一整个前缀向前缀最后一个区间的端点对齐
这也就代表着无论怎么修改，“编号小的区间总是被编号的的区间完全包围”这个性质不会改变
所以，区间是否包含x这个点是具有单调性(二分性)的
采用两次二分即可解决

因为我们总是认为最终得到的点是符合条件的，但当前区间有可能全部都不符合条件，
所以在二分时我们需要对符合条件那侧的端点做特判，或者给符合条件那侧的端点做一个偏移量
*/

struct Node {
    int l, r;
    int op;
    int x;
};

void solve() {
    int n;
    cin >> n;
    vector<int> lt(n);
    for(int i = 0; i < n; i ++) {
        cin >> lt[i];
    }
    vector<Node> s;
    s.push_back({0, n, -1, 0});
    int m;
    cin >> m;

    auto work = [&](int op, int r) {
        while(1) {
            auto [cl, cr, cop, cx] = s.back();
            s.pop_back();
            if(cr < r) {
                continue;
            }
            if(cr > r) {
                s.push_back({r, cr, cop, cx});
            }
            int tl, tr;
            if(cop == -1) {
                tl = cx;
                tr = cx + lt[r];
            } else {
                tr = cx;
                tl = cx - lt[r];
            }
            int curx = (op == -1 ? tl : tr);
            s.push_back({0, r, op, curx});
            break;
        }
    };


    while(m --) {
        int op, x;
        cin >> op >> x;
        if(op == 1) {
            x --;
            work(-1, x);
        } else if(op == 2) {
            x --;
            work(1, x);
        } else {
            int l = -1, r = s.size() - 1;

            auto check = [&](int mid) {
                auto &[cl, cr, cop, cx] = s[mid];
                int tl, tr;
                if(cop == -1) {
                    tl = cx, tr = cx + lt[cl];
                } else {
                    tr = cx, tl = cx - lt[cl];
                }
                return (x >= tl && x < tr);
            };

            while(l < r) {
                int mid = l + r + 1 >> 1;
                if(check(mid)) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }

            // if(l == 0) {
            //     if(!check(l)) {
            //         l --;
            //     }
            // }

            auto check1 = [&](int mid) {
                int tl, tr;
                if(s[l].op == -1) {
                    tl = s[l].x;
                    tr = tl + lt[mid];
                } else {
                    tr = s[l].x;
                    tl = tr - lt[mid];
                }
                return (tl <= x && tr > x);
            };

            int ans = 0;
            if(l == s.size() - 1) {
                ans += n;
            } else {
                l ++;
                int L = s[l].l, R = s[l].r;
                while(L < R) {
                    int mid = L + R >> 1;
                    if(check1(mid)) {
                        R = mid;
                    } else {
                        L = mid + 1;
                    }
                }
                // if(L == s[l].r) {
                //     if(!check1(L)) {
                //         L ++;
                //     }
                // }
                ans += n - L;
            }
            cout << ans << '\n';
        }
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
