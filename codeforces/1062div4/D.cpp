#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
答案一定是素数
只要有一个数没有该质因子便成立
考虑暴力
*/

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
    vector<i64> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for(auto i : primes) {
        for(int j = 0; j < n; j ++) {
            if(a[j] % i != 0) {
                cout << i << '\n';
                return;
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    sieve(10000);
    while(t --) {
        solve();
    }
    return 0;
}