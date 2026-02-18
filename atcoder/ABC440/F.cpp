#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
注意到：排列在变，但系数为2的数的个数是不变的，我们总是尽量让大的值系数为2，于是从大到小排序选取
因为系数的来源不是本身，而是前一个数，所以前k大不能全部都是B=2的马，至少需要一个B=1的马
若全部都是B=2的马，则考虑k+1位上B=1的最大的马
但本题还包括修改，我们需要维护一个有序的数据结构
用单纯的数组显然不行，我们可以考虑用有序的set维护，但用差量法维护答案所需要的考虑和讨论太多了
所以，根据需求，我们需要换一种能直接找到前k大的马、直接判断是否全是B=2的马并最终实现删一个最小的B=2和加一个最大的B=1的办法
权值树状数组也是一个有序的数据结构
注意到：这本质就是求带修改的总范围固定为全体集合的区间数的个数、区间值的求和和第k小数
用权值树状数组即可解决，找前k小值更好写，所以我们转而维护系数为1的部分
*/

template<typename T>
struct Fenwick {
    int n;
    vector<T> a;

    Fenwick(int n_) : n(n_), a(n + 1) {};

    void add(int x, const T &v) {
        for(int i = x; i <= n; i += i & -i)
            a[i] += v;
    }

    T sum(int x) {
        T res{};
        for(int i = x; i; i -= i & -i)
            res += a[i];
        return res;
    }

    T rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    int kth(int k) {                //针对权值树状数组 
        int pos = 0;
        T cur{};
        for(int i = 1 << __lg(n); i; i >>= 1) {
            if(pos + i <= n && cur + a[pos + i] < k) {   // 第k - 1小数
                pos += i;
                cur += a[pos];
            }
        }
        return pos + 1;
    }
};

const int N = 1e6;

void solve() {
    int n, q;
    cin >> n >> q;
    int num2 = 0;
    Fenwick<i64> trs(N), trc(N);
    Fenwick<int> tr1(N), tr2(N);
    vector<array<int, 2>> a(n);

    auto work = [&](int pos, int val, int d, int op) {
        int add = 1;
        if(op == 0) {
            val *= -1;
            add *= -1;
        }
        trs.add(pos, val);
        trc.add(pos, add);
        if(d == 1) {
            tr1.add(pos, add);
        } else {
            tr2.add(pos, add);
        }
    };

    for(int i = 0; i < n; i ++) {
        cin >> a[i][0] >> a[i][1];
        work(a[i][0], a[i][0], a[i][1], 1);
        if(a[i][1] == 2) {
            num2 ++;
        }
    }

    while(q --) {
        int pos, x, c;
        cin >> pos >> x >> c;
        pos --;

        if(a[pos][1] == 2) {
            num2 --;
        }
        work(a[pos][0], a[pos][0], a[pos][1], 0);
        a[pos] = {x, c};
        work(a[pos][0], a[pos][0], a[pos][1], 1);
        if(a[pos][1] == 2) {
            num2 ++;
        }

        i64 ans;
        if(num2 == n) {
            ans = trs.sum(N) * 2 - tr2.kth(1);
        } else if(num2 == 0) {
            ans = trs.sum(N);
        } else {
            ans = trs.sum(N) * 2;
            int k = trc.kth(n - num2);

            ans -= trs.sum(k - 1);
            int cur = trc.sum(k - 1);
            ans -= 1ll * (n - num2 - cur) * k;

            int h2 = tr2.sum(k);
            if(h2 == 0) {
                ans += tr1.kth(n - num2) - tr2.kth(1);
            }
        }

        cout << ans << '\n';
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

