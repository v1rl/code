#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

// 三个的质因子之和一定要有奇数

vector<int> minp, primes;
void sieve(int n)
{
    minp.assign(n + 1, 0);
    for(int i = 2; i <= n; i ++)
    {
        if(minp[i] == 0)
        {
            minp[i] = i;
            primes.emplace_back(i);
        }
        for(auto p : primes)
        {
            if(i * p > n) break;
            minp[i * p] = p;
            if(p == minp[i]) break;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> p;
    auto ck = [&](int x) {
        if(minp[x] == x) {
            return true;
        }
        unordered_map<int, int> mp;
        while(x != 1) {
            int p = minp[x];
            mp[p] ++;
            x /= p;
        }

        int odd = 0;
        int even = 0;
        for(auto [_, t] : mp) {
            if(t & 1) odd ++;
            else even ++;
        }

        if(even && odd != 2 && odd != 0) {
            return true;
        }
        if(even == 0 && odd) {
            if(odd & 1) {
                return true;
            }
        }
        return false;
    };

    for(int i = 1; i <= n; i ++) {
        if(ck(i)) {
            p.emplace_back(i);
        }
    }

    for(auto x : p) {
        cout << x << ' ';
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    sieve(2000000);
    while(t --) {
        solve();
    }
}