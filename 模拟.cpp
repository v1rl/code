#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-3;
struct charactor
{
    int dun;
    double attack[3];
    int level[3];
    double sum;
    long long ans;
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    double a, b;
    cin >> a >> b;
    
    vector<charactor> cha(2);
    cha[0] = {50, {a * 0.7, a, a * 2}, {0, 0, 0}, 0, 0};
    cha[1] = {100, {b * 0.5, b, b * 3}, {0, 0, 0}, 0, 0};

    int t;
    cin >> t;
    while(t --)
    {
        int n, x;
        cin >> n >> x;
        for(auto &[dun, attack, level, sum, ans] : cha)
        {
            level[0] = (n - 1) / dun;
            if(n > 0) level[2] = 1;
            else level[2] = 0;
            level[1] = 2;

            long long res = 0;
            sum = attack[0] * level[0] + attack[1] * level[1] + attack[2] * level[2];
            res = (int)(x / sum) * (level[0] + level[1] + level[2]);
            double last = x - (int)(x / sum) * sum;
//            cout << sum << ' ' << res << ' ' << last << '\n';

            int k = 0;
            while(last > eps)
            {
                k ++;
                if(k <= level[0]) last -= attack[0];
                else if(k == level[0] + 1 && level[2]) last -= attack[2];
                else last -= attack[1];
            }
            res += k;

            ans += res;
        }
    }

    cout << cha[0].ans << '\n' << cha[1].ans << '\n';
    if(cha[0].ans > cha[1].ans) cout << "LHZ YES!";
    else if(cha[0].ans < cha[1].ans) cout << "LZ YES!";
    else cout << "xue zhang men tql!";
}
