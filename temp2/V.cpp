#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
    int n,m ; cin >> n >> m;
    // n++;
    // m++;
    vector<vector<int> > a(n + 1,vector<int> (m + 1));
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            int up = i ,down = n - i,le = j, ri = m - j;
            a[i][j] += min(up,le);//左上角
            a[i][j] += min(up,ri);//右上角
            a[i][j] += min(down,le);//左下角
            a[i][j] += min(down,ri);//右下角
            int res = 0;
            int k = min(down,ri);
            int t1 = 0;
            if(k > 0)
            {
                int q1 = 0;
                if(ri > down)
                {
                    q1 = ri - down;//可以直接乘down多少次
                    if(q1 >= up)
                    {
                        t1 += up * down;
                    } 
                    else
                    {
                        int q2 = up - q1;//q2表示等差数列项数
                        t1 += q1 * down;
                        t1 += q2 * (down + down - q2) / 2;
                    }
                }
                else
                {
                    int te = max(ri - up,0);
                    t1 += up *(k - 1 + te) / 2;
                }
                res += t1;
                a[i][j] += t1; //右边的斜正方形
            }
            // cout << t1 << " ";

            k = min(down,le);
            int t2 = 0;
            if(k > 0)
            {
                int q1 = 0;
                if(le > down)
                {
                    q1 = le - down;//可以直接乘down多少次
                    if(q1 >= up)
                    {
                        t2 += up * down;
                    } 
                    else
                    {
                        int q2 = up - q1;//q2表示等差数列项数
                        t2 += q1 * down;
                        t2 += q2 * (down + down - q2) / 2;
                    }
                }
                else
                {
                    int te = max(le - up,0);
                    t2 += up *(k - 1 + te) / 2;
                }
                res += t2;
                a[i][j] += t2; //左边的斜正方形
            }

            // cout << res << " ";
            k = min(ri,down);
            int t3 = 0;
             if(k > 0)
            {
                int q1 = 0;
                if(down > ri)
                {
                    q1 = down - ri;//可以直接乘ri多少次
                    if(q1 >= le)
                    {
                        t3 += le * ri;
                    } 
                    else
                    {
                        int q2 = le - q1;//q2表示等差数列项数
                        t3 += q1 * ri;
                        t3 += q2 * (ri + ri - q2) / 2;
                    }
                }
                else
                {
                    int te = max(down - le,0);
                    t3 += le *(k - 1 + te) / 2;
                }
                res += t3;
                a[i][j] += t3; //下方的斜正方形
            }
            // cout << t3 << ' ';

            k = min(ri,up);
            int t4 = 0;
            if(k > 0)
            {
                int q1 = 0;
                if(up > ri)
                {
                    q1 = up - ri;//可以直接乘ri多少次
                    if(q1 >= ri)
                    {
                        t4 += ri * le;
                    } 
                    else
                    {
                        int q2 = ri - q1;//q2表示等差数列项数
                        t4 += q1 * ri;
                        t4 += q2 * (ri + ri - q2) / 2;
                    }
                }
                else
                {
                    int te = max(up - ri,0);
                    t4 += ri *(k - 1 + te) / 2;
                }
                res += t4;
                a[i][j] += t4; //下方的斜正方形
            }
                cout<<t4<<" ";

            a[i][j] += k;//加上下方的斜正方形

        }
        cout << '\n';
    }

    // for(int i = 0; i <= n; i++)
    // {
    //     for(int j = 0; j <= m; j++)
    //     {
    //         cout << a[i][j]<<" ";
    //     }
    //     cout << '\n';
    // }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}