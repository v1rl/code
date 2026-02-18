#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    while(n --) {
        int x;
        cin >> x;
        for(int i = 2; i <= x / i; i ++) {
            if(x % i == 0) {
                int res = 0;
                while(x % i == 0) {
                    x /= i;
                    res ++;
                }
                mp[i] += res;
            }
        }
        if(x > 1) mp[x] ++;
    }

    i64 ans = 1;
    for(auto [x, num] : mp) {
        i64 p = 1;
        i64 res = 1;
        for(int i = 1; i <= num; i ++) {
            p = p * x % mod;
            res = (res + p) % mod;
        }
        ans = (ans * res) % mod;
    }
    cout << ans << '\n';
}