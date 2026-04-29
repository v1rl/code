#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;
#define int long long

const int mod = 998244353;

void solve() {
    int n;
    cin>>n;
    vector<int> a(2*n+2);
    for(int i=1;i<=2*n;i++) cin>>a[i];
    sort(a.begin()+1,a.begin()+2*n+1);
    int ans=a[2*n];
    for(int i=1;i<=n-1;i++){
        ans-=a[i];
    }
    for(int i=n;i<=2*n-1;i++) ans+=a[i];
    cout<<a[2*n]<<' ';
    vector<int> b(n+1),c(n+1);
    b[1]=ans;
    for(int i=2;i<=n;i++) b[i]=a[i-1];
    for(int i=1;i<=n;i++) c[i]=a[n+i-1];
    for(int i=1;i<=n;i++){
        cout<<b[i]<<' '<<c[i]<<' ';
    }
    cout<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;

    while(t --) {
        solve();
    }

    return 0;
}

