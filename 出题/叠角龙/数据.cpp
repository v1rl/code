#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <string>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

// 将你的代码封装为标程，用于生成 .out 文件
// 注意：这里将累加和升级为了 long long，防止大数据溢出
long long solve_std(int n, int m, int k, const vector<int>& a) {
    vector<long long> f(n + 1, 0);
    long long mx = 0; // 初始化为0，完美契合"空放策略"（都不选收益为0）
    
    for(int i = 1; i <= n; i ++) {
        f[i] = max(f[i - 1], (long long)min(m, a[i]));
        if(i > k) {
            f[i] = max(f[i], f[i - k - 1] + min(m, a[i]));
        }
        mx = max(mx, f[i]);
    }
    return mx;
}

// 核心生成逻辑
void make_test_case(int id, int n, int m, int k, int min_a, int max_a, mt19937& rng) {
    uniform_int_distribution<int> dist_a(min_a, max_a);
    
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        a[i] = dist_a(rng);
    }

    // --- 生成 .in 文件 ---
    string in_name = to_string(id) + ".in";
    ofstream fout_in(in_name);
    fout_in << n << " " << m << " " << k << "\n";
    for(int i = 1; i <= n; i++) {
        fout_in << a[i] << (i == n ? "" : " ");
    }
    fout_in << "\n";
    fout_in.close();

    // --- 运行标程，生成 .out 文件 ---
    long long ans = solve_std(n, m, k, a);
    string out_name = to_string(id) + ".out";
    ofstream fout_out(out_name);
    fout_out << ans << "\n";
    fout_out.close();

    cout << "Test case " << id << " generated: " << in_name << " and " << out_name 
         << " (n=" << n << ", ans=" << ans << ")\n";
}

int main() {
    // 使用固定的随机种子，保证每次运行生成的测试数据都是一样的，方便复现
    mt19937 rng(19990101); 

    int m_max = 10000;
    int a_min = -10000;
    int a_max = 15000;

    cout << "开始生成测试数据..." << endl;

    // ==========================================
    // 前 2 组数据：放过 O(n^2) 的做法 (n <= 2000)
    // ==========================================
    // 1. 基础随机小数据
    make_test_case(1, 1000, 5000, 2, a_min, a_max, rng);
    // 2. 较多负数的小数据，冷却时间较长
    make_test_case(2, 2000, 10000, 50, -10000, 5000, rng);

    // ==========================================
    // 后 4 组数据：满数据，卡掉 O(n^2) (n = 100000)
    // ==========================================
    // 3. 满数据：无冷却时间 (k=0) 的退化情况
    make_test_case(3, 100000, 8000, 0, a_min, a_max, rng);
    
    // 4. 满数据：极端情况，全部都是负数（答案应为0）
    make_test_case(4, 100000, 10000, 5, -10000, -1, rng);
    
    // 5. 满数据：冷却时间极长，只能放几个技能
    make_test_case(5, 100000, 10000, 30000, a_min, a_max, rng);
    
    // 6. 满数据：标准强度测试，数据波动极大，包含大量超模小兵 (a_i > m)
    make_test_case(6, 100000, 5000, 3, -10000, 50000, rng);

    cout << "6组测试数据生成完毕！" << endl;
    return 0;
}