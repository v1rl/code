#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

const int mod = 1e9 + 7;

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
    for(auto c : primes) {
        if(c % 10 == 1) {
            cout << c << ' ';
            n --;
        }
        if(!n) {
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    sieve(1000000);
    while(t --) {
        solve();
    }


    return 0;
}
