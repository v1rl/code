#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <string>
#include <set>

using namespace std;

// 将你的代码修复 32 位溢出隐患后封装为标程
long long solve_std(int n, int m, int k, const vector<pair<int, int>>& queries) {
    set<int> Sx, Sy;
    for(int i = 0; i < k; i++) {
        int op = queries[i].first;
        int x = queries[i].second;
        if(op == 0) {
            Sx.insert(x);
        } else {
            Sy.insert(x);
        }
    }
    
    // 关键修复：最后面 Sx.size() * Sy.size() 前面加上了 1ll 强转
    long long safe_cells = 1ll * n * m - (1ll * Sx.size() * m + 1ll * Sy.size() * n - 1ll * Sx.size() * Sy.size());
    return safe_cells;
}

// 核心生成逻辑
void make_test_case(int id, int n, int m, int k, int op_mode, int coord_range_mode, mt19937_64& rng) {
    // coord_range_mode: 0 表示全图随机，1 表示集中在极小范围内（制造大量重复攻击）
    
    vector<pair<int, int>> queries(k);
    for(int i = 0; i < k; i++) {
        int op;
        if (op_mode == -1) op = rng() % 2; // 随机 0 或 1
        else op = op_mode;                 // 锁定为全 0 或全 1

        int max_coord = (op == 0) ? n : m;
        int min_coord = 1;
        
        // 如果是模式 1，强制把坐标压缩在 1 到 50 之间，制造疯狂重叠
        if (coord_range_mode == 1) {
            max_coord = min(max_coord, 50);
        }

        uniform_int_distribution<int> dist_x(min_coord, max_coord);
        queries[i] = {op, dist_x(rng)};
    }

    // --- 生成 .in 文件 ---
    string in_name = to_string(id) + ".in";
    ofstream fout_in(in_name);
    fout_in << n << " " << m << " " << k << "\n";
    for(int i = 0; i < k; i++) {
        fout_in << queries[i].first << " " << queries[i].second << "\n";
    }
    fout_in.close();

    // --- 运行标程，生成 .out 文件 ---
    long long ans = solve_std(n, m, k, queries);
    string out_name = to_string(id) + ".out";
    ofstream fout_out(out_name);
    fout_out << ans << "\n";
    fout_out.close();

    cout << "Test case " << id << " generated: " << in_name << " and " << out_name 
         << " (n=" << n << ", m=" << m << ", k=" << k << ", ans=" << ans << ")\n";
}

int main() {
    // 使用 64 位随机数发生器，防止在 10^9 范围内随机度不够
    mt19937_64 rng(20260327); 

    int max_N = 1000000000; // 10^9
    int max_K = 100000;     // 10^5

    cout << "开始生成测试数据..." << endl;

    // ==========================================
    // 6 组精心设计的测试点
    // ==========================================
    
    // 1. 基础小数据局：方便选手手动模拟和 Debug
    make_test_case(1, 100, 100, 50, -1, 0, rng);

    // 2. 满数据随机：一切拉满，最标准的强度测试
    make_test_case(2, max_N, max_N, max_K, -1, 0, rng);

    // 3. 极端偏科：纯粹的行攻击（op 全为 0），测试选手的逻辑分支是否会有空指针或除零等奇葩异常
    make_test_case(3, max_N, max_N, max_K, 0, 0, rng);

    // 4. 疯狂重叠：所有攻击全部集中在前 50 行和前 50 列，测试 set 的去重逻辑，如果写成 vector 会 MLE/TLE
    make_test_case(4, max_N, max_N, max_K, -1, 1, rng);

    // 5. 极端地图形状：极为狭长的走廊（n=1, m=10^9），测试行列极度不平衡时的边界处理
    make_test_case(5, 1, max_N, max_K, -1, 0, rng);

    // 6. 极限碰撞测试：刚好能把所有行列填满的极小地图 + 极大攻击次数，答案必须是 0
    make_test_case(6, 100, 100, max_K, -1, 0, rng);

    cout << "6组测试数据全部生成完毕！" << endl;
    return 0;
}