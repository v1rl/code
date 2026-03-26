## 1-1 加油宣言

#### 知识点：语法

```cpp
#include<bits/stdc++.h>
using namespace std;

int main () {
    cout << "Dai Ma Qiao Bian,BUG Zai Jian,Tian Ti Sai Chong Ya!";
    return 0;
}
```

## 1-2 甘い飴

#### 知识点：语法

```cpp
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define pii pair<int,int>
const int mod = 1e9 + 7;

void solve() {
    int x,y,z;
    cin >> x >> y >> z;
    int ans = max({x,y,z});
    cout << ans;
}  

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
```

## 1-3 咦，我赢了！

#### 知识点：模拟

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
	map<string,string> mp;
	mp["jiandao"]="shitou";
	mp["shitou"]="bu";
	mp["bu"]="jiandao";
	while(1){
		string s;
		cin>>s;
		if(s=="end") break;
		cout<<mp[s]<<'\n';
	} 
}

signed main() {
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

## 1-4 点亮字符

#### 知识点：模拟

```cpp
#include <bits/stdc++.h>
using namespace std;
void solve() {
	string s;
	cin>>s;
	int len=s.length();
	int num=10+(len-1)*100;
	int ans=(num+30-1)/30;
	cout<<ans<<'\n';
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
 } 
```

## 1-5 exkmp

#### 知识点：模拟 / Z函数

$O(n^2)$

```cpp
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    vector<int> z(n);
    for(int i = 1; i < n; i ++) {
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i] ++;
        }
    }

    for(int i = 0; i < n; i ++) {
        cout << z[i] << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while(t --) {
        solve();
    }
    return 0;
}
```

$O(n)$

```cpp
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<int> zFunction(string &s) {
	int n = s.size();
	vector<int> z(n);
	for(int i = 1, l = 0, r = 0; i < n; i ++) {
		if(i <= r) {
			z[i] = min(z[i - l], r - i + 1);
		}

		while(i + z[i] < n && s[i + z[i]] == s[z[i]]) {
			z[i] ++;
		}

		if(i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}

void solve() {
	string s;
	cin >> s;
	vector z = zFunction(s);
    for(int i = 0; i < s.size(); i ++) {
    	cout << z[i] << " \n"[i == s.size() - 1];
    }
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	// cin >> t;
	t = 1;
	while(t --) {
		solve();
	}
	return 0;
}
```

## 1-6 倒数第N个字符串

#### 知识点：进制转换

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int L;
    long long N;
    cin >> L >> N;

    long long total = 1;
    for (int i = 0; i < L; i++) total *= 26;

    long long x = total - N;
    string ans(L, 'a');

    for (int i = L - 1; i >= 0; i--) {
        ans[i] = char('a' + (x % 26));
        x /= 26;
    }

    cout << ans << '\n';
    return 0;
}
```

## 1-7 剪切粘贴

#### 知识点：字符串模拟

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n;
    cin >> n;

    while (n--) {
        int l, r;
        string pre, post;
        cin >> l >> r >> pre >> post;

        int L = l - 1, R = r - 1;
        string clip = s.substr(L, R - L + 1);
        s.erase(L, R - L + 1);
        
        string key = pre + post;
        size_t pos = s.find(key);
        if (pos == string::npos) {
            s += clip;
        } else {
            size_t ins = pos + pre.size();
            s.insert(ins, clip);
        }
    }

    cout << s << '\n';
    return 0;
}
```

## 1-8 泉此方的循环

#### 知识点：前缀和

```cpp
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<i64> pre(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> pre[i];
        pre[i] += pre[i - 1];
    }

    int p = 0;
    while(q --) {
        int op;
        cin >> op;
        if(op == 1) {
            int c;
            cin >> c;
            p += c;
            p %= n;
        } else {
            int l, r;
            cin >> l >> r;
            l += p, r += p;
            l = (l - 1) % n + 1;
            r = (r - 1) % n + 1;
            if(l <= r) {
                cout << pre[r] - pre[l - 1] << '\n';
            } else {
                cout << pre[n] - pre[l - 1] + pre[r] << '\n';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
```

