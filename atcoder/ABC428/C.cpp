#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
主要难点在于回退操作
我们开一个数组记录当前执行到了多少步(不计回退)
每次发生成功的匹配时，当前步数设置记录
当从记录点开始回退时，向栈中加入左括号，取消当前点的记录
*/

const i64 inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> st(n + 1);
    vector<char> stk;
    int cnt = 0;
    int res = 0;
    while(n --) {
        int op;
        cin >> op;
        if(op == 1) {
            cnt ++;
            char x;
            cin >> x;
            if(x == ')') {
                if(stk.size() && stk.back() == '(') {
                    st[cnt] = true;
                    res ++;
                    stk.pop_back();
                } else {
                    stk.push_back(x);
                }
            } else {
                stk.push_back(x);
            }
        } else {
            if(st[cnt]) {
                stk.push_back('(');
                res --;
                st[cnt] = false;
            } else {
                stk.pop_back();
            }
            cnt --;
        }
        cout << (stk.empty() ? "Yes" : "No") << '\n';
        // cout << (res * 2 == cnt ? "Yes" : "No") << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
