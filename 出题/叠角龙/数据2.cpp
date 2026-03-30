// #include <iostream>
// #include <vector>
// #include <fstream>
// #include <random>
// #include <string>
// #include <algorithm>
// #include <deque>

// using namespace std;

// const long long INF = 1e18;

// // 将你的单调队列代码封装为标程，用于生成绝对正确的 .out 文件
// // 注意：ans 和 pre 升级为了 long long，防止极端情况下的前缀和溢出
// long long solve_std(int n, int k, const vector<int>& a) {
//     vector<long long> pre(n + 1, 0);
//     for(int i = 1; i <= n; i ++) {
//         pre[i] = pre[i - 1] + a[i];
//     }

//     deque<int> q;
//     q.push_back(0);
//     long long ans = -INF; 
//     for(int i = 1; i <= n; i ++) {
//         if(!q.empty() && q.front() < i - k) {
//             q.pop_front();
//         }

//         ans = max(ans, pre[i] - pre[q.front()]);
        
//         while(!q.empty() && pre[q.back()] >= pre[i]) {
//             q.pop_back();
//         }
//         q.push_back(i);
//     }
//     return ans;
// }

// // 核心生成逻辑
// void make_test_case(int id, int n, int k, int min_a, int max_a, mt19937& rng) {
//     uniform_int_distribution<int> dist_a(min_a, max_a);
    
//     vector<int> a(n + 1);
//     for(int i = 1; i <= n; i++) {
//         a[i] = dist_a(rng);
//     }

//     // --- 生成 .in 文件 ---
//     string in_name = to_string(id) + ".in";
//     ofstream fout_in(in_name);
//     fout_in << n << " " << k << "\n";
//     for(int i = 1; i <= n; i++) {
//         fout_in << a[i] << (i == n ? "" : " ");
//     }
//     fout_in << "\n";
//     fout_in.close();

//     // --- 运行标程，生成 .out 文件 ---
//     long long ans = solve_std(n, k, a);
//     string out_name = to_string(id) + ".out";
//     ofstream fout_out(out_name);
//     fout_out << ans << "\n";
//     fout_out.close();

//     cout << "Test case " << id << " generated: " << in_name << " and " << out_name 
//          << " (n=" << n << ", k=" << k << ", ans=" << ans << ")\n";
// }

// int main() {
//     // 使用固定的随机种子，保证每次运行生成的测试数据都是一样的，方便复现
//     mt19937 rng(20260327); 

//     int a_min = -10000;
//     int a_max = 10000;

//     cout << "开始生成测试数据..." << endl;

//     // ==========================================
//     // 第 1 组数据：放过 O(n^2) 的做法 (n = 2000)
//     // ==========================================
//     make_test_case(1, 2000, 500, a_min, a_max, rng);

//     // ==========================================
//     // 后 5 组数据：满数据，卡掉 O(n^2) (n = 100000)
//     // ==========================================
    
//     // 2. 满数据：k = n 的退化情况（等价于无长度限制的最大子段和，贪心或简单DP即可过）
//     make_test_case(2, 100000, 100000, a_min, a_max, rng);
    
//     // 3. 满数据：k = 1 的极端情况（只能单点斩杀，找全局最大值即可）
//     make_test_case(3, 100000, 1, a_min, a_max, rng);
    
//     // 4. 满数据：卡人必修课 —— 全局都是负数（答案应为受损最小的单个单位）
//     // 这点尤其针对初始化为 0 的错误做法
//     make_test_case(4, 100000, 50000, -10000, -1, rng);
    
//     // 5. 满数据：k 较小，窗口滑动极其频繁，强制单调队列不停做 push 和 pop
//     make_test_case(5, 100000, 10, a_min, a_max, rng);
    
//     // 6. 满数据：标准强度测试，数据正负交替波动极大，k 为中等规模
//     make_test_case(6, 100000, 30000, a_min, a_max, rng);

//     cout << "6组测试数据全部生成完毕！" << endl;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <string>
#include <deque>

using namespace std;

// 正确标程：单调队列求最大子段和
long long solve_std(int n, int k, const vector<long long>& a) {
    vector<long long> pre(n + 1, 0);
    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];

    deque<int> q;
    q.push_back(0);
    long long ans = -1e18; 
    for(int i = 1; i <= n; i++) {
        if(!q.empty() && q.front() < i - k) q.pop_front();
        ans = max(ans, pre[i] - pre[q.front()]);
        while(!q.empty() && pre[q.back()] >= pre[i]) q.pop_back();
        q.push_back(i);
    }
    return ans;
}

// 核心 Hack 逻辑：合规的对称两端陷阱
void make_strict_hack_case(int id, int n, int k, mt19937_64& rng) {
    // 整个数组填充极度深寒的毒药 -10000，防止他在别的地方乱凑
    vector<long long> a(n + 1, -10000);
    
    // 确保 k 至少大于等于 4 才能布置分流陷阱
    if (k < 4) k = 4;

    // 随机选一个位置埋放长度为 k+4 的陷阱组
    uniform_int_distribution<int> dist_pos(1, n - (k + 4));
    int pos = dist_pos(rng);
    
    // 1. 左侧诱饵与毒药
    a[pos] = 10000;
    a[pos + 1] = -10000;
    
    // 2. 核心真实区间 Z (将 19800 的总和分摊到两端)
    a[pos + 2] = 5000;
    a[pos + 3] = 4900;
    
    for (int i = 4; i <= k - 1; i++) {
        a[pos + i + 1] = 0; // 中间填0，凑足长度且不增加前期权重
    }
    
    a[pos + k] = 4900;
    a[pos + k + 1] = 5000;
    
    // 3. 右侧毒药与诱饵 (用来卡死他的 reverse 反向遍历)
    a[pos + k + 2] = -10000;
    a[pos + k + 3] = 10000;

    // --- 生成 .in 文件 ---
    string in_name = to_string(id) + ".in";
    ofstream fout_in(in_name);
    fout_in << n << " " << k << "\n";
    for(int i = 1; i <= n; i++) fout_in << a[i] << (i == n ? "" : " ");
    fout_in << "\n";
    fout_in.close();

    // --- 运行标程，生成 .out 文件 ---
    long long ans = solve_std(n, k, a);
    string out_name = to_string(id) + ".out";
    ofstream fout_out(out_name);
    fout_out << ans << "\n";
    fout_out.close();

    cout << "合规 Hack 数据 " << id << " 生成完毕！" 
         << " | 假做法必定输出: 10000" 
         << " | 标程真实答案: " << ans << "\n";
}

int main() {
    mt19937_64 rng(20260327); 

    cout << "--- 开始生成严格合规的 Hack 数据 ---" << endl;

    // 生成一组满数据强度的绝杀数据
    make_strict_hack_case(7, 100000, 10, rng);
    
    // 再生成一组 k 极大的绝杀数据
    make_strict_hack_case(8, 100000, 50000, rng);

    cout << "--- 生成完毕！ ---" << endl;
    return 0;
}