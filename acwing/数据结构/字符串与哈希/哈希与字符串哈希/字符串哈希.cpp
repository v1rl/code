#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
const int P = 131;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<u64> res(n);
    for(int i = 0; i < n; i ++)
    {
        string s;
        cin >> s;
        u64 ans = 0;
        for(auto c : s)
        {
            ans = ans * P + c;
        }
        res[i] = ans;
    }
    sort(res.begin(), res.end());
    int num = n;
    for(int i = 1; i < n; i ++)
    {
        if(res[i] == res[i - 1]) num --;
    }

    cout << num << '\n';
}

