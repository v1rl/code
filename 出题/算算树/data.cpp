#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int mod = 998244353;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

// 等价于标程的非递归版本，防止特殊构造树（如长链）导致系统栈溢出
i64 solve_test(int n, const vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(n + 1);
    for (auto e : edges) {
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
    }
    
    vector<int> dep(n + 1, 0), siz(n + 1, 1), p(n + 1, -1);
    vector<int> q; // 模拟 BFS 队列
    q.reserve(n);
    q.push_back(1);
    dep[1] = 1;
    
    // BFS 求 dep 和 父节点
    for(int i = 0; i < (int)q.size(); ++i) {
        int u = q[i];
        for(int v : adj[u]) {
            if(v != p[u]) {
                p[v] = u;
                dep[v] = dep[u] + 1;
                q.push_back(v);
            }
        }
    }
    
    // 逆序遍历 BFS 序列计算 siz (自底向上)
    for(int i = n - 1; i >= 0; --i) {
        int u = q[i];
        if (p[u] != -1) siz[p[u]] += siz[u];
    }
    
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += siz[i] - 1;
    }
    
    for (auto e : edges) {
        int x = e.first, y = e.second;
        if (dep[x] > dep[y]) swap(x, y);
        ans = (ans + 1ll * siz[y] * (n - siz[y] - dep[x])) % mod;
    }
    
    return ans;
}

// 树的生成器
// type: 0随机树, 1链状树, 2菊花图(星状树), 3二叉树形态
vector<pair<int,int>> generate_tree(int n, int type) {
    vector<pair<int,int>> edges;
    if (n <= 1) return edges;
    
    vector<int> p(n + 1);
    for (int i = 2; i <= n; i++) {
        if (type == 0) p[i] = rnd() % (i - 1) + 1; 
        else if (type == 1) p[i] = i - 1; 
        else if (type == 2) p[i] = 1; 
        else if (type == 3) p[i] = i / 2; 
    }
    
    // 为了防止固定形状，除了根节点1，将其他节点编号打乱
    vector<int> perm(n + 1);
    perm[1] = 1;
    for (int i = 2; i <= n; i++) perm[i] = i;
    shuffle(perm.begin() + 2, perm.end(), rnd);

    for(int i = 2; i <= n; ++i) {
        int u = perm[i];
        int v = perm[p[i]];
        // 随机边输入顺序 u,v 或 v,u
        if (rnd() % 2) edges.push_back({u, v});
        else edges.push_back({v, u});
    }
    // 打乱边顺序
    shuffle(edges.begin(), edges.end(), rnd);
    return edges;
}

// 单个测试文件生成
// id: 测试点编号
// T: 组数
// sum_N: n的总和限制
// type_mask: 指定树类型，-1为随机混合
void gen_case(int id, int T, int sum_N, int type_mask) {
    cout << "Generating test case " << id << " ..." << endl;
    
    ofstream fin(to_string(id) + ".in");
    ofstream fout(to_string(id) + ".out");
    fin << T << "\n";
    
    int avg_n = sum_N / T;
    int rem_n = sum_N;
    
    for(int i = 0; i < T; ++i) {
        int n;
        if (i == T - 1) {
            n = rem_n; 
        } else {
            n = avg_n / 2 + rnd() % avg_n;
            if (n < 2) n = 2;
            if (n > rem_n - (T - 1 - i) * 2) n = rem_n - (T - 1 - i) * 2;
        }
        if (n < 2) n = 2;
        rem_n -= n;
        
        int type = type_mask;
        if (type == -1) type = rnd() % 4; // 混合类型
        
        auto edges = generate_tree(n, type);
        
        // 输出 .in
        fin << n << "\n";
        for (auto e : edges) {
            fin << e.first << " " << e.second << "\n";
        }
        
        // 输出 .out
        fout << solve_test(n, edges) << "\n";
    }
    
    fin.close();
    fout.close();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // ==========================================
    // 数据梯度设计 (总计 15 组)
    // ==========================================
    
    // 【前 3 组】极小数据，用于过滤极其显然的暴力
    gen_case(1, 10, 100, 0); // T=10, 随机树
    gen_case(2, 10, 100, 1); // T=10, 链状树
    gen_case(3, 10, 100, 2); // T=10, 菊花图
    
    // 【4-6 组】中等数据
    gen_case(4, 50, 5000, -1); // 混合形态
    gen_case(5, 50, 5000, 3);  // 二叉树
    gen_case(6, 100, 10000, -1);
    
    // 【7-10 组】大数据：T极大，n较小 (针对可能的错误清空和初始化导致超时)
    gen_case(7, 10000, 200000, -1);
    gen_case(8, 10000, 200000, 0);
    gen_case(9, 5000,  200000, 1);
    gen_case(10, 5000, 200000, 2);
    
    // 【11-13 组】大数据：T极小，n极大 (针对非线性的复杂度，或由于递归爆栈)
    gen_case(11, 1, 200000, 1); // 链状树 (容易引发 DFS 爆栈)
    gen_case(12, 1, 200000, 2); // 菊花图
    gen_case(13, 1, 200000, 3); // 二叉树
    
    // 【14-15组】满极限综合数据
    gen_case(14, 10, 200000, 0);  // 大随机树
    gen_case(15, 10, 200000, -1); // 终极混合极限数据
    
    cout << "All 15 test cases generated successfully!" << endl;
    return 0;
}