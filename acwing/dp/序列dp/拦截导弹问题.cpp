#include<bits/stdc++.h>
using namespace std;

/*
最长下降子序列
等价于
不下降序列的最小划分
*/

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    string s;
    getline(cin, s);

    stringstream ssin(s);
    vector<int> a(100010);
    int n = 0;
    while(ssin >> a[n]) n ++;

    /*
    vector<int> f(n, 1);
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < i; j ++) {
            if(a[j] >= a[i]) f[i] = max(f[i], f[j] + 1);
        }
        ans = max(ans, f[i]);
    }
    */
    // 最长不上升子序列，等价为上升子序列的最小划分(得到的g序列是一个不上升序列)
    vector<int> g;
    for(int i = 0; i < n; i ++) {
        auto pos = upper_bound(g.begin(), g.end(), a[i], greater());
        if(pos == g.end()) {
            g.emplace_back(a[i]);
        } else {
            *pos = a[i];
        }
    }
    cout << g.size() << '\n';

    // 不上升子序列的最小划分(得到的g序列将是一个上升序列)
    g.clear();
    for(int i = 0; i < n; i ++) {
        auto pos = lower_bound(g.begin(), g.end(), a[i]);
        if(pos == g.end()) {
            g.emplace_back(a[i]);
        } else {
            *pos = a[i];
        }
    }
    cout << g.size() << '\n';

    return 0;
}