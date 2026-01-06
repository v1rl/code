#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;

int main()
{
    int t ;
    cin >> t;
    while(t --)
    {
        long long l, a, b;
        cin >> l >> a >> b;
        double len1 = sqrtl(a * a + b * b);
        double len2 = sqrtl((a - l) * (a - l) + b * b);
        if(len1 - l <= eps) cout << "Yes" << '\n' << 0 << '\n';
        else if(len2 - l <= eps) cout << "Yes" << '\n' << l << '\n';
        else cout << "No" << '\n';
    }
}