#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;
#define int long long

const int M = 1e5+10;
int a[M];

void solve() {
    int n;
    cin>>n;
    int p=0,ans=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        if(a[i]==0) ans += p, p=0;
        else{
            if(a[i]>=a[i-1]) p=a[i];
            else{
                ans+=p;
                ans-=a[i];
                p=a[i];
            }
        }
    }
    cout<<ans+p<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;

    while(t --) {
        solve();
    }

    return 0;
}

