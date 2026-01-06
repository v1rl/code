#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
const int N = 26 * 26 + 10;
int w[N][N];

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    i64 ans = 0;
    while(n --)
    {
        string a, b;
        cin >> a >> b;
        int w1 = 26 * (a[0] - 'A') + a[1] - 'A';
        int w2 = 26 * (b[0] - 'A') + b[1] - 'A';
        if(w1 == w2) continue;                  //“并且来自不同的州”
        ans += w[w2][w1];
        w[w1][w2] ++;
    }
    cout << ans << '\n';
    return 0;
}