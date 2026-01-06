#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;
typedef pair<int, int> PII;
const int inf = 2e9;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    const int MOD = n;
    vector<int> ne(n);
    vector<int> s(n), a(n), b(n);
    i64 ans = 0, pre = 0;
    vector<vector<int>> fails(n);
    for(int i = 0; i < n; i++)
    {
        cin >> s[i] >> a[i] >> b[i];
        s[i] = (s[i] + ans) % MOD;
        // cout << s[i] << '\n';
        pre += b[i];
        if(i > 0)
        {
            int j = ne[i - 1];
            while(j > 0 && s[j] != s[i]) 
            {
                fails[i].push_back(j);
                j = ne[j - 1];
            }
            if(s[j] == s[i])
            {
                for(auto x : fails[j])
                {
                    fails[i].push_back(x);
                }
                j++;
            } 
            else
            {
                fails[i].push_back(j);
            }
            ne[i] = j;
        }
        for(auto x : fails[i])
        {
            pre -= b[i - x];
        }
        ans += pre * a[i];
        cout << ans << "\n";
    }
}