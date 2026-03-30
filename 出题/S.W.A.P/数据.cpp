#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <string>
#include <algorithm>

using namespace std;

struct Query {
    int l1, r1, l2, r2;
};

// 将你的四次 reverse 优雅逻辑封装为标程
string solve_std(int n, int m, string s, const vector<Query>& queries) {
    for(int i = 0; i < m; i++) {
        int l1 = queries[i].l1 - 1;
        int r1 = queries[i].r1 - 1;
        int l2 = queries[i].l2 - 1;
        int r2 = queries[i].r2 - 1;
        
        reverse(s.begin() + l1, s.begin() + r1 + 1);
        reverse(s.begin() + l2, s.begin() + r2 + 1);
        if(r1 + 1 < l2) {
            reverse(s.begin() + r1 + 1, s.begin() + l2);
        }
        reverse(s.begin() + l1, s.begin() + r2 + 1);
    }
    return s;
}

// 核心生成逻辑
void make_test_case(int id, int n, int m, mt19937& rng) {
    // 1. 随机生成初始字符串 s
    uniform_int_distribution<int> char_dist(0, 25);
    string s = "";
    for(int i = 0; i < n; i++) {
        s += (char)('a' + char_dist(rng));
    }

    // 2. 随机生成 m 次合法的操作区间
    // 使用“四点取样法”保证 l1 <= r1 < l2 <= r2
    uniform_int_distribution<int> point_dist(1, n + 1);
    vector<Query> queries(m);
    for(int i = 0; i < m; i++) {
        vector<int> pts;
        // 拒绝采样，直到取到 4 个互不相同的点
        while(pts.size() < 4) {
            int p = point_dist(rng);
            if(find(pts.begin(), pts.end(), p) == pts.end()) {
                pts.push_back(p);
            }
        }
        sort(pts.begin(), pts.end());
        // 映射为合法区间
        queries[i].l1 = pts[0];
        queries[i].r1 = pts[1] - 1;
        queries[i].l2 = pts[2];
        queries[i].r2 = pts[3] - 1;
    }

    // --- 生成 .in 文件 ---
    string in_name = to_string(id) + ".in";
    ofstream fout_in(in_name);
    fout_in << n << " " << m << "\n";
    fout_in << s << "\n";
    for(int i = 0; i < m; i++) {
        fout_in << queries[i].l1 << " " << queries[i].r1 << " " 
                << queries[i].l2 << " " << queries[i].r2 << "\n";
    }
    fout_in.close();

    // --- 运行标程，生成 .out 文件 ---
    string ans = solve_std(n, m, s, queries);
    string out_name = to_string(id) + ".out";
    ofstream fout_out(out_name);
    fout_out << ans << "\n";
    fout_out.close();

    cout << "Test case " << id << " generated: " << in_name << " and " << out_name 
         << " (n=" << n << ", m=" << m << ")\n";
}

int main() {
    // 固定随机种子
    mt19937 rng(20260327); 

    cout << "开始生成测试数据..." << endl;

    // ==========================================
    // 前 5 组数据：规模逐渐递增，放过不优美的暴力拼接
    // ==========================================
    // 1. 极小数据，用于选手手算 Debug
    make_test_case(1, 15, 5, rng);
    
    // 2. 小数据
    make_test_case(2, 50, 20, rng);
    
    // 3. 中等偏小数据
    make_test_case(3, 200, 100, rng);
    
    // 4. 中等数据，O(n^2) 附带大常数的做法（如 substr 拷贝）也能轻松过
    make_test_case(4, 800, 500, rng);
    
    // 5. 较高压测试，筛选掉写得特别烂的暴力，但允许普通 string 拼接通过
    make_test_case(5, 1500, 1500, rng);

    // ==========================================
    // 第 6 组数据：终极测试，跑满 3000 的高压锅
    // ==========================================
    // 6. 满数据拉满，只有你的原地 O(n) 操作能跑出最优美的性能
    make_test_case(6, 3000, 3000, rng);

    cout << "6组测试数据全部生成完毕！" << endl;
    return 0;
}