## 1-1 **好好学习，天天向上**

#### 知识点：语法

```cpp
#include<stdio.h>

int main () {
    int a,b;
    printf("good good study, day day up.");
    return 0;
}
```

## 1-2 **你喝奶茶吗？**

#### 知识点：语法

```cpp
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define pii pair <int,int>
using namespace std;

void solve()
{
	int x;
	cin>>x;
	if(x<=10) cout<<"cold\n";
	else if(10<x&&x<40) cout<<"warm\n";
	else cout<<"hot"; 
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	while(t--){
		solve();
	} 
	return 0;
}
```

## 1-3 **死线·冲刺**

#### 知识点：模拟

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

void solve() {
    int sum = 0;
    for(int i = 0; i < 7; i ++) {
        int x;
        cin >> x;
        sum += x;
    }
    cout << (sum <= 374 ? "Bravo!" : "Boooo~") << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while(t --) {
        solve();
    }
    return 0;
}
```

## 1-4 **龙骨炮·审判**

#### 知识点：stl，容斥原理

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    set<int> Sx, Sy;
    for(int i = 0; i < k; i ++) {
        int op, x;
        cin >> op >> x;
        if(op == 0) {
            Sx.insert(x);
        } else {
            Sy.insert(x);
        }
    }
    cout << 1ll * n * m - (1ll * Sx.size() * m + 1ll * Sy.size() * n - Sx.size() * Sy.size()) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while(t --) {
        solve();
    }
    return 0;
}
```

## 1-5 **消息轰炸！！！**

#### 知识点：组合数学

```cpp
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define pii pair <int,int>
using namespace std;
const int mod=1e9+7;
int ksm(int a,int b)
{
	int res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res%mod;
}
void solve()
{
	int n;
	cin>>n;
	cout<<ksm(2,n-1); 
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	} 
	return 0;
}
```

## 1-6 **猎杀·加冕**

#### 知识点：结构体排序

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    vector<tuple<string, int, int, int>> a(n);
    for(int i = 0; i < n; i ++) {
        string name;
        int x, y, z;
        cin >> name >> x >> y >> z;
        a[i] = {name, x, y, z};
    }

    sort(a.begin(), a.end(), 
        [&](auto &x, auto &y) {
            if(get<1>(x) != get<1>(y)) {
                return get<1>(x) > get<1>(y);
            }
            if(get<2>(x) != get<2>(y)) {
                return get<2>(x) > get<2>(y);
            }
            if(get<3>(x) != get<3>(y)) {
                return get<3>(x) > get<3>(y);
            }
            return get<0>(x) < get<0>(y);
        });

    for(auto &[s, _1, _2, _3] : a) {
        cout << s << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while(t --) {
        solve();
    }
    return 0;
}
```

## 1-7 **重构·修正**

#### 知识点：字符串模拟

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for(int i = 0; i < m; i ++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        l1 --, r1 --, l2 --, r2 --;
        reverse(s.begin() + l1, s.begin() + r1 + 1);
        reverse(s.begin() + l2, s.begin() + r2 + 1);
        reverse(s.begin() + r1 + 1, s.begin() + l2);
        reverse(s.begin() + l1, s.begin() + r2 + 1);
    }

    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while(t --) {
        solve();
    }
    return 0;
}
```

## 1-8 **整数拆分**

#### 知识点：搜索

```cpp
#include <bits/stdc++.h>
using namespace std;
int ans[100];
int n;
void dfs(int m,int s,int la)
{
	if(s==n){
		for(int i=0;i<m;i++){
			cout<<ans[i]<<' ';
		}
		cout<<'\n';
		return ;
	}
	for(int i=la;s+i<=n;i++){
		ans[m]=i;
		dfs(m+1,s+i,i);
	}
}
void solve()
{
	cin>>n;
	dfs(0,0,1); 
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	 
	return 0;
}
```

## 2-1 **求更新！！！**

