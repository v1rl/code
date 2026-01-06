#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    // nth_element(a.begin(), a.begin() + m, a.end());
    // cout << a[m] << '\n';
    // return 0;


    auto dfs = [&](auto&& self, int l, int r)->void
    {
        int i = l, j = r;
        int mid = a[l];
        while(i < j)
        {
            while(i < j && a[j] >= mid) j --;
            swap(a[i], a[j]);
            while(i < j && a[i] <= mid) i ++;
            swap(a[i], a[j]);
        }
        if(m > i) self(self, i + 1, r);
        else if(m < i) self(self, l, i - 1);
    };
    dfs(dfs, 0, n - 1);

    cout << a[m] << '\n';
}
  