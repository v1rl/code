#include<bits/stdc++.h> 
using namespace std;   
using i64 = long long;
constexpr int mod = 1e9 + 7;

i64 qmi(i64 a, i64 b)
{
    i64 res = 1;
    while(b)
    {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main()  
{  
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        int n, m;
        cin >> n >> m;
        cout << qmi(qmi(2, m) - 2, n) << '\n';        
    }
}  
