#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

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
    int n, k;
    cin >> n >> k;
    vector<i64> a(n), b(n), c(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i ++) {
        cin >> b[i];
    }
    for(int i = 0; i < n; i ++) {
        cin >> c[i];
    }
    sort(a.begin(), a.end(), greater());
    sort(b.begin(), b.end(), greater());
    sort(c.begin(), c.end(), greater());

    unordered_set<array<int, 3>, rHash> S;

    priority_queue<tuple<i64, int, int, int>> heap;
    heap.push({a[0] * b[0] + b[0] * c[0] + c[0] * a[0], 0, 0, 0});
    S.insert({0, 0, 0});
    for(int i = 0; i < k - 1; i ++) {
        auto [sum, x, y, z] = heap.top();
        heap.pop();

        if(x + 1 < n && !S.count({x + 1, y, z})) {
            heap.push({a[x + 1] * b[y] + b[y] * c[z] + c[z] * a[x + 1], x + 1, y, z});
            S.insert({x + 1, y, z});
        }

        if(y + 1 < n && !S.count({x, y + 1, z})) {
            heap.push({a[x] * b[y + 1] + b[y + 1] * c[z] + c[z] * a[x], x , y + 1, z});
            S.insert({x, y + 1, z});
        }

        if(z + 1 < n && !S.count({x, y, z + 1})) {
            heap.push({a[x] * b[y] + b[y] * c[z + 1] + c[z + 1] * a[x], x, y, z + 1});
            S.insert({x, y, z + 1});
        }
    }

    auto t = heap.top();
    cout << get<0>(t) << '\n';
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
