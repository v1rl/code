#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

mt19937_64 rng(1337);

i64 randRange(i64 l, i64 r) {
    return uniform_int_distribution<i64>(l, r)(rng);
}

// ---------------------------------------------------------
// 核心：你的标程逻辑，改造为直接读取 in_file，写入 out_file
// ---------------------------------------------------------
void solve_and_generate_out(const string& in_file, const string& out_file) {
    ifstream cin(in_file);
    ofstream cout(out_file);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n + 1);
    priority_queue<array<i64, 3>, vector<array<i64, 3>>, greater<array<i64, 3>>> heap;
    for(int i = 1; i <= n; i ++) {
        cin >> v[i];
        if(v[i] == 0) {
            heap.push({0, i, 1});
        }
    }

    for(int i = 0; i < k; i ++) {
        int t, c;
        cin >> t >> c;
        for(int j = 0; j < c; j ++) {
            int x;
            cin >> x;
            heap.push({t, x, 1});
        }
    }

    vector<vector<array<int, 2>>> adj(n + 1); 
    for(int i = 0; i < m; i ++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
    }

    vector<i64> ans(n + 1, -1);
    while(heap.size()) {
        auto [t, x, op] = heap.top();
        heap.pop();

        if(ans[x] != -1) {
            continue;
        }

        if(!op && --v[x] > 0) {
            continue;
        }

        ans[x] = t;
        for(auto [y, w] : adj[x]) {
            heap.push({t + w, y, 0});
        }
    }

    for(int i = 1; i <= n; i ++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    
    cin.close();
    cout.close();
}

// ---------------------------------------------------------
// 辅助函数：构造边、写入 .in 和统筹调度
// ---------------------------------------------------------
void add_random_edges(int n, int m, int max_w, vector<pair<pair<int, int>, int>>& edges) {
    for (int i = 0; i < m; ++i) {
        int u = randRange(1, n);
        int v = randRange(1, n);
        while (u == v) v = randRange(1, n);
        edges.push_back({{u, v}, (int)randRange(0, max_w)});
    }
}

void build_test_case(int test_idx, int n, int m, int k, 
                     const vector<int>& a, 
                     const vector<pair<pair<i64, int>, vector<int>>>& refreshers,
                     const vector<pair<pair<int, int>, int>>& edges) {
    
    cout << "Generating Case " << test_idx << " ... ";
    
    // 1. 写入 .in
    string in_file = to_string(test_idx) + ".in";
    string out_file = to_string(test_idx) + ".out";
    
    ofstream fout(in_file);
    fout << n << " " << m << " " << k << "\n";
    for (int i = 0; i < n; ++i) fout << a[i] << (i == n - 1 ? "" : " ");
    fout << "\n";

    for (auto& ref : refreshers) {
        fout << ref.first.first << " " << ref.first.second;
        for (int id : ref.second) fout << " " << id;
        fout << "\n";
    }

    for (auto& edge : edges) {
        fout << edge.first.first << " " << edge.first.second << " " << edge.second << "\n";
    }
    fout.close();

    // 2. 调用标程计算并写入 .out
    solve_and_generate_out(in_file, out_file);
    cout << "Done! (" << in_file << " & " << out_file << " created)" << endl;
}

