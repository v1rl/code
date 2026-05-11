#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <fstream>

using namespace std;

mt19937 rng(random_device{}());
int rand_int(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

struct Submission {
    int t;
    char p;
    string v;
};

struct TestCase {
    int n, a, b;
    vector<Submission> subs;
};

// 你的标程逻辑（保持不变，完全正确）
int solve_testcase(const TestCase& tc) {
    int n = tc.n, a = tc.a, b = tc.b;
    vector<bool> is_ac(n, false);
    vector<int> rj_count(n, 0);
    vector<bool> has_pd(n, false);
    vector<int> potential_adds;

    int current_solved = 0;
    int current_penalty = 0;

    for (const auto& sub : tc.subs) {
        int p_idx = sub.p - 'A';
        if (is_ac[p_idx]) continue; 

        if (sub.v == "ac") {
            is_ac[p_idx] = true;
            current_solved++;
            current_penalty += sub.t + 20 * rj_count[p_idx];
        } else if (sub.v == "rj") {
            rj_count[p_idx]++;
        } else if (sub.v == "pd") {
            if (!has_pd[p_idx]) {
                has_pd[p_idx] = true;
                is_ac[p_idx] = true; 
                potential_adds.push_back(sub.t + 20 * rj_count[p_idx]);
            }
        }
    }

    sort(potential_adds.begin(), potential_adds.end());

    int ans = 0;
    int current_p = current_penalty;
    
    while (true) {
        if (current_solved + ans > a || (current_solved + ans == a && current_p < b)) {
            return ans;
        }
        if (ans < potential_adds.size()) {
            current_p += potential_adds[ans];
            ans++;
        } else {
            break;
        }
    }
    return -1;
}

int main() {
    for(int cs = 1; cs <= 20; cs ++) {
        string in_file = to_string(cs) + ".in";
        string out_file = to_string(cs) + ".out";
        ofstream fin(in_file);
        ofstream fout(out_file);

        if (!fin.is_open() || !fout.is_open()) {
            cerr << "Error: Cannot open files for writing!" << endl;
            return 1;
        }

        int T = rand_int(1, 100);
        fin << T << "\n";

        while (T--) {
            TestCase tc;
            tc.n = rand_int(10, 15);
            tc.a = rand_int(1, tc.n);
            tc.b = rand_int(0, 5000); // 你也可以根据题目难度稍微降低上限，比如 0~5000，更容易产生能反超的情况
            
            fin << tc.n << " " << tc.a << " " << tc.b << "\n";

            // 优化点：让提交总数 s 呈现多样性，涵盖提交少的队伍和提交多的队伍
            int s_type = rand_int(1, 10);
            int s = 0;
            if (s_type <= 2) s = rand_int(0, 50);          // 20% 概率：低活跃度队伍
            else if (s_type <= 7) s = rand_int(51, 300);   // 50% 概率：中等活跃度队伍
            else s = rand_int(301, 1000);                  // 30% 概率：高活跃度队伍（罚时战神）
            
            vector<int> times;
            for (int i = 0; i < s; ++i) {
                times.push_back(rand_int(0, 299));
            }
            sort(times.begin(), times.end());

            // 优化点：随机决定这个队伍的水平（AC率），避免所有题目都在封榜前被过掉
            int ac_prob = rand_int(1, 15); // AC 概率在 1% 到 15% 之间波动

            for (int i = 0; i < s; ++i) {
                int t = times[i];
                char p = 'A' + rand_int(0, tc.n - 1); 
                string v;

                if (t >= 240) {
                    v = "pd";
                } else {
                    int r = rand_int(1, 100);
                    if (r <= ac_prob) {
                        v = "ac";
                    } else {
                        v = "rj";
                    }
                }
                tc.subs.push_back({t, p, v});
            }

            fin << s << "\n";
            for (const auto& sub : tc.subs) {
                fin << sub.t << " " << sub.p << " " << sub.v << "\n";
            }

            int ans = solve_testcase(tc);
            fout << ans << "\n";
        }

        fin.close();
        fout.close();

        // 优化点：打印实际的文件名
        cout << "Successfully generated " << in_file << " and " << out_file << "!" << endl;
    }

    return 0;
}