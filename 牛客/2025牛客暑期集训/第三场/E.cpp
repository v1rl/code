#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 5e6 + 10;

vector<int> minp, primes;
void sieve(int n) {
    minp.assign(n + 1, 0);
    for(int i = 2; i <= n; i ++) {
        if(minp[i] == 0) {
            minp[i] = i;
            primes.emplace_back(i);
        }
        for(auto p : primes) {
            if(i * p > n) break;
            minp[i * p] = p;
            if(p == minp[i]) break;
        }
    }
}


void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> mp;

    auto divide = [&](int x) {
        while(x != 1) {
            int p = minp[x];
            mp[p] ++;
            x /= p;
        }
    };

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    if(n & 1) {
        cout << "YES" << '\n';
    } else if(n == 2 && a[1] != a[2]) {
        cout << "NO" << '\n';
    } else {
        for(int i = 1; i <= n; i ++) {
            divide(a[i]);
        }
        for(auto [_, c] : mp) {
            if(c & 1) {
                cout << "NO" << '\n';
                return;
            }
        }
        cout << "YES" << '\n';
    }

}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    sieve(5000000);
    while(t --)
    {
        solve();
    }
}