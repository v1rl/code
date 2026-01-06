#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;
typedef pair<int, int> PII;
const int mod = 1e9 + 7;

int A(int a, int b)
{
    i64 res = 1;
    for(int i = a; i >= a - b + 1; i --) res *= i;
    return res;
}

int C(int a, int b)
{
    int res = A(a, b);
    for(int i = 1; i <= b; i ++) res /= i;
    return res;
}


int solve()
{
    int n;
    cin >> n;
    vector<string> s(3);
    for(int i = 0; i < 3; i ++) cin >> s[i];

    vector<int> match(10, -1);
    vector<int> f(n + 1);
    for(int j = 0; j < n; j ++)
    {
        int c = j % 3;
        set<int> S;
        for(int i = 0; i < 3; i ++)
        {
            if(s[i][j] == '?')
            {
                f[j] ++;
                continue;
            }
            int ch = s[i][j] - '0';
            if(match[ch] != -1 && match[ch] != c) return 0;
            else
            {
                if(S.count(ch)) return 0;
                else
                {
                    match[ch] = c;
                    S.insert(ch);
                }
            }
        }
    }

    vector<int> num(3);
    int cnt = 0;
    int sum = 0;
    for(int i = 1; i <= 9; i ++)
    {
        if(match[i] == -1) cnt ++;
        else num[match[i]] ++;
    }
    for(auto c : num)
    {
        if(c > 3) return 0;
    }

    i64 ans = 1;
    for(auto x : num)
    {
        ans *= C(cnt, 3 - x);
        cnt -= (3 - x);
    }

    for(int i = 0; i < n; i ++)
    {
        ans = ans * A(f[i], f[i]) % mod;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        cout << solve() << '\n';
    }
}