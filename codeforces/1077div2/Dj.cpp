#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
最优解是p、q恰好可以等于x、y
但p、q有p&q=0的限制，这也就代表着可能会有一些原本为1的点不得不改成0，使得p/q的值相比最优值变小
为了这样的改动对绝对值的影响最小，我们考虑尽可能做补正让p/q的值变大一些

注意到：这样的执行补正的"数位"只有一个，不妨将它看作一个补正点
因为是绝对值，我们要考虑补正不超过原最优值和超过原最优值两种情况
补正后不超过原最优值，则该分界点数位后的所有点设为1
补正后超过原最优值，则该分解点数位后的所有点设为0，且该分界点本身设为1

我们的目标是分别找到x、y的最优补正点和补正操作，直接贪心寻找很困难
我们考虑将根据性质的贪心抉择问题转为根据结构的暴力查找问题
不存在补正点的情况被补正点为0所包含
按照这样的结构暴力枚举补正点，然后取答案最优的情况即可
*/

const int inf = 1e9 + 10;

void solve() {
    int x, y;
    cin >> x >> y;
    int ans = x + y;
    int p = 0, q = 0;
    for(int i = 0; i <= 30; i ++) {
        for(int j = 0; j <= 30; j ++) {
            int a = x >> i << i;
            int b = y >> j << j;
            int bsA = 1 << i, bsB = 1 << j;
            for(auto P : {a | bsA, a + bsA - 1}) {
                for(auto Q : {b | bsB, b + bsB - 1}) {
                    Q -= P & Q;
                    int c = abs(P - x) + abs(Q - y);
                    if(c < ans) {
                        ans = c;
                        p = P;
                        q = Q;
                    }
                }
            }
        }
    }
    cout << p << ' ' << q << '\n';
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