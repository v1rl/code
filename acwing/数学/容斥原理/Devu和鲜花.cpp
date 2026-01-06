#include<bits/stdc++.h> 
using namespace std;   
using i64 = long long;
constexpr int N = 20, mod = 1e9 + 7;
vector<int> infact(N + 1);

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

i64 C(i64 n, i64 m)
{
    i64 q = 1;
    for(int i = n; i >= n - m + 1; i --)
        q = q * i % mod;
    return q * infact[m] % mod;
}
  
int main()  
{  
    i64 n, m;
    cin >> n >> m;

    infact[0] = 1;
    for(int i = 1; i <= N; i ++)
        infact[i] = infact[i - 1] * qmi(i, mod - 2);

    vector<i64> nums(n);
    for(int i = 0; i < n; i ++) cin >> nums[i];

    i64 sum = C(n + m - 1, n - 1);
    for(int i = 1; i < 1 << n; i ++)
    {
        int cnt = 0;
        i64 p = n + m - 1;
        for(int j = 0; j < n; j ++)
        {
            if(i >> j & 1)
            {
                p -= nums[j] + 1;
                cnt ++;
            }
        }
        if(p >= 0)
        {
            if(cnt & 1) sum = (sum - C(p, n - 1)) % mod;
            else sum = (sum + C(p, n - 1)) % mod;
        }
    }

    cout << (sum + mod) % mod << '\n';
}  