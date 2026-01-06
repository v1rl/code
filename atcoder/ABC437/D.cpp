#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
暴力显然不可取，我们考虑是否存在另一种复杂度更小的算法
注意到，两数相减的绝对值即大数取正，小数取负
对于数组a的每个元素，我们只需要知道b中有多个数小于a[i]，即可得知a[i]取正数次数，其补集即取负数次数
对于数组b的每个元素，同理
这样，我们即刻O(n + m)完成计算
离散化后前缀和即可解决静态的"数组中小于x的数的个数问题"
*/

const int mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> kth;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        kth.emplace_back(a[i]);
    }
    for(int i = 0; i < m; i ++) {
        cin >> b[i];
        kth.emplace_back(b[i]);
    }

    sort(kth.begin(), kth.end());
    kth.erase(unique(kth.begin(), kth.end()), kth.end());

    auto rk = [&](int x) {
        return lower_bound(kth.begin(), kth.end(), x) - kth.begin() + 1;
    };


    int t = kth.size();
    vector<int> suma(t + 1), sumb(t + 1);

    for(int i = 0; i < n; i ++) {
        a[i] = rk(a[i]);
        suma[a[i]] ++;
    }
    for(int i = 0; i < m; i ++) {
        b[i] = rk(b[i]);
        sumb[b[i]] ++;
    }

    for(int i = 1; i <= t; i ++) {
        suma[i] += suma[i - 1];
        sumb[i] += sumb[i - 1];
    }

    i64 ans = 0;
    for(int i = 0; i < n; i ++) {
        int num = sumb[a[i]];
        ans += 1ll * (2 * num - m) * kth[a[i] - 1] % mod;
        ans %= mod;
    }

    for(int i = 0; i < m; i ++) {
        // 需要注意，这里-1的意义是，相等时一方按取正数处理，则另一方必须按负数处理
        int num = suma[b[i] - 1];
        ans += 1ll * (2 * num - n) * kth[b[i] - 1] % mod;
        ans %= mod;
    }


    cout << (ans % mod + mod) % mod << '\n';
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
