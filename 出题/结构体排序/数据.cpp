#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <string>
#include <algorithm>

using namespace std;

// 选手结构体
struct Player {
    string name;
    int kills;
    int damage;
    int time;
};

// 标程的排序逻辑
bool cmp(const Player& a, const Player& b) {
    if (a.kills != b.kills) return a.kills > b.kills;
    if (a.damage != b.damage) return a.damage > b.damage;
    if (a.time != b.time) return a.time > b.time;
    return a.name < b.name;
}

// 随机生成长度在 5 到 15 之间的玩家代号
string generate_name(mt19937& rng) {
    uniform_int_distribution<int> len_dist(5, 15);
    uniform_int_distribution<int> char_dist(0, 25);
    uniform_int_distribution<int> case_dist(0, 1);
    
    int len = len_dist(rng);
    string name = "";
    for (int i = 0; i < len; i++) {
        char base = case_dist(rng) ? 'A' : 'a';
        name += (char)(base + char_dist(rng));
    }
    return name;
}

// 核心生成逻辑
void make_test_case(int id, int n, int mode, mt19937& rng) {
    vector<Player> players(n);
    
    // 基础随机分布
    uniform_int_distribution<int> kills_dist(0, 100);
    uniform_int_distribution<int> dmg_dist(0, 9999);
    uniform_int_distribution<int> time_dist(0, 3000);

    for (int i = 0; i < n; i++) {
        players[i].name = generate_name(rng);
        
        if (mode == 1 || mode == 2) {
            // 正常随机
            players[i].kills = kills_dist(rng);
            players[i].damage = dmg_dist(rng);
            players[i].time = time_dist(rng);
        } else if (mode == 3) {
            // 击杀数高度重合 (例如只有 0, 1, 2 三种可能)
            players[i].kills = kills_dist(rng) % 3;
            players[i].damage = dmg_dist(rng);
            players[i].time = time_dist(rng);
        } else if (mode == 4) {
            // 击杀数和伤害高度重合
            players[i].kills = 20;
            players[i].damage = dmg_dist(rng) % 5 * 1000; 
            players[i].time = time_dist(rng);
        } else if (mode == 5) {
            // 击杀、伤害、时间全部极度重合，疯狂逼迫比较字典序
            players[i].kills = 99;
            players[i].damage = 9999;
            players[i].time = 3000;
        } else if (mode == 6) {
            // 综合高压测试，有随机也有大量完全一致的数据
            if (i % 2 == 0) {
                players[i].kills = 50;
                players[i].damage = 4000;
                players[i].time = 1500;
            } else {
                players[i].kills = kills_dist(rng);
                players[i].damage = dmg_dist(rng);
                players[i].time = time_dist(rng);
            }
        }
    }

    // --- 生成 .in 文件 ---
    string in_name = to_string(id) + ".in";
    ofstream fout_in(in_name);
    fout_in << n << "\n";
    for (int i = 0; i < n; i++) {
        fout_in << players[i].name << " " 
                << players[i].kills << " " 
                << players[i].damage << " " 
                << players[i].time << "\n";
    }
    fout_in.close();

    // --- 运行标程，生成 .out 文件 ---
    sort(players.begin(), players.end(), cmp);
    string out_name = to_string(id) + ".out";
    ofstream fout_out(out_name);
    for (int i = 0; i < n; i++) {
        fout_out << players[i].name << "\n";
    }
    fout_out.close();

    cout << "Test case " << id << " generated: " << in_name << " and " << out_name 
         << " (n=" << n << ", mode=" << mode << ")\n";
}

int main() {
    mt19937 rng(20260327); 

    cout << "开始生成测试数据..." << endl;

    // 1. 小数据福利局：放过 O(n^2) 的冒泡/选择排序 (n=2000)
    make_test_case(1, 2000, 1, rng);

    // 2. 满数据常规局：测试 O(n log n) 的 sort，数据全随机 (n=100000)
    make_test_case(2, 100000, 2, rng);

    // 3. 击杀相同局：大量选手的击杀数一样，逼迫程序比较“伤害”
    make_test_case(3, 100000, 3, rng);

    // 4. 击杀+伤害相同局：逼迫程序比较“存活时间”
    make_test_case(4, 100000, 4, rng);

    // 5. 极端同分局：所有人的战斗数据一模一样！专门用来卡掉忘记写“字典序比较”的选手
    make_test_case(5, 100000, 5, rng);

    // 6. 综合高压局：一半数据相同，一半随机，防投机取巧
    make_test_case(6, 100000, 6, rng);

    cout << "6组测试数据全部生成完毕！" << endl;
    return 0;
}