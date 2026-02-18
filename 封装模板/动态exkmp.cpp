#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
一个后缀子串在动态增长过程中Z函数未定等价于该后缀子串是当前字符串的一个border
通过维护kmp中当前字符串的最长border数组ne，得到当前字符串Z函数未定的最长后缀子串
正如当前字符串的所有border都可以通过j=ne[j-1]的递推得到，当前字符串所有未定的后缀子串也都可以通过j=ne[j-1]的递推得到
若s[i]!=s[j]，该后缀对应的后缀子串Z函数大小从此固定
若s[i]=s[j]，该后缀对应的后缀子串Z函数大小仍可能继续增长
但如果每次都将j递推到等于0，时间复杂度会退化到平方级别
我们知道kmp之所以能做到O(n)，是因为它在第一次s[i]=s[j]时就停止了递推
注意到：第一次s[i]=s[j]时，剩余的Z函数大小固定的后缀子串全都在fails[j]中，递推依然可以在这里停止
于是，我们便以O(n)的复杂度解决本题
*/

void solve() {
    int n;
    cin >> n;
    vector<int> ne(n);
    vector<int> z(n, -1);
    vector<char> s(n);
    vector<vector<int>> fails(n);

    for(int i = 0, j = 0; i < n; i ++) {
        cin >> s[i];
        if(i > 0) {
            while(j && s[i] != s[j]) {
                fails[i].emplace_back(j);
                j = ne[j - 1];
            }
            if(s[i] == s[j]) {
                for(auto x : fails[j]) {
                    fails[i].emplace_back(x);
                }
                j ++;
            } else {
                fails[i].emplace_back(j);
            }
            ne[i] = j;
        }

        for(auto x : fails[i]) {
            z[i - x] = x;
        }
    }

    for(int i = 0; i < n; i ++) {
        if(z[i] == -1) {
            z[i] = n - i;
        }
    }

    for(int i = 0; i < n; i ++) {
        cout << i << ' ' << z[i] << '\n';
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
