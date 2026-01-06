#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int N = 1e6 + 10;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<int> st(N);
    int max_a = 0;
    for(int i = 0; i < n; i ++) 
    {
        int x;
        cin >> x;
        st[x] = true;
        max_a = max(max_a, x);
    }

    int ans = 0;
    for(int i = 1; i <= max_a; i ++)
    {
        if(st[i]) ans ++;
        else
        {
            for(int j = 2 * i; j <= max_a; j += i)
                st[j] = false;
        }
    }
    cout << ans << '\n';
}