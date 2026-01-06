#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while(n --)
    {
        int x;
        cin >> x;
        vector<int> ans;
        for(int i = 1; i <= x / i; i ++)
        {
            if(x % i == 0)
            {
                ans.emplace_back(i);
                if(x / i != i) ans.emplace_back(x / i);
            }
        }
        sort(ans.begin(), ans.end());
        for(auto c : ans) cout << c << ' ';
        cout << '\n';
    }
}