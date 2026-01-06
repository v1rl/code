#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long

/*
成对，随意
最多可以有两个单
*/


// 110 -> 1101 1011
// 1100 -> 111011 110111
// 1110
// 1111 -> 1010 0101
// 110110 -> 1 01 1 10 1 1  1011011  1101101 

// 01010 -> 10011 11001
// 10101 -> 

// 连续的1是偶数个
// 右侧的0只会是由两个1构成的，这也就代表着

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int lst = -1;
    int num = 0;

    i64 sum = 0;
    int eg = 0;
    vector<int> odds;
    for(int i = 0; i < n; i ++) {
        if(a[i] == lst) {
            num ++;
        } else {
            sum += num / 2 * 2 * lst;
            eg += num / 2 * 2;
            if(num & 1) {
                odds.emplace_back(lst);
            }
            num = 1;
        }
        lst = a[i];
    }

    sum += num / 2 * 2 * lst;
    eg += num / 2 * 2;
    if(num & 1) {
        odds.emplace_back(lst);
    }

    i64 ans = sum;

    if(odds.empty()) {
        cout << ans << '\n';
        return;
    }

    for(int i = odds.size() - 1; i >= 0; i --) {
        if(odds[i] < sum) {
            eg ++;
            ans = max(ans, sum + odds[i]);
        }
        auto t = lower_bound(odds.begin(), odds.end(), odds[i] + sum);
        if(t == odds.begin()) {
            continue;
        }
        t --;
        if(*t <= odds[i]) {
            continue;
        }
        ans = max(ans, sum + odds[i] + *t);
        eg ++;
    }

    if(eg > 2) {
        cout << ans << '\n';
    } else {
        cout << 0 << '\n';
    }
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