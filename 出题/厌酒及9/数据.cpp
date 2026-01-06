#include<bits/stdc++.h> 
#include<string.h> 
using namespace std; 
using i64 = long long;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<array<i64, 2>> res;

const int mod = 1e9 + 7, N = 20;
int f[N][10][10];
int nums[N];

i64 random(i64 l,i64 r)
{ 
    return (rng() - l) % (r - l + 1) + l;
}

void solve1() 
{
    res.clear();
    n = random(1, 1000);
    cout << n << '\n';
    for(int i = 1; i <= n; i ++)
    {
        i64 l, r;
        l = random(1, 1e8);
        r = random(l, 1e8);
        res.push_back({l, r});
        if(l > r)
        {
            cout << "error" << '\n';
            exit(0);
        }
        cout << l << ' ' << r << '\n';
    }
}

int dp(int pos, int val, int sum, int op)
{
    if(!pos)
    {
        if(val && sum) return 1;
        return 0;
    }
    if(!op && f[pos][val][sum] != -1) return f[pos][val][sum];
    int res = 0, mx = op ? nums[pos] : 9;
    for(int i = 0; i <= mx; i ++)
    {
        if(i == 9) continue;
        res = (res + dp(pos - 1, (val * 10 + i) % 9, (sum + i) % 9, op && i == nums[pos])) % mod;
    }
    return op ? res : f[pos][val][sum] = res;
}

int calc(i64 n)
{
    int tt = 0;
    while(n) nums[++ tt] = n % 10, n /= 10;
    return dp(tt, 0, 0, 1);
}

void solve2()
{
    memset(f, -1, sizeof f);
    for(int i = 0; i < n; i ++)
    {
        auto [l, r] = res[i];
        cout << ((calc(r) - calc(l - 1)) % mod + mod) % mod << '\n';
    }
}

int main() 
{
    // srand(int(time(0)));
    for(int i = 4;i <= 5; i ++)
    {
        string filename1 = "";
        filename1 += to_string(i); 
        filename1 += ".in"; 
        freopen(filename1.c_str() , "w" , stdout);
        solve1();
        fclose(stdout);

        string filename2 = "";
        filename2 += to_string(i); 
        filename2 += ".out"; 
        freopen(filename2.c_str() , "w" , stdout);
        solve2();
        fclose(stdout);
    }
}