#### 知识点：贪心、stl / 对顶堆

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    multiset<int> S;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    S.insert(a[1]);
    int cur = a[1];
    auto it = S.begin();
    cout << *it << ' ';

    for(int i = 3; i <= n; i += 2) {
        int x = a[i - 1], y = a[i];
        S.insert(x);
        S.insert(y);
        if(x > *it && y > *it) {
            it ++;
        } else if(x <= *it && y <= *it) {
            it --;
        }
        cout << *it << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    while(t --) {
        solve();
    }
    return 0;
}
```

```cpp
#include<bits/stdc++.h>
using namespace std;
int read(){//读入优化
	int x=0;bool f=0;char c=getchar();
	while (c<'0'||c>'9'){if (c=='-')f=1;c=getchar();}
	while (c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f?-x:x;
}
priority_queue<int,vector<int> > q1;//大根堆
priority_queue<int,vector<int>,greater<int> > q2;//小根堆
int main(){
	int n=read();q1.push(read());
	cout<<q1.top()<<' '; 
	for (int i=2;i<=n;i++){
		int input=read();//等同于cin>>input
		if (input>q1.top()) q2.push(input);
			else q1.push(input);
		while (abs((int)q1.size()-(int)q2.size())>1)
			if (q1.size()>q2.size()){q2.push(q1.top());q1.pop();}
				else{q1.push(q2.top());q2.pop();}
		if (i%2) cout<<(q1.size()>q2.size()?q1.top():q2.top())<<' ';
	}
	return 0;
}
```

## 2-2 **下雨了，记得带伞！！！**

#### 知识点：拓扑排序

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<vector<int>> g(n + 1);
    vector<int> indeg(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        int m;
        cin >> m;
        indeg[i] = m;          // 入度等于依赖个数
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            g[x].push_back(i); // 依赖x的人必须先走，所以x->i
        }
    }
    
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (indeg[i] == 0) q.push(i);
    }
    
    vector<int> ans;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ans.push_back(u);
        for (int v : g[u]) {
            if (--indeg[v] == 0) {
                q.push(v);
            }
        }
    }
    
    sort(ans.begin(), ans.end());   // 按编号从小到大输出
    cout << ans.size() << "\n";
    for (size_t i = 0; i < ans.size(); ++i) {
        cout <<ans[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
```

## 2-3 **双子·交织**

#### 知识点：双指针

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

const int inf = 1e9 + 7;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i ++) {
        cin >> b[i];
    }

    int i = 1, j = 0;
    while(1) {
        int cnt = 0;
        while(j < m && abs(b[j] - a[i - 1]) <= k) {
            cnt ++;
            j ++;
        }
        while(i < n && abs(a[i] - b[j - 1]) <= k) {
            i ++;
            cnt ++;
        }
        if(!cnt) {
            break;
        }
    }
    if(i == n && j == m) {
        cout << "WIIIIIN?" << '\n';
    } else {
        cout << "LOOOOSE!" << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}
```

## 2-4 **叠角龙·时机**

#### 知识点：前缀和、单调队列（滑动窗口）

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

const int inf = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    vector<int> pre(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    deque<int> q;
    q.push_back(0);
    int ans = -inf;
    for(int i = 1; i <= n; i ++) {
        if(q.size() && q.front() < i - k) {
            q.pop_front();
        }

        ans = max(ans, pre[i] - pre[q.front()]);
        
        while(q.size() && pre[q.back()] >= pre[i]) {
            q.pop_back();
        }
        q.push_back(i);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while(t --) {
        solve();
    }

    return 0;
}
```

## 3-1 **叠角龙·决策**

#### 知识点：动态规划

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    vector<int> f(n + 1);
    int mx = -inf;
    for(int i = 1; i <= n; i ++) {
        f[i] = max(f[i - 1], min(m, a[i]));
        if(i > k) {
            f[i] = max(f[i], f[i - k - 1] + min(m, a[i]));
        }
        mx = max(mx, f[i]);
    }
    cout << mx << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while(t --) {
        solve();
    }
    return 0;
}
```

## 3-2 **Hollow Knight 好玩，爱玩，多玩^_^**

#### 知识点：最短路、分层图

```cpp
#include <bits/stdc++.h>
#define int long long
#define pii pair <int,int>
using namespace std;