## 2-1 我要创造一个只有0的世界！

#### 知识点：贪心

```cpp
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define pii pair<int,int>
const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    char c = s[0];
    for(int i = 0; i < s.size(); i++) {
        if(c != s[i]) {
            ans++;
            c = s[i];
        }
    }
    if(s[s.size()-1] == '1') ans++;
    cout << ans << endl;
} 

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
```

## 2-2 愤怒的牛

#### 知识点：二分答案

```cpp
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);

    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    auto check = [&](i64 mid) {
        int cnt = 1;
        int lst = a[0];
        for(int i = 1; i < n; i ++) {
            if(a[i] - lst >= mid) {
                cnt ++;
                lst = a[i];
            }
        }
        return cnt >= m;
    };

    i64 l = 0, r = (1ll << 31) - 1;
    while(l < r) {
        i64 mid = l + r + 1 >> 1;
        if(check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << l << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
```

## 2-3 我爱平方数

#### 知识点：质因数分解，思维

```cpp
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    i64 x, l, r;
    cin >> x >> l >> r;

    i64 v = 1;
    for(int i = 2; i <= x / i; i ++) {
        if(x % i == 0) {
            int cnt = 0;
            while(x % i == 0) {
                x /= i;
                cnt ++;
            }
            if(cnt & 1) {
                v *= i;
            }
        }
    }
    if(x > 1) {
        v *= x;
    }

    l = (l + v - 1) / v;
    r /= v;

    i64 t = l;
    l = sqrt(l);
    if(l * l < t) {
        l ++;
    }
    r = sqrt(r);

    if(l <= r) {
        cout << v * l * l << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}
```

## 2-4 请给三国杀好评喵~

#### 知识点：模拟

```cpp
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define pii pair<int,int>
const int mod = 1e9 + 7;

struct node{
    string c1,c2;
};

void solve() {
    int n,k,m,p;
    cin >> n >> k >> m >> p;
    vector<node> a(k+1);
    for(int i = 1; i <= k; i++) {
        cin >> a[i].c1 >> a[i].c2;
    }
    auto xp = [&]() -> void {
        int idx1 = k/2+1, idx2 = 1;
        vector<node> b;
        b.push_back({"",""});
        for(int i = 1; i <= k/2; i++) {
            b.push_back(a[idx1++]);
            b.push_back(a[idx2++]);
        }
        if(k % 2) b.push_back(a[idx1]);
        a = b;
    };
    for(int i = 1; i <= m; i++) xp();
    vector<node> ans;
    for(int i = 1; i <= k; i++) {
        if((i-1) % n == p-1) ans.push_back(a[i]);
        if(ans.size() == 4) break;
    }
    if(n * 4 > k) cout << "Error:cards not enough";
    else {
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i].c1 << ' ' << ans[i].c2 << endl;
        }
    }
} 

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
```

## 3-1特殊堆栈

#### 知识点：思维，数据结构，模拟，二分

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,x;
    string s;
    vector<int>a,b;
    cin >> n;
    while(n--) {
        cin >> s;
        if(s == "Push") {
            cin >> x;
            a.push_back(x);
            auto it=lower_bound(b.begin(), b.end(), x);
            b.insert(it, x);
        } else if(s == "Pop") {
            if(a.size()==0) {
             	cout << "Invalid\n";
            } else {
                auto it = lower_bound(b.begin(), b.end(), a[a.size()-1]);
                b.erase(it);
                cout<<a[a.size()-1]<<endl;
                a.pop_back();
            }
        } else {
            if(b.size()==0) {
            	cout << "Invalid\n";
            } else {
                if(b.size() & 1) {
                	cout << b[b.size() >> 1] << endl;
                } else {
                	cout << b[b.size() - 1 >> 1] << endl;
                }
            }
        }
    }
    return 0;
}
```

## 3-2 英語は本当に難しいな

#### 知识点：ST表，线段树

```cpp
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define pii pair<int,int>
const int mod = 1e9 + 7;
int a[100005];
struct tree{
    int l,r;
    int add,mx,pre;
}t[2000005];

