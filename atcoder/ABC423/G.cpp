#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

/*

*/

i64 qmi(i64 a, i64 b, i64 mod) {
    i64 res = 1;
    while(b) {
        if(b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

i64 exgcd(i64 a, i64 b, i64 &x, i64 &y) {
    if(!b) {
        x = 1, y = 0;
        return a;
    }
    i64 g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

void solve() {
    string s, t;
    cin >> t >> s;

    int k = stoi(t);
    i64 snum = 0;
    for(auto c : s) {
        snum = (snum * 10 + (c - '0')) % k;
    }
    int sz = s.size();

    string ans;
    auto cal = [&](const string &res) -> void {
        if(ans.empty() || make_pair(res.size(), res) < make_pair(ans.size(), ans)) {
            ans = res;
        }
    };

    auto mkSuf = [&](i64 v, i64 l) -> string {
        string res = (v == 0 ? "" : to_string(v));
        return string(l - res.length(), '0') + res;
    };

    auto lce = [&](i64 x, i64 g, i64 b) -> i64 {
        if(b % g != 0) {
            return -1;
        }

        i64 b0 = b / g, m0 = k / g;

        x = (b0 * x % m0 + m0) % m0;
        return x;
    };

    vector<i64> p10(11);
    p10[0] = 1;
    for(int i = 1; i < 11; i ++) {
        p10[i] = p10[i - 1] * 10;
    }

    // k最大为1e9，只需要9位就够了
    // i代表后缀一定是i位
    // 因为后缀可以存在前导0，所以折半枚举过程中后缀位数总是固定的
    for(int i = 0; i <= 9; i ++) {
        i64 mnP = -1, mnQ = -1;
        i64 A = qmi(10, sz + i, k);
        i64 B = (i64)qmi(10, i, k) * snum % k;

        i64 x, y;
        i64 g = exgcd(A, k, x, y);

        if(i <= 9 - i) {
            int limit = p10[i];
            // 枚举后缀大小（位数固定为i）
            for(i64 Q = 0; Q < limit; Q ++) {
                i64 P = lce(x, g, (-Q - B) % k);
                if(P != -1 && P < p10[9 - i]) {
                    // 已确定这轮循环中后缀一定是i位，因此可以直接做下方的比较
                    if(mnP == -1 || make_pair(P, Q) < make_pair(mnP, mnQ)) {
                        mnP = P;
                        mnQ = Q;
                    }
                }
            }
        } else {
            int l = 9 - i;
            int limit = p10[l];
            // 枚举前缀大小（位数随大小变动）
            for(i64 P = 0; P < limit; P ++) {
                i64 Q = (-B - P * A % k) % k;
                if(Q < 0) {
                    Q += k;
                }
                if(Q < p10[i]) {
                    if(mnP == -1 || make_pair(P, Q) < make_pair(mnP, mnQ)) {
                        mnP = P;
                        mnQ = Q;
                    }          
                }
            }
        }
        if(mnP != -1) {
            string pre = (mnP == 0 ? "" : to_string(mnP));
            string suf = mkSuf(mnQ, i);
            cal(pre + s + suf);            
        }
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