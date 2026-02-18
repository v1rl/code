#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

/*
根据样例猜测x与y中有一个会被完全相等的值删去，不妨设这个值是x
于是只需要考虑剩下的另一个值y要怎么选取q
我们根据p&q=0的限制得到q的可选集sel，再列出参考集y，然后考虑分类讨论最优选择
若sel对应位为0，没得选，直接跳过
若sel对应位为1且y的对应位也为1，则必选，累计到sum中
若sel对应位为1且y对应位为0，在没遇上y为1sel为0的节点前，当前节点可选则作为进位补足点累计一次答案，之后则必选，累积到sum中
按照上述方式模拟即可
*/

const int inf = 1e9 + 10;

void solve() {
    int x, y;
    cin >> x >> y;
    bool f = false;

    if(x == 0 && y == 0) {
        cout << 0 << ' ' << 0 << '\n';
        return;
    }

    auto get = [&](int x, int y) -> array<int, 3> {
        int p = x, q;

        // 总共就31位，没有按照y的大小限制上界的必要
        int sel = (((1ll << 31) - 1) ^ x);

        int d = inf;
        int sum = 0;
        bool ok = true;

        for(int i = 30; i >= 0; i --) {
            if(!(sel >> i & 1)) {
                if(y >> i & 1) {
                    ok = false;
                }
                continue;
            }
            if(!ok) {
                sum += (1 << i);
            } else {
                if(y >> i & 1) {
                    sum += (1 << i);
                } else {
                    int cur = sum + (1 << i);
                    if(cur - y < d) {
                        d = cur - y;
                        q = cur;
                    }                
                }            
            }
        }

        if(y - sum < d) {
            q = sum;
            d = y - sum;
        }

        return {d, p, q};
    };

    auto a = get(x, y), b = get(y, x);
    if(a[0] < b[0]) {
        cout << a[1] << ' ' << a[2] << '\n';
    } else {
        cout << b[2] << ' ' << b[1] << '\n';
    }
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