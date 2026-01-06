#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long

/*
找到当前有多少个1
离散地去确定加多少时会让总数多一个

按位存1的个数确定当前可以额外变成1的最小位置
Trie树确定最大可以是多少 X
32 * 32 大概1000
每次O(n)遍历找可以变化的最大值
*/

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> bit(35);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        int x = a[i];
        int cnt = 0;
        while(x) {
            bit[cnt ++] += x % 2;
            x /= 2;
        }
    }

    int mnpos = 0;
    for(int i = 0; i < 35; i ++) {
        if(!bit[i]) {
            mnpos = i;
            break;
        }
    }

    int base = 0;
    for(int i = 0; i < 35; i ++) {
        if(bit[i]) {
            base ++;
        }
    }

    // cerr << base << '\n';

    int res = 0;
    vector<int> stage;
    while(1) {
        int pos = 0;
        for(int i = 0; i < 35; i ++) {
            if(!bit[i]) {
                pos = i;
                break;
            }
        }


        // for(int i = 0; i < 31; i ++) {
        //     cerr << bit[i] << ' ';
        // }
        // cerr << '\n';
        // cerr << '\n';

        int mod = (1ll << (pos + 1));
        cout << mod << '\n';
        int mx = 0;
        int tar = 0;
        for(int i = 0; i < n; i ++) {
            if(mx < a[i] % mod) {
                mx = a[i] % mod;
                tar = i;
            }
        }
        // cout << pos << '\n';

        int nd = mod - mx;
        res += nd;
        a[tar] += nd;
        bit[pos] ++;

        // cerr << pos << '\n';

        int cnt = 0;
        while(mx) {
            bit[cnt] -= mx % 2;
            if(bit[cnt] == 0) {
                res += (1ll << cnt);
                a[tar] += (1ll << cnt);
                bit[cnt] = 1;
            }
            mx /= 2;
            cnt ++;
        }

        stage.emplace_back(res);

        if(base + stage.size() >= 32) {
            break;
        }
    }

    for(auto c : stage) {
        cout << c << '\n';
    }

    while(q --) {
        int x;
        cin >> x;
        // cout << x << '\n';
        int pos = upper_bound(stage.begin(), stage.end(), x) - stage.begin();
        // cout << pos << '\n';
        // cout << base + max(0ll, pos) << '\n';
    }

    // 111011100110101100101000000000
    // 000000000000000000001111111111


    // 1023 + 2048
    cout << 11263 + 4096 * 4;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}