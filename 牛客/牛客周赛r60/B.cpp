#include<bits/stdc++.h> 
using namespace std;   
using i64 = long long;
  
int main()  
{  
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    cout << n + m - max(abs(n - m) - 1, 0) << '\n';
}  
