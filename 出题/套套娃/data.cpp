#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <string>

using namespace std;

// 核心解法：用于生成标准输出 (.out)
// 注意这里必须使用 long long，否则标程自己也会溢出
void generate_case(int case_id, int n, const vector<long long>& a) {
    string in_file = to_string(case_id) + ".in";
    string out_file = to_string(case_id) + ".out";
    
    // 写入 .in 文件
    ofstream fin(in_file);
    fin << n << "\n";
    for (int i = 0; i < n; ++i) {
        fin << a[i] << (i == n - 1 ? "" : " ");
    }
    fin << "\n";
    fin.close();
    
    // 计算并写入 .out 文件
    ofstream fout(out_file);
    long long current_s = 0;
    long long current_p = 0;
    for (int i = 0; i < n; ++i) {
        current_s += a[i];
        current_p += current_s;
        fout << current_p << (i == n - 1 ? "" : " ");
    }
    fout << "\n";
    fout.close();
    
    cout << "Test case " << case_id << " generated. N = " << n << "\n";
}

int main() {
    // 随机数生成器 (使用固定种子保证每次生成的数据一致，方便复现)
    mt19937 rng(42);
    
    int n = 100000;
    int case_id = 1;

    // Case 1-3: N=100000, 完全随机的大数据 (卡 O(n^2) 暴力)
    uniform_int_distribution<long long> dist_random(0, 100000);
    for (int k = 0; k < 3; ++k) {
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) a[i] = dist_random(rng);
        generate_case(case_id++, n, a);
    }

    // Case 4: N=100000, 严格递增数据 (1 到 100000)
    {
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) a[i] = i + 1;
        generate_case(case_id++, n, a);
    }

    // Case 5: N=100000, 严格递减数据 (100000 到 1)
    {
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) a[i] = 100000 - i;
        generate_case(case_id++, n, a);
    }

    // Case 6: N=100000, 前一半全是 0，后一半全是 100000 
    // 测试前缀和前期的 0 堆积，防止某些剪枝错解
    {
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) a[i] = (i < n / 2) ? 0 : 100000;
        generate_case(case_id++, n, a);
    }

    // Case 7: N=100000, 离散极端点 (一半是0，一半是100000交替)
    {
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) a[i] = (i % 2 == 0) ? 0 : 100000;
        generate_case(case_id++, n, a);
    }

    // Case 8-9: N=100000, 逼近极限，值域在 [99990, 100000] 之间随机 (爆 int 杀手)
    uniform_int_distribution<long long> dist_extreme(99990, 100000);
    for (int k = 0; k < 2; ++k) {
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) a[i] = dist_extreme(rng);
        generate_case(case_id++, n, a);
    }

    // Case 10: N=100000, 绝对极限数据，所有 a_i 全部等于 100000 (最终压力测试，绝对爆 int)
    {
        vector<long long> a(n, 100000);
        generate_case(case_id++, n, a);
    }

    cout << "All 10 BIG data test cases generated successfully in the current directory!\n";
    return 0;
}