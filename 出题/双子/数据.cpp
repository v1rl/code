#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <string>
#include <algorithm>

using namespace std;

// 使用你的核心逻辑生成绝对正确的答案
string solve_std(int n, int m, int k, const vector<int>& a, const vector<int>& b) {
    int i = 1, j = 0;
    while(1) {
        int cnt = 0;
        while(j < m && abs(b[j] - a[i - 1]) <= k) {
            cnt++;
            j++;
        }
        while(i < n && abs(a[i] - b[j - 1]) <= k) {
            i++;
            cnt++;
        }
        if(!cnt) break;
    }
    if(i == n && j == m) return "WIIIIIN?";
    else return "LOOOOSE!";
}

// 核心生成逻辑
void make_multi_test_file(int id, int T, int sum_limit, int k_base, int mode, mt19937& rng) {
    string in_name = to_string(id) + ".in";
    string out_name = to_string(id) + ".out";
    ofstream fout_in(in_name);
    ofstream fout_out(out_name);

    fout_in << T << "\n";

    int current_sum_n = 0;
    
    cout << "正在生成测试点 " << id << "..." << flush;

    for (int t = 0; t < T; t++) {
        int n, m;
        // 分配 n 和 m 的大小，保证 sum_n 和 sum_m 不超过 sum_limit
        if (t == T - 1) {
            n = m = max(10, sum_limit - current_sum_n); // 最后一组吃掉剩余的额度
        } else {
            uniform_int_distribution<int> dist_nm(10, (sum_limit - current_sum_n) / (T - t));
            n = m = dist_nm(rng);
        }
        current_sum_n += n;

        // 随机生成 k
        uniform_int_distribution<int> dist_k(k_base / 2, k_base);
        int k = dist_k(rng);

        vector<int> a(n), b(m);
        
        // 保证起始点满足条件 |a[0] - b[0]| <= k
        uniform_int_distribution<int> dist_start(1, 10000);
        a[0] = dist_start(rng);
        uniform_int_distribution<int> dist_b0(max(1, a[0] - k), a[0] + k);
        b[0] = dist_b0(rng);

        // 决定单组数据的生成策略
        int sub_mode = mode;
        if (mode == 6) { // 综合测试点随机模式
            uniform_int_distribution<int> dist_sub(1, 4);
            sub_mode = dist_sub(rng);
        }

        // 严格升序生成数据
        if (sub_mode == 1) { // 稳赢局 (步子小)
            uniform_int_distribution<int> step(1, max(1, k / 2));
            for(int i = 1; i < n; i++) a[i] = a[i - 1] + step(rng);
            for(int j = 1; j < m; j++) b[j] = b[j - 1] + step(rng);
        } 
        else if (sub_mode == 2) { // 必输局 (蓝方步子太大)
            uniform_int_distribution<int> step_a(1, max(1, k / 2));
            uniform_int_distribution<int> step_b(k + 1, k * 2);
            for(int i = 1; i < n; i++) a[i] = a[i - 1] + step_a(rng);
            for(int j = 1; j < m; j++) b[j] = b[j - 1] + step_b(rng);
        } 
        else if (sub_mode == 3) { // 坑爹局 (终点前断裂)
            uniform_int_distribution<int> step(1, max(1, k / 2));
            for(int i = 1; i < n; i++) {
                if (i == n * 9 / 10) a[i] = a[i - 1] + k * 2 + 1; // 鸿沟
                else a[i] = a[i - 1] + step(rng);
            }
            for(int j = 1; j < m; j++) b[j] = b[j - 1] + step(rng);
        } 
        else if (sub_mode == 4) { // 极限拉扯局 (踩着 k 的边缘)
            for(int i = 1; i < n; i++) a[i] = a[i - 1] + k - 1;
            for(int j = 1; j < m; j++) b[j] = b[j - 1] + k - 1;
        }

        // 写入 .in
        fout_in << n << " " << m << " " << k << "\n";
        for (int i = 0; i < n; i++) fout_in << a[i] << (i == n - 1 ? "" : " ");
        fout_in << "\n";
        for (int j = 0; j < m; j++) fout_in << b[j] << (j == m - 1 ? "" : " ");
        fout_in << "\n";

        // 写入 .out
        fout_out << solve_std(n, m, k, a, b) << "\n";
    }

    fout_in.close();
    fout_out.close();
    cout << " 完成！(生成了 " << T << " 组数据, 总 n=" << current_sum_n << ")" << endl;
}

int main() {
    mt19937 rng(20260327); 

    cout << "--- 开始生成 6 组强力多测数据 ---" << endl;

    // 1. 福利局：T较小，总 N 也小，用来放过不加优化的 O(N^2) (例如循环找最近点)
    make_multi_test_file(1, 10, 2000, 1000, 6, rng);

    // 2. 纯通关局：全都是步子很小的良性数据，用来给测试点送分
    make_multi_test_file(2, 50, 100000, 5000, 1, rng);

    // 3. 陷阱局：大量 90% 进度处断裂的数据，防错误贪心
    make_multi_test_file(3, 100, 200000, 2000, 3, rng);

    // 4. 极限拉扯局：全都是踩着 K 的边缘跳跃，防 <= 写成 < 的错别字
    make_multi_test_file(4, 100, 200000, 100, 4, rng);

    // 5. 巨大范围局：K 极大，考验 int 是否会越界的问题 (虽然都在 1e9 内)
    make_multi_test_file(5, 100, 200000, 10000000, 6, rng);

    // 6. 究极综合高压锅：混合各种模式，T 和 N 拉满
    make_multi_test_file(6, 100, 200000, 5000, 6, rng);

    cout << "--- 6 组数据全部生成完毕，快去 OJ 配置吧！ ---" << endl;
    return 0;
}