const int N=1e4+5;
vector <pii> e[21*N];
int n,m,k;
int s,t;
bool vis[21*N];
int dis[21*N];
void dij()
{
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	priority_queue<pii,vector<pii>,greater<pii> > q;
	dis[s]=0;
	q.push({dis[s],s});
	while(!q.empty()){
		pii no=q.top();
		q.pop();
		int u=no.second;
		if(vis[u]) continue;
		vis[u]=1;
		int len=e[u].size();
		for(int i=0;i<len;i++){
			int v=e[u][i].first;
			int w=e[u][i].second;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		} 
	}
}
void solve()
{
	cin>>n>>m>>k;
	cin>>s>>t;
	for(int i=0;i<21*N;i++) e[i].clear();
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		for(int j=0;j<=k;j++){
			e[u+j*n].push_back({v+j*n,w});
			e[v+j*n].push_back({u+j*n,w});
			if(j==k) break;
			e[u+j*n].push_back({v+(j+1)*n,0});
			e[v+j*n].push_back({u+(j+1)*n,0}); 
		}
	}	
	for(int j=0;j<k;j++) e[t+j*n].push_back({t+(j+1)*n,0});
	dij();
	if(dis[t+k*n]!=dis[21*N-1]) cout<<dis[t+k*n]<<'\n';
	else cout<<-1<<'\n';
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
```

## 3-3 **许久不见，甚是想念！**

#### 知识点：计算几何

```cpp
#include <bits/stdc++.h>
#define ll long long
//#define double long long 
#define pii pair<int,int> 
using namespace std;
const int N=1e6+5;
const int inf=2e9;
const int mod=1e9+7;
const long long llinf=9e18;
const double esp=1e-10;
const double finf=1e20;
const double pi=acos(-1.0);
struct Point 
{
	long long x,y;
	friend Point operator + (Point a,Point b){
		return {a.x+b.x,a.y+b.y};
	}
	friend Point operator - (Point a,Point b){
		return {a.x-b.x,a.y-b.y};
	}
	friend double operator * (Point a,Point b){
		return a.x*b.x+a.y*b.y;
	}
	friend Point operator * (Point a,long long k){
		return {a.x*k,a.y*k};
	}
	friend Point operator / (Point a,long long k){
		return {a.x/k,a.y/k};
	}
	friend double operator % (Point a,Point b){
		return a.x*b.y-a.y*b.x;
	}
	friend bool operator < (Point a,Point b){
		if(a.x!=b.x) return a.x<b.x;
		else return a.y<b.y;
	}
	friend bool operator == (Point a,Point b){
		return (a.x==b.x&&a.y==b.y);
	}
	double abs()
	{
		return sqrt(x*x+y*y);
	}
	long long abs2()
	{
		return x*x+y*y;
	}
	
}; 

//三角形面积*2
long long sqr(Point A,Point B,Point C)
{
	Point ab=B-A,ac=C-A;
	return ab%ac;
} 
//求凸包（逆时针），返回凸包点个数， p和poly均从0开始
int get_poly(Point *p,Point *poly,int n)
{
	n=unique(p,p+n)-p;
	sort(p,p+n);
	int tp=-1;
	poly[++tp]=p[0];
	for(int i=1;i<n;i++){
		while(tp>0&&((poly[tp]-poly[tp-1])%(p[i]-poly[tp-1])<=0)){
			tp--;
		}
		poly[++tp]=p[i];
	}
	int num1=tp;
	for(int i=n-2;i>=0;i--){
		while(tp>num1&&((poly[tp]-poly[tp-1])%(p[i]-poly[tp-1])<=0)){
			tp--;
		}
		poly[++tp]=p[i];
	}
//	if(n>1) tp--;
	return tp;
}

//获得凸包poly的直径 
long long get_poly_len(Point *poly,int n)
{
	long long mlen=0;
	int k=2;
	for(int i=0;i<n;i++){
		int j=(i+1)%n;
		while(sqr(poly[i],poly[j],poly[k])<sqr(poly[i],poly[j],poly[(k+1)%n])) k=(k+1)%n;
		mlen=max({mlen,(poly[i]-poly[k]).abs2(),(poly[j]-poly[k]).abs2()});
	}
	return mlen;
}
Point p[N],poly[N];
int n;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p[i].x>>p[i].y;
	}
	int num=get_poly(p,poly,n);
	cout<<get_poly_len(poly,num)<<'\n';
	return 0;
}
```