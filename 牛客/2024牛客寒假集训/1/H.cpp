#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;
typedef pair<int, int> PII;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> range(n + 1);
    vector<int> r(n + 1), l(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        cin >> l[i] >> r[i];
        range[l[i]].emplace_back(i);
    }

    priority_queue<PII, vector<PII>, greater<PII>> heap;
    vector<int> ans(n + 1);
    for(int x = 1; x <= n; x ++)
    {
        for(auto i : range[x])
        {
            heap.push({r[i], i});
        }
        if(heap.empty())
        {
            cout << -1 << '\n';
            return 0;
        }
        auto [r, i] = heap.top();
        if(r < x)
        {
            cout << -1 << '\n';
            return 0;
        }
        heap.pop();
        ans[i] = x;
    }
    for(int i = 1; i <= n; i ++) cout << ans[i] << ' ';
    return 0;
}