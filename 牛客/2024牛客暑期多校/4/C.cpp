#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        int n;
        int res = 0;
        int sum_2 = 0;
        cin >> n;
        vector<int> dat(n + 1);
        vector<bool> st(n + 1);
        for(int i = 1; i <= n; i ++)
        {
            cin >> dat[i];
            if(dat[i] == i) st[i] = true;
        }
        for(int i = 0; i < n; i ++)
        {
            int stt = dat[i];
            if(!st[dat[i]])
            {
                int cnt = 0;
                int cur = stt;
                do
                {
                    st[cur] = true;
                    cur = dat[cur];
                    cnt ++;
                }while(cur != stt);

                if(cnt == 2) sum_2 ++;
                else if(cnt > 2 && cnt <= 4) res ++;
                else if(cnt > 4)
                {
                    cnt -= 2;
                    if(cnt % 3 == 0)
                    {
                        sum_2 ++;
                        res += cnt / 3;
                    }
                    else res += cnt / 3 + 1;
                }
            }
        }
        res += (sum_2 + 1) / 2;
        cout << res << '\n';
    }
}
