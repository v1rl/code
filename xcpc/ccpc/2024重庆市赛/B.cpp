#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const double eps = 1e-6;

void solve()
{
    double p;
    cin >> p;
	double a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    double ans = 300 * a + 300 * b + 200 * c + 100 * d + 50 * e;
    ans /= 300 * (a + b + c + d + e + f);
    ans *= 100;

    double pp = 320 * a + 300 * b + 200 * c + 100 * d + 50 * e;
    pp /= 320 * (a + b + c + d + e + f);
    pp -= 0.8;
    pp *= 5 * p;
    pp = max(0.0, pp);


    printf("%.2lf%% %.0lf\n", ans + eps, pp + eps);
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
    return 0;
}