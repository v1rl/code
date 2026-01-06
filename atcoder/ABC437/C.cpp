#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
题意要求W部分求和小于等于P部分求和的情况下，W部分的个数尽可能多
直观地说，W越小越是适合放到W部分，P越大越适合放到P部分
但同一个物件具有这两种属性，需要同时满足两条贪心规则
我们考虑是否存在数学变换，能够将这两种贪心规则聚合起来
注意到它们补集的重合关系，我们可以通过数学转换得到约束 W部分的W+P <= 全体的P
按照W+P排序即可
*/

void solve() {
    int n;
    cin >> n;
    i64 sum = 0;
    vector<int> s(n);
    for(int i = 0; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        s[i] = x + y;
        sum += y;
    } 
    sort(s.begin(), s.end());
    int ans = 0;
    i64 res = 0;
    for(int i = 0; i < n; i ++) {
        res += s[i];
        if(res > sum) {
            break;
        }
        ans ++;
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
