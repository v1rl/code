#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
暴力模拟的瓶颈在于高次数的K次分裂
考虑能否用批处理快速执行这个过程
注意到：可以将长度相同的棍子的分裂视作一个整体，且分裂过程类似一个完全二叉树
于是，将相等的棍子聚合起来执行分裂的复杂度是log(K)的
*/

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    map<double, int, greater<double>> mp;
    for(int i = 0; i < n; i ++) {
        double v;
        cin >> v;
        mp[v] ++;
    }

    while(k) {
        auto it = mp.begin();
        double val = it->first / 2;
        int c = it->second;

        if(k >= c) {
            mp[val] += 2 * c;
            mp.erase(it);
            k -= c;
        } else {
            mp[val] += 2 * k;
            it->second -= k;
            k = 0;
        }
    }

    for(auto [v, c] : mp) {
        if(x - c <= 0) {
            cout << v << '\n';
            break;
        }
        x -= c;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    cout<< fixed << setprecision(15);
    while(t --) {
        solve();
    }
    return 0;
}