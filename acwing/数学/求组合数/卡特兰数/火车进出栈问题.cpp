#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;
const int M = 10000, P = 4;

struct bignum
{
    int n[10000],l;
    bignum(string s = "")
    {
        memset(n,0,sizeof(n));
        l=1;

        int now=0,cc=1,ct=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            n[now]+=(s[i]-'0')*cc;
            cc*=10;
            ct++;
            if(ct==P && i!=0)
            {
                now++;
                cc=1;
                ct=0;
            }
        }
        l=now+1;
    }
    void print()
    {
        printf("%d",n[l-1]);
        for(int i=l-2;i>=0;i--)
            printf("%0*d",P,n[i]);
        printf("\n");
    }
    void add(int x)
    {
        if(x || l)
            n[l++]=x;
    }
    void re()
    {
        reverse(n,n+1);
    }
    bool operator < (const bignum &x) const
    {
        bignum t=*this;
        if(t.l!=x.l)
            return t.l<x.l;
        for(int i=t.l-1;i>=0;i--)
            if(t.n[i]!=x.n[i])
                return t.n[i]<x.n[i];
        return 0;
    }
    bignum operator + (const bignum &x) const
    {
        bignum t=*this;
        if(x.l>t.l)
            t.l=x.l;
        for(int i=0;i<t.l;i++)
        {
            t.n[i]+=x.n[i];
            if(t.n[i]>=M)
            {
                t.n[i+1]+=t.n[i]/M;
                t.n[i]%=M;
            }
        }
        while(t.n[t.l])
        {
            t.n[t.l+1]+=t.n[t.l]/M;
            t.n[t.l++]%=M;
        }
        return t;
    }
    bignum operator - (bignum x) const
    {
        bignum t=*this;
        if(t<x)
        {
            printf("-");
            swap(t,x);
        }
        for(int i=0;i<t.l;i++)
        {
            t.n[i]-=x.n[i];
            if(t.n[i]<0)
            {
                t.n[i]+=M;
                t.n[i+1]--;
            }
        }
        while(!t.n[t.l-1] && t.l>1)
            t.l--;
        return t;
    }
    bignum operator * (const bignum &x) const
    {
        bignum t=*this,tmp;
        tmp.l=t.l+x.l-1;
        for(int i=0;i<t.l;i++)
            for(int j=0;j<x.l;j++)
            {
                tmp.n[i+j]+=t.n[i]*x.n[j];
                if(tmp.n[i+j]>=M)
                {
                    tmp.n[i+j+1]+=tmp.n[i+j]/M;
                    tmp.n[i+j]%=M;
                }
            }
        while(tmp.n[tmp.l])
        {
            tmp.n[tmp.l+1]+=tmp.n[tmp.l]/M;
            tmp.n[tmp.l++]%=M;
        }
        return tmp;
    }
    bignum operator / (const int &x) const
    {
        bignum t=*this,r;
        int tmp=0;
        r.l=t.l;
        for(int i=t.l-1;i>=0;i--)
        {
            tmp+=t.n[i];
            if(tmp>=x)
            {
                r.n[i]+=tmp/x;
                tmp%=x;
            }
            tmp*=M;
        }
        while(!r.n[r.l-1] && r.l>1)
            r.l--;
        return r;
    }
};

vector<int> minp, primes;
void sieve(int n)
{
    minp.assign(n + 1, 0);
    for(int i = 2; i <= n; i ++)
    {
        if(!minp[i])
        {
            minp[i] = i;
            primes.emplace_back(i);
        }
        for(auto p : primes)
        {
            if(i * p > n) break;
            minp[i * p] = p;
            if(minp[i] == p) break;
        }
    }
}


int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    sieve(2 * n);

    vector<int> cnt(2 * n + 1);
    for(auto p : primes)
    {
        for(i64 i = p; i <= 2 * n; i *= p)
        {
            cnt[p] += 2 * n / i;
        }

        for(i64 i = p; i <= n; i *= p)
        {
            cnt[p] -= 2 * (n / i);
        }
    }

    int t = n + 1;
    for(int i = 2; i <= t / i; i ++)
    {
        if(t % i == 0)
        {
            while(t % i == 0)
            {
                t /= i;
                cnt[i] --;
            }
        } 
    }
    if(t > 1) cnt[t] --;

    bignum ans("1");
    for(int i = 2; i <= 2 * n; i ++)
    {
        while(cnt[i])
        {
            string s = to_string(i);
            bignum t(s);
            ans = ans * t;
            cnt[i] --;
        }
    }

    ans.print();
}