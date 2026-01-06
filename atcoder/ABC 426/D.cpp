#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
一个在两侧，一个在内部时可以直接得到答案
按照这个思路，一个比较显然的做法就是找一串最长连续的1...0...1...或0...1...0...，它们不变，其余的向它们靠拢
但这样比较麻烦，考虑在最开始优化思路
让一串连续的0或连续的1不变，其余所有数向它靠拢，不同的数变化一次，相同的数变化两次
这样，维护不变的那一串数时就会简单很多
同时，因为我们只需要数量，所以直接用总数操作会更容易
*/

const int inf = 1e9;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int n1 = 0, n0 = 0;
    for(auto c : s) {
        if(c == '0') {
            n0 ++;
        } else {
            n1 ++;
        }
    }

    int m1 = 0, m0 = 0;
    int num0 = 0, num1 = 0;
    for(int i = 0; i < n; i ++) {
        if(i == 0) {
            s[i] == '0' ? num0 ++ : num1 ++;
        }
        if(s[i] == s[i - 1]) {
            s[i] == '0' ? num0 ++ : num1 ++;
        } else {
            m1 = max(num1, m1);
            m0 = max(num0, m0);
            num0 = 0, num1 = 0;
            s[i] == '0' ? num0 ++ : num1 ++;
        }
    }
    m1 = max(num1, m1);
    m0 = max(num0, m0);

    // cout << n0 << ' ' << m0 << ' ' << n1 << ' ' << m1 << '\n';

    int ans = min((n0 - m0) * 2 + n1, (n1 - m1) * 2 + n0);
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