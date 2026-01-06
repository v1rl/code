#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;

struct Node
{
    int val, x, l, r;
    bool operator <(const Node &W) const
    {
        return val < W.val;
    }
};

void solve()
{
    int n, mod, k;
    cin >> n >> mod >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) 
    {
        cin >> a[i];
        a[i] %= mod;
    }
    sort(a.begin() + 1, a.end());
    priority_queue<Node, vector<Node>> heap;
    for(int i = 1, j = n; i <= n; i ++)
    {
        while(j >= 1 && a[i] + a[j] >= mod) j --;
        if(j > i)
        {
            heap.push({a[i] + a[j], a[i], i + 1, j});
        }
        if(i != n && j != n)
        {
            heap.push({(a[i] + a[n]) % mod, a[i], max(i, j) + 1, n});
        }
    }
    vector<int> ans;
    ans.reserve(k);
    while(ans.size() < k && !heap.empty())
    {
        auto [val, x, l, r] = heap.top();
        heap.pop();
        ans.emplace_back(val);
        if(r - 1 >= l)
        {
            heap.push({(x + a[r - 1]) % mod, x, l, r - 1});
        }
    }
    while(ans.size() < k) ans.emplace_back(-1);
    for(auto x : ans) 
        cout << x << ' ';
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    // t = 1;
    while(t --)
    {
        solve();
    }
    return 0;
}