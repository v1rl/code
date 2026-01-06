#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; i ++)
    {
        int x;
        cin >> x;
        sum ^= x;
    }
    if(sum) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}