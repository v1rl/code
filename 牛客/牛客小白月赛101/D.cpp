#include <bits/stdc++.h>
using namespace std;

/* 遍历右端点，定右移左
int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<int> c(n + 2);
    for(int i = 1; i <= n; i ++) cin >> a[i];

    map<int, int> mp;
    mp[0] = 0;
    int sum = 0;
    for(int i = 1; i <= n; i ++)
    {
        sum += a[i];
        for(int j = 1; j * j <= sum; j ++)
        {
            if(mp.count(sum - j * j))
            {
                c[mp[sum - j * j] + 1] ++;
                c[i + 1] --;
            }
            mp[sum] = i;
        }
    }

    for(int i = 1; i <= n; i ++) 
        c[i] += c[i - 1];

    while(m --)
    {
        int x;
        cin >> x;
        cout << c[x] << '\n';
    }
    return 0;
}
*/

bool check(int x)
{
    int t = sqrt(x);
    if(x == t * t) return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) cin >> a[i];

    vector<array<int, 2>> state;
    state.reserve(1e6);

    for(int l = 1; l <= n; l ++)
    {
        int sum = 0;
        for(int r = l; r <= n; r ++)
        {
            sum += a[r];
            if(check(sum))
                state.push_back({l, r});
        }
    }

    vector<int> nums(n + 1);
    for(auto [l, r] : state)
        for(int i = l; i <= r; i ++)
            nums[i] ++;

    while(m --)
    {
        int x;
        cin >> x;
        cout << nums[x] << '\n';
    }
}