// ---------------------------------------------------------
// 样例硬编码录入，确保题面例子原汁原味
// ---------------------------------------------------------
void build_hardcoded_case(int test_idx, const string& input_data) {
    cout << "Generating Case " << test_idx << " ... ";
    string in_file = to_string(test_idx) + ".in";
    string out_file = to_string(test_idx) + ".out";
    
    ofstream fout(in_file);
    fout << input_data;
    fout.close();
    
    solve_and_generate_out(in_file, out_file);
    cout << "Done! (" << in_file << " & " << out_file << " created)" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    
    // Case 1-3: 题目 Example 原数据
    build_hardcoded_case(1, "6 9 0\n0 2 1 1 1 4\n1 2 1\n2 3 1\n3 4 1\n4 5 1\n5 2 1\n2 6 1\n3 6 1\n4 6 1\n5 6 1\n");
    build_hardcoded_case(2, "6 9 1\n0 2 1 1 1 4\n100 2 3 5\n1 2 1\n2 3 1\n3 4 1\n4 5 1\n5 2 1\n2 6 1\n3 6 1\n4 6 1\n5 6 1\n");
    build_hardcoded_case(3, "4 3 0\n1 0 1 1\n3 1 10\n1 2 100\n2 4 1000\n");

    // Case 4: 小规模随机
    {
        int n = 10, m = 20, k = 2;
        vector<int> a(n); for(int i=0; i<n; i++) a[i] = randRange(0, 3); a[0] = 0;
        vector<pair<pair<i64, int>, vector<int>>> ref = {{{10, 2}, {3, 5}}, {{5, 1}, {8}}};
        vector<pair<pair<int, int>, int>> edges; add_random_edges(n, m, 10, edges);
        build_test_case(4, n, m, k, a, ref, edges);
    }

    // Case 5: 极长链 (测试能量逐级传递)
    {
        int n = 100000, m = n - 1, k = 0;
        vector<int> a(n, 1); a[0] = 0;
        vector<pair<pair<int, int>, int>> edges;
        for(int i=1; i<n; i++) edges.push_back({{i, i+1}, 1});
        build_test_case(5, n, m, k, a, {}, edges);
    }

    // Case 6: 循环图 + 高阈值 (测试-1情况)
    {
        int n = 1000, m = 1000, k = 0;
        vector<int> a(n, 100); a[0] = 0;
        vector<pair<pair<int, int>, int>> edges;
        for(int i=1; i<n; i++) edges.push_back({{i, i+1}, 1}); edges.push_back({{n, 1}, 1});
        build_test_case(6, n, m, k, a, {}, edges);
    }

    // Case 7: 强力刷新器 (一键解锁全场)
    {
        int n = 100000, m = 0, k = 1;
        vector<int> a(n, 100); a[0] = 0;
        vector<int> ids(n-1); iota(ids.begin(), ids.end(), 2);
        vector<pair<pair<i64, int>, vector<int>>> ref = {{{1000000000LL, n-1}, ids}};
        build_test_case(7, n, m, k, a, ref, {});
    }

    // Case 8-10: 极限规模随机数据 (N=1e5, M=1e6)
    for(int t=8; t<=10; t++) {
        int n = 100000, m = 1000000, k = 500;
        vector<int> a(n); for(int i=0; i<n; i++) a[i] = randRange(0, 100); a[randRange(0, n-1)] = 0;
        vector<pair<pair<i64, int>, vector<int>>> ref;
        int total_sc = 0;
        for(int i=0; i<k; i++) {
            int sc = randRange(1, 1000);
            if(total_sc + sc > 1000000) break;
            unordered_set<int> st;
            while(st.size() < sc) {
                st.insert(randRange(1, n));
            }
            vector<int> ids(st.begin(), st.end());
            ref.push_back({{randRange(0, 1000000000), sc}, ids});
            total_sc += sc;
        }
        vector<pair<pair<int, int>, int>> edges; add_random_edges(n, m, 1000000000, edges);
        build_test_case(t, n, m, ref.size(), a, ref, edges);
    }

    // Case 11: 零权重边测试 (0ms 传递)
    {
        int n = 50000, m = 100000, k = 10;
        vector<int> a(n, 1); a[0] = 0;
        vector<pair<pair<int, int>, int>> edges; add_random_edges(n, m, 0, edges);
        build_test_case(11, n, m, 0, a, {}, edges);
    }

    // Case 12: 星型图 (极多边指向同一节点)
    {
        int n = 100000, m = 100000, k = 0;
        vector<int> a(n, 0); for(int i=1; i<n; i++) a[i] = 100000;
        vector<pair<pair<int, int>, int>> edges;
        for(int i=0; i<m; i++) edges.push_back({{1, (i % (n-1)) + 2}, 1});
        build_test_case(12, n, m, k, a, {}, edges);
    }

    // Case 13-15: 综合复杂图 (长链与随机边混合体，高压测试)
    for(int t=13; t<=15; t++) {
        int n = 100000, m = 500000, k = 1000;
        vector<int> a(n); for(int i=0; i<n; i++) a[i] = randRange(0, 10); a[0] = 0;
        vector<pair<pair<int, int>, int>> edges;
        for(int i=1; i<n/2; i++) edges.push_back({{i, i+1}, (int)randRange(0, 100)});
        add_random_edges(n, m - (n/2), 1000000, edges);

        vector<pair<pair<i64, int>, vector<int>>> ref;
        int total_sc = 0;
        for(int i=0; i<k; i++) {
            int sc = randRange(1, 100); // 不要太大，防止超过总和百万的限制
            if(total_sc + sc > 1000000) break;
            
            unordered_set<int> st;
            while(st.size() < sc) st.insert(randRange(1, n));
            vector<int> ids(st.begin(), st.end());
            
            ref.push_back({{randRange(0, 1000000000), sc}, ids});
            total_sc += sc;
        }

        build_test_case(t, n, m, ref.size(), a, ref, edges);
    }

    cout << "\nAll 15 IN/OUT pairs generated successfully!" << endl;
    return 0;
}