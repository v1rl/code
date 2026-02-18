#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
区间约束问题，考虑用 双指针/前后缀 维护信息
题目转换为前缀A个数相减>前缀B个数相减
暴力枚举左端点不可取，移项得到C=A-B，所有符合条件的区间在C数组中满足左右端点为顺序对
题意转换为求顺序对个数O(nlogn)
注意到：本题每次C的扩展变化只会是+1/-1/0
所以，可以配合桶数组O(n)维护答案
*/

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> bk(2 * n + 1);
    int sum = 0;
    i64 ans = 0;
    int c = n;
    bk[c] ++;
    for(int i = 0; i < n; i ++) {
        if(s[i] == 'A') {
            c ++;
            sum += bk[c - 1];
        } else if(s[i] == 'B') {
            c --;
            sum -= bk[c];
        }
        ans += sum;
        bk[c] ++;
    }
    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(15);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}