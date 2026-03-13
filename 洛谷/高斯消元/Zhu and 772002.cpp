#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

// https://acm.hdu.edu.cn/showproblem.php?pid=5833

const int N = 303;
const int mod = 1e9 + 7;
int tt = 0;

vector<int> minp, primes;
void sieve(int n) {
    minp.assign(n + 1, 0);

    for(int i = 2; i <= n; i ++) {
        if(!minp[i]) {
            minp[i] = i;
            primes.emplace_back(i);
        }
        for(auto p : primes) {
            if(p * i > n) {
                break;
            }
            minp[p * i] = p;
            if(p == minp[i]) {
                break;
            }
        }
    }
}

int guass(int n, int m, auto &g) {
    for(int x = 1; x <= n; x ++) {
        for(int i = 1; i <= n; i ++) {
            if(i < x && g[i][i] == 1) {
                continue;
            }
            if(g[i][x] == 1) {
                swap(g[i], g[x]);
                break;
            }
        }

        if(g[x][x] == 0) {
            continue;
        }

        for(int i = 1; i <= n; i ++) {
            if(i != x && g[i][x] == 1) {
                g[i] ^= g[x];
            }
        }
    }

    int cnt = 0;
    for(int x = 1; x <= m; x ++) {
        if(g[x][x] == 0) {
            cnt ++;
        }
    }

    return cnt;
}

i64 qmi(i64 a, i64 b) {
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

void solve() {
    int n;
    cin >> n;
    
    vector g(N + 1, bitset<N + 2>());
    for(int j = 1; j <= n; j ++) {
        int x;
        cin >> x;

        for(int i = 0; i < primes.size(); i ++) {
            int p = primes[i];
            int cnt = 0;
            while(x % p == 0) {
                x /= p;
                cnt ++;
            }
            g[i + 1][j] = cnt & 1;
        }
    }

    int t = guass(N, n, g);
    int ans = qmi(2, t) - 1;
    if(ans < 0) {
        ans += mod;
    }

    cout << "Case #" << ++tt << ":\n";
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve(2000);
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}