#include<bits/stdc++.h> 
using namespace std;   
using i64 = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    sort(a.begin(), a.end());

    i64 num = 0;
    for(auto k : a)
    {
        if(k <= num + 1) num += k;
        else break;
        if(num >= n)
        {
            cout << "Cool!" << '\n';
            return;
        }
    }
    cout << num + 1 << '\n';
}
  
int main()  
{  
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        solve();
    }
}  
