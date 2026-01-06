#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr double pi = acos(-1), eps = 1e-6;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<double> vec;
    for(int i = 0; i < n; i ++)
    {
        i64 x, y, r;
        cin >> x >> y >> r;
        double dist = sqrt(x * x + y * y);
        if(r - dist > eps) vec.emplace_back((r - dist) * r * r);
    }
    sort(vec.begin(), vec.end());
    int num = vec.size() - k;
    int cnt = 0;
    double ans = 0;
    while(num > 0)
    {
        ans += pi * vec[cnt ++];
        num --;
    }
    printf("%.6lf", ans);
}