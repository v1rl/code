#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/

void solve() {
    i64 l, r;
    cin >> l >> r;
    i64 x = r;
    int num = 0;
    while(x) {
        num ++;
        x /= 10;
    }

    vector<i64> p10(17);
    p10[0] = 1;
    for(int i = 1; i <= 16; i ++) {
        p10[i] = p10[i - 1] * 10;
    }

    auto work = [&](i64 l, i64 r) -> i64 {
        string s = to_string(l);

        i64 bs = 0;
        int cnt = 0;

        int p = 16;
        while(p --) {
            for(int i = 9; i >= 0; i --) {
                i64 cur = i * p10[cnt] + bs;

                string t = to_string(cur);
                int l = s.size() - t.size();
                if(l > 0) {
                    t = s.substr(0, l) + t;
                }

                i64 g = stoll(t);
                if(g < l) {
                    g += p10[cnt + 1];
                }

                if(g <= r) {
                    bs = cur;
                    break;
                }
            }

            cnt ++;
        }

        i64 ans = 0;
        while(bs) {
            ans *= 10;
            ans += bs % 10;
            bs /= 10;
        }
        return ans;
    };

    if(p10[num - 1] != r && p10[num - 1] > l) {
        l = p10[num - 1];
    }
    cout << work(l, r) << '\n';
    
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