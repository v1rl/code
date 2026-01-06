#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int N = 1e5 + 10, mod = 1e9 + 7;
int fact[N], infact[N];

int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};

i64 qmi(i64 a, i64 b)
{
    i64 res = 1;
    while(b)
    {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

i64 C(int a, int b)
{
    return 1ll * fact[a] * infact[a - b] % mod * infact[b] % mod;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    fact[0] = infact[0] = 1;
    for(int i = 1; i <= 100000; i ++)
    {
        fact[i] = 1ll * fact[i - 1] * i % mod;
        infact[i] = 1ll * infact[i - 1] * qmi(i, mod - 2) % mod;
    }

    unordered_map<char, int> mp;
    mp['U'] = 0, mp['L'] = 1, mp['D'] = 2, mp['R'] = 3;
    while(t --)
    {
        unordered_map<char, int> has_nums;
        unordered_map<char, int> need_nums;
        int len, x, y;
        cin >> len >> x >> y;
        string s;
        cin >> s;
        int nx = 0, ny = 0;
        int dist = abs(x) + abs(y);
        string ans;
        for(auto c : s)
        {
            int id = mp[c];

            int cx = nx + dx[id], cy = ny + dy[id];
            int ndist = abs(cx - x) + abs(cy - y);
            if(ndist < dist)
            {
                need_nums[c] ++;
                dist = ndist;
                ans += string(1, c);
                nx += dx[id], ny += dy[id];
            }
            if(ndist == 0) break;
        }

        if(nx == x && ny == y)
        {
            cout << "YES" << ' ' << ans << ' ';
            for(auto c : s)
            {
                has_nums[c] ++;
            }
            i64 res = 1;
            i64 p = 0, pp = 0;
            for(int i = 0; i <= min(has_nums['L'] - need_nums['L'], has_nums['R'] - need_nums['R']); i ++)
            {
                p = (p + C(has_nums['L'], need_nums['L'] + i) * C(has_nums['R'], need_nums['R'] + i)) % mod;
            }
            res = res * p % mod;
            for(int i = 0; i <= min(has_nums['U'] - need_nums['U'], has_nums['D'] - need_nums['D']); i ++)
            {
                pp = (pp + C(has_nums['U'], need_nums['U'] + i) * C(has_nums['D'], need_nums['D'] + i)) % mod;
            }
            res = res * pp % mod;   
            cout << res << '\n';
        }
        else cout << "NO" << '\n';
    }
}