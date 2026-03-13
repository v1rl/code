#include<bits/stdc++.h> 
#include<string.h> 
using namespace std; 
using i64 = long long;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

i64 random(i64 l,i64 r) { 
    return (rng() - l) % (r - l + 1) + l;
}

const int N = 2e5 + 10;
const int inf = 1e9;
int n, q;
i64 pre[N];
array<int, 3> vec[N];

void get() {
    n = random(100000, 200000);
    q = random(100000, 200000);
    cout << n << ' ' << q << '\n';

    for(int i = 1; i <= n; i ++) {
        pre[i] = random(1, inf);
        cout << pre[i] << ' ';
    }
    cout << '\n';

    for(int i = 1; i <= q; i ++) {
        vec[i][0] = random(1, 2);
        cout << vec[i][0] << ' ';
        if(vec[i][0] == 1) {
            vec[i][1] = random(1, n);
            cout << vec[i][1] << '\n';
        } else {
            vec[i][1] = random(1, n);
            vec[i][2] = random(vec[i][1], n);
            cout << vec[i][1] << ' ' << vec[i][2] << '\n';
        }
    }
}

void solve() {
    for(int i = 1; i <= n; i ++) {
        pre[i] += pre[i - 1];
    }

    int p = 0;
    for(int i = 1; i <= q; i ++) {
        auto [op, l, r] = vec[i];
        if(op == 1) {
            p += l;
            p %= n;
        } else {
            l += p, r += p;
            l = (l - 1) % n + 1;
            r = (r - 1) % n + 1;
            if(l <= r) {
                cout << pre[r] - pre[l - 1] << '\n';
            } else {
                cout << pre[n] - pre[l - 1] + pre[r] << '\n';
            }
        }
    }
}

int main() {
    for(int i = 3;i <= 5; i ++) {
        string filename1 = "";
        filename1 += to_string(i); 
        filename1 += ".in"; 
        freopen(filename1.c_str() , "w" , stdout);
        get();
        fclose(stdout);

        string filename2 = "";
        filename2 += to_string(i); 
        filename2 += ".out"; 
        freopen(filename2.c_str() , "w" , stdout);
        solve();
        fclose(stdout);
    }
}

