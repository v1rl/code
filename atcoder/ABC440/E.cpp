#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
经典Topk问题，将数据排序，不难发现k全部分布在最大时总和最大
以此为起点，用优先队列heap<sum, array<int, 50>>维护，当前数的次小数集合在所有-a[i]+a[i+1]中出现，全部入堆即可
过程类似一个初始点为全部在a[0]处，邻点在-a[i]+a[i+1]处的dijkstra
*/

typedef pair<i64, array<int, 50>> PIA;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
struct rHash {
    using u64 = uint64_t;

    static u64 sm64(u64 x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    // 基础整数类型
    template<typename T>
    typename enable_if<is_integral<T>::value, size_t>::type
    operator()(T x) const {
        static const u64 salt = rng();
        return sm64((u64)x + salt);
    }

    // 基础字符串类型 (新增部分)
    size_t operator()(const string& s) const {
        static const u64 salt = rng();
        u64 h = 0;
        for (char c : s) h = h * 131 + c; 
        return sm64(h + salt);
    }

    // 通用 Pair 哈希
    template<typename T1, typename T2>
    size_t operator()(const pair<T1, T2>& p) const {
        static const u64 salt = rng();
        // 递归调用，支持 pair 套 pair
        u64 h1 = (*this)(p.first); 
        u64 h2 = (*this)(p.second);
        return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }

    // 通用 Vector 哈希
    template<typename T>
    size_t operator()(const vector<T>& v) const {
        static const u64 salt = rng();
        u64 res = 0;
        for (const auto& x : v) {
            // 递归调用，支持 vector<vector<int>> 嵌套结构
            // 相应的，如果 x 是 string，会自动去调上面的 string 哈希
            u64 h = (*this)(x); 
            res ^= h + 0x9e3779b9 + (res << 6) + (res >> 2);
        }
        return res;
    }

    // 通用 Array 哈希 (支持任意大小 N 和类型 T)
    template<typename T, size_t N>
    size_t operator()(const array<T, N>& v) const {
        static const u64 salt = rng();
        u64 res = 0;
        for (const auto& x : v) {
            // 递归调用，支持 array 套 array
            u64 h = (*this)(x);
            res ^= h + 0x9e3779b9 + (res << 6) + (res >> 2);
        }
        return res;
    }
};

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater());

    unordered_set<array<array<i64, 2>, 50>, rHash> q;
    array<array<i64, 2>, 50> tt;
    q.insert(tt);

    unordered_set<array<int, 50>, rHash> S;
    priority_queue<PIA> heap;
    heap.push({1ll * k * a[0], {k}});
    while(x --) {
        auto [sum, b] = heap.top();
        heap.pop();
        cout << sum << '\n';

        for(int i = 0; i < n - 1; i ++) {
            if(b[i] > 0) {
                i64 csum = sum;
                array<int, 50> cb = b;
                cb[i] --;
                cb[i + 1] ++;
                csum -= a[i];
                csum += a[i + 1];
                if(!S.count(cb)) {
                    heap.push({csum, cb});
                    S.insert(cb);
                }
            }
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