void build(int u, int l, int r) {
    t[u].l = l, t[u].r = r;
    if(l == r) {
        t[u].pre = a[l];
        t[u].mx = a[l];
        return;
    }
    int m = l + r >> 1;
    build(u*2,l,m);
    build(u*2+1,m+1,r);
    t[u].mx = max({t[u].pre,t[u*2].mx, t[u*2+1].mx});
}

int ask(int u, int x, int y) {
    if(t[u].l >= x&&t[u].r <= y) {
        return t[u].mx;
    }
    int ans = 0;
    int m = (t[u].l + t[u].r) >> 1;
    if(x <= m) ans = max(ans,ask(u*2,x,y));
    if(y > m) ans = max(ans,ask(u*2+1,x,y));
    return ans;
}

struct node{
    string s,ss;
    int idx;
};

bool cmp(node a, node b) {
    if(a.ss != b.ss) return a.ss < b.ss;
    else return a.idx < b.idx;
}

void solve() {
    int n,m;
    cin >> n >> m;
    vector<node> b(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> b[i].s;
        for(int j = 0; j < b[i].s.size(); j++) {
            char c = b[i].s[j];
            if(c >= 'A'&&c <= 'Z') b[i].ss += (char)tolower(c);
            else b[i].ss += c;
        }
        b[i].idx = i;
    }
    sort(b.begin()+1,b.end(),cmp);
    for(int i = 1; i <= n; i++) {
        a[b[i].idx] = i;
    }
    build(1,1,n);
    for(int i = 1; i <= m; i++) {
        int l,r;
        cin >> l >> r;
        cout << b[ask(1,l,r)].s << endl;
    }
} 

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
```

## 3-3 泉此方的线代模拟

#### 知识点：线性代数，高斯消元

```cpp
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const double EPS = 1e-8;
double sgn(double x) {
    if(fabs(x) < EPS) {
        return 0;
    }
    return x < 0 ? -1 : 1;
}

pair<int, vector<double>> gauss(int n, auto &g) {
    for(int x = 1; x <= n; x ++) {
        int sel = x;
        for(int i = 1; i <= n; i ++) {
            if(i < x && sgn(g[i][i]) != 0) {
                continue;
            }
            if(fabs(g[i][x]) > fabs(g[sel][x])) {
                sel = i;
            }
        }

        if(sgn(g[sel][x]) == 0) {
            continue;
        }

        swap(g[x], g[sel]);
        double div = g[x][x];
        for(int j = x; j <= n + 1; j ++) {
            g[x][j] /= div;
        }
        for(int i = 1; i <= n; i ++) {
            if(i != x) {
                double fac = g[i][x];
                for(int j = x; j <= n + 1; j ++) {
                    g[i][j] -= fac * g[x][j];
                }
            }
        }
    }

    int f = 1;
    vector<double> ans(n + 1);
    for(int x = 1; x <= n; x ++) {
        if(sgn(g[x][x]) == 0) {
            if(sgn(g[x][n + 1]) == 0) {
                f = 0;
            } else {
                f = -1;
                break;
            }
        } else {
            ans[x] = g[x][n + 1];
        }
    }

    return {f, ans};
}

void solve() {
    int n;
    cin >> n;
    vector g(n + 1, vector(n + 2, (double)0.0));
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n + 1; j ++) {
            cin >> g[i][j];
        }
    }

    auto [f, ans] = gauss(n, g);

    if(f == 1) {
        for(int i = 1; i <= n; i ++) {
            cout << "x" << i << "=" << ans[i] << '\n';
        }
    } else {
        cout << f << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(3);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
```