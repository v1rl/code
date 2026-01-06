#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0, j = s.size() - 1; i <= j; i ++, j --)
    {
        int a = abs(s[i] - s[j]);
        ans += min(a, 26 - a);
    }
    cout << ans << '\n';
}