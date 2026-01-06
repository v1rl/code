#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e7 + 10;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    int num = 0;
    vector<array<char, 3>> ans;
    for(char i = 'a'; i <= 'z'; i ++)
    {
        for(char j = 'a'; j <= 'z'; j ++)
        {
            if(i == j) continue;
            unordered_set<int> S;
            int cnt = 0;
            for(int k = 1; k < n - 1; k ++)
            {
                if(s[k - 1] == i && s[k] == j && s[k + 1] == j)
                {
                    cnt ++;
                    S.insert(k);
                    S.insert(k - 2);
                    S.insert(k - 1);
                    S.insert(k + 1);
                    S.insert(k + 2);
                }
            }
            if(cnt >= m)
            {
                num ++;
                ans.push_back({i, j, j});
            }
            else if(cnt == m - 1)
            {
                int stt = 1;
                for(int k = 1; k < n - 1; k ++)
                {
                    if(S.count(k)) continue;
                    int t = 0;
                    if(s[k - 1] == i) t ++;
                    if(s[k] == j) t ++;
                    if(s[k + 1] == j) t ++;
                    if(t == 2)
                    {
                        num ++;
                        ans.push_back({i, j, j});
                        break;
                    }
                }
            }
        }
    }

    cout << num << '\n';
    for(auto &[a, b, c] : ans)
        cout << a << b << c << '\n';

    return 0;
}