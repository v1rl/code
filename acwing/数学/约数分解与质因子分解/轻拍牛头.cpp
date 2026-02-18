#include<bits/stdc++.h> 
using namespace std;   
using i64 = long long;
constexpr int N = 1e6;
  
int main() {  
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(N + 1);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        cnt[a[i]] ++;
    }

    vector<int> ans(N + 1);

    for(int i = 1; i <= N; i ++)
        if(cnt[i])
            for(int j = i; j <= N; j += i)
                ans[j] += cnt[i];

    for(int i = 0; i < n; i ++)
        cout << ans[a[i]] - 1 << '\n';

    return 0;
}  