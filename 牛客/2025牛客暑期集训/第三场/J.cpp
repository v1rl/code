#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 5e6 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> num(N);

    auto divide = [&](int x) {
        for(int i = 2; i * i <= x; i ++) {
            if(x % i == 0) {
                while(x % i == 0) {
                    num[i] --;
                    x /= i;
                }
                if(num[i] < 0) num[i] = -num[i];
            }
        }
        if(x) {
            num[x] --;
            if(num[x] < 0) num[x] = -num[x];
        }
    };

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        divide(a[i]);
    }

    i64 sum = 1;
    for(int i = 1; i <= 5000000; i ++) {
        while(num[i]) {
            sum *= i;
            num[i] --;
            if(sum > 5000000) {
                cout << "NO" << '\n';
                return;
            }
        }
    }

    for(int i = 1; i <= n; i ++) {
        if(a[i] % sum == 0) {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --)
    {
        solve();
    }
}