#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;
/*
-B + A只能给B提供两种值
-C + B只能给C提供三种值 X

4 -2
3   1 -5 -3 9 7 -11 -9 15 13

c
    -c + b

c + a - 2 * b
    -c - a + 3 * b
c + 2 * a - 4 * b
-c - 2 * a + 5 * b
c + 3 * b + 6 * b


    -c - b + a
c + 2 * b - a
-c - 3 * b + 2 * a
c + 4 * b - 2 * a
-c - 5 * b + 3 * a
*/

void solve() {
    int a, b, c, x;
    cin >> a >> b >> c >> x;
    int mod1 = a - 2 * b;
    int mod2 = -a + 2 * b;
    int t1 = -c + b;
    int t2 = c;

    int it1 = x - t1;
    int it2 = x - t2;
    if(mod1 == 0 && mod2 != 0) {
        if(it1 == mod1 || it1 % mod2 == 0 || it2 == mod1 || it2 % mod2) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    } else if(mod2 == 0 && mod1 != 0) {
        if(it1 == mod2 || it1 % mod1 == 0 || it2 == mod2 || it2 % mod1 == 0) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }        
    } else if(mod1 == 0 && mod2 == 0) {
        if(it1 == mod1 || it1 == mod2 || it2 == mod1 || it2 == mod2) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    } else {
        if(it1 % mod1 == 0 || it1 % mod2 == 0 || it2 % mod2 == 0 || it2 % mod1 == 0) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }        
    }
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