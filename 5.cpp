#include<bits/stdc++.h>
#define re return
#define ll long long 
#define lowbit(x) (x&(-x))
#define inc(i,l,r) for(int i=l;i<=r;++i)
using namespace std;
template<typename T>inline void rd(T&x)
{
    char c;bool f=0;
    while((c=getchar())<'0'||c>'9')if(c=='-')f=1;
    x=c^48;
    while((c=getchar())>='0'&&c<='9')x=x*10+(c^48);
    if(f)x=-x;
}

const int maxn=5000;
ll n,m;
ll c[maxn][maxn];

inline void add(ll x,ll y,ll z)
{
    for(ll i=x;i<=n;i+=lowbit(i))
    for(ll j=y;j<=m;j+=lowbit(j))
        c[i][j]+=z;
}

inline ll sum(ll x,ll y)
{
    ll res=0;
    for(ll i=x;i;i-=lowbit(i))
    for(ll j=y;j;j-=lowbit(j))
    res+=c[i][j];

    re res;
}


int main()
{
    freopen("in.txt","r",stdin);
    
    ll a,b,x,y,z,opt;
    
    rd(n);rd(m);
    while(~(scanf("%lld",&opt)))
    {
        if(opt==1)
        {
            rd(x),rd(y),rd(z);
            add(x,y,z);
        }
        else 
        {
            rd(a);rd(b),rd(x),rd(y);
            printf("%lld\n",sum(x,y)+sum(a-1,b-1)-sum(x,b-1)-sum(a-1,y));
        }    
    }
    re 0;
}