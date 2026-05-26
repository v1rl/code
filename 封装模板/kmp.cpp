#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
ne[i]，以i结尾的，与前缀串相等的，最长的后缀串的长度
*/

vector<int> kmp(string &s) {
    int n = s.size();
    vector<int> ne(n);
    for(int i = 1, j = 0; i < n; i ++) {
        while(j && s[i] != s[j]) {
            j = ne[j - 1];
        }
        if(s[i] == s[j]) {
            j ++;
        }
        ne[i] = j;
    }
    return ne;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    string a, b;
    cin >> a >> b;

    int n = a.size(), m = b.size();

    auto ne = kmp(b);

    for(int i = 0, j = 0; i < n; i ++) {
        while(j && a[i] != b[j]) {
            j = ne[j - 1];
        }
        if(a[i] == b[j]) {
            j ++;
        }
        if(j == m) {
            cout << i - m + 2 << '\n';
            j = ne[j - 1];
        }
    }

    for(int i = 0; i < m; i ++) {
        cout << ne[i] << ' ';
    }
}

