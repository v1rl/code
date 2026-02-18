#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
对于任意右括号，只要其右侧存在两左两右，左侧存在一个左，它就可以作为答案存在
在此基础上添加成对的括号，添加位置任意

(())()
选恰为两对合法括号的子序列，有多少种选法
*/

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> prel(n + 1), prer(n + 1);
    for(int i = 0; i < n; i ++) {
        prel[i + 1] = prel[i] + (s[i] == '(');
        prer[i + 1] = prer[i] + (s[i] == ')');
    }

    int ans = 0;
    for(int i = 0; i < n; i ++) {
        if(s[i] == ')') {
            if(prer[n] - prer[i + 1] >= prel[i] - prer[i] + 1) {
                ans = (prel[i] + 1) * 2 + min(prer[n] - prer[i + 1] - (prel[i] - prer[i] + 1), prel[n] - prel[i + 1]) * 2;
            }
        }
    }

    cout << (ans == 0 ? -1 : ans) << '\n';

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

