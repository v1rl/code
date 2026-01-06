#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i ++) cin >> nums[i];

    // 按照次数维护
    int npos = 0, step = 0;
    while(npos < n - 1)
    {
        step ++;
        if(npos + nums[npos] >= n - 1) break;
        int ma = 0;
        for(int i = npos + 1, j = 1; j <= nums[npos]; i ++, j ++)
            if(j + nums[i] > ma) 
            {
                ma = j + nums[i];
                npos = i;
            }
    }
    cout << step << '\n';

/*
    // 按照遍历维护
    int maxpos = 0, end = 0, step = 0;
    for(int i = 0; i < n - 1; i ++)
    {
        maxpos = max(maxpos, i + nums[i]);
        if(i == end)
        {
            step ++;
            end = maxpos;
        }
    }
    cout << step << '\n';
*/
}