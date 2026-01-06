#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 inf = 1e18;

//  5 6 3 4 1 2

// 4 3 2 1 7 6 

int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {  // ch 不是数字时
    if (ch == '-') w = -1;        // 判断是否为负
    ch = getchar();               // 继续读入
    }
    while (ch >= '0' && ch <= '9') {  // ch 是数字时
    x = x * 10 + (ch - '0');  // 将新读入的数字「加」在 x 的后面
    // x 是 int 类型，char 类型的 ch 和 '0' 会被自动转为其对应的
    // ASCII 码，相当于将 ch 转化为对应数字
    // 此处也可以使用 (x<<3)+(x<<1) 的写法来代替 x*10
    ch = getchar();  // 继续读入
    }
    return x * w;  // 数字 * 正负号 = 实际数值
}

template<class Info>
struct Segmentree {
    int n;
    vector<Info> info;
    int cnt = 0;

    Segmentree(int n_) : n(n_), info(52 * 4 * (n + 1)) {};

    void pushup(int p) {
        info[p].val = info[info[p].ls].val + info[info[p].rs].val;
    }

    void build(int &p, int l, int r, string &s, int op) {
        if(!p) p = ++ cnt;
        if(l == r) {
            if(s[l] - 'a' == op) {
                info[p].val = 1;
            }
            return;
        }
        int mid = l + r >> 1;
        build(info[p].ls, l, mid, s, op);
        build(info[p].rs, mid + 1, r, s, op);
        pushup(p);
    }

    void build(int &p, string &s, int op) {
        build(p, 1, n, s, op);
    }

    void modify(int &p, int &q, int l, int r, int x, int y) {
        if(r < x || l > y) return;
        if(l >= x && r <= y) {
            swap(p, q);
            return;
        }
        int mid = l + r >> 1;
        modify(info[p].ls, info[q].ls, l, mid, x, y);
        modify(info[p].rs, info[q].rs, mid + 1, r, x, y);
        pushup(p), pushup(q);
    }

    void modify(int &p, int &q, int x, int y) {
        modify(p, q, 1, n, x, y);
    }

    int query(int p, int l, int r, int x, int y) {
        if(r < x || l > y) return 0;
        if(l >= x && r <= y) return info[p].val;
        int mid = l + r >> 1;
        return query(info[p].ls, l, mid, x, y) + query(info[p].rs, mid + 1, r, x, y);
    }

    int query(int p, int x, int y) {
        return query(p, 1, n, x, y);
    }
};

struct Info {
    int val = 0;
    int ls = 0, rs = 0;
};

void solve() {
    int n, m;
    n = read(), m = read();
    string s;
    cin >> s;
    s = '#' + s;
    vector<int> root(26);
    Segmentree<Info> tr(n);
    for(int i = 0; i < 26; i ++) {
        tr.build(root[i], s, i);
    }

    while(m --) {
        int op;
        op = read();
        if(op == 1) {
            int l, r, d;
            l = read(), r = read(), d = read();
            d %= 26;
            for(int i = 0, j = 26 - d - 1; i < j; i ++, j --) {
                tr.modify(root[i], root[j], l, r);
            }
            for(int i = 26 - d, j = 26 - 1; i < j; i ++, j --) {
                tr.modify(root[i], root[j], l, r);
            }
            for(int i = 0, j = 26 - 1; i < j; i ++, j --) {
                tr.modify(root[i], root[j], l, r);
            }
        } else {
            int l, r;
            l = read(), r = read();
            int odd = 0;
            for(int i = 0; i < 26; i ++) {
                int num = tr.query(root[i], l, r);
                if(num & 1) odd ++;
                // if(num) cout << char('a' + i) << ' ' << num << '\n';
            }
            if(odd > 1) {
                cout << "No" << '\n';
            } else {
                cout << "Yes" << '\n';
            }
        }
    }
}

int main() {
    // ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = read();
    // cin >> t;

    while(t --) {
        solve();
    }
    return 0;
}