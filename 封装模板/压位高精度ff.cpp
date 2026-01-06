#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int M = 100000000, P = 8;
struct bignum
{
    i64 n[5000], l;
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

int main()
{
    string a, b;
    cin >> a >> b;
    bignum p(a), q(b);
    bignum t = p * q;
    t.print();
}