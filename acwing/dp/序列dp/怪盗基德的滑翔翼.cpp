#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        vector<int> f1(n + 1, 1);
        vector<int> f2(n + 1, 1);
        for(int i = 1; i <= n; i ++) cin >> a[i];

        for(int i = 1; i <= n; i ++)
            for(int j = 1; j < i; j ++)
                if(a[j] > a[i]) f1[i] = max(f1[i], f1[j] + 1);

        for(int i = n; i; i --)
            for(int j = n; j > i; j --)
                if(a[j] > a[i]) f2[i] = max(f2[i], f2[j] + 1);

        int res = 0;
        for(int i = 1; i <= n; i ++) res = max(res, max(f1[i], f2[i]));
        cout << res << '\n';
    }
    return 0;
}