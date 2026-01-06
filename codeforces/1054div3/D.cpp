#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;
/*
a往外和b往外取min
找到一个分界点，左边的往左、右边的往右一定最优，这似乎符合三分
经过血的教训，本题答案并不符合三分

所以往外有两个方向，不好决策
但是内部一定是连在一起的
所以求往中位数汇合的距离，取较小值
*/

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a, b;
    for(int i = 0; i < n; i ++) {
        if(s[i] == 'a') {
            a.emplace_back(i);
        } else {
            b.emplace_back(i);
        }
    }

    i64 ans = inf;
    if(a.size()) {
        int pos = a.size() / 2;
        int mid = a[pos];
        i64 res = 0;
        for(auto c : a) {
            res += abs(c - mid); 
        }
        if(a.size() & 1) {
            res -= 1ll * pos * (pos + 1);
        } else {
            res -= 1ll * pos * (pos + 1) / 2;
            res -= 1ll * pos * (pos - 1) / 2;
        }
        ans = res;
    }
    if(b.size()) {
        int pos = b.size() / 2;
        int mid = b[pos];
        i64 res = 0;
        for(auto c : b) {
            res += abs(c - mid);
        }
        if(b.size() & 1) {
            res -= 1ll * pos * (pos + 1);
        } else {
            res -= 1ll * pos * (pos + 1) / 2;
            res -= 1ll * pos * (pos - 1) / 2;
        }
        ans = min(ans, res);
    }

    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}