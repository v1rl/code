#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
第一次必须往下后就只能用第二行的内容了
确定最优之后再考虑利用前后缀求个数
*/


void solve() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    string s;
    s += s1[0];
    bool f = false;
    for(int i = 1; i < n; i ++) {
        if(s1[i] == s2[i - 1]) {
            s += s1[i];
        } else if(s2[i - 1] == '0') {
            f = true;
            s += s2.substr(i - 1);
            break;
        } else {
            s += s1[i];
        }
    }
    if(!f) {
        s += s2[n - 1];
    }
    cout << s << '\n';


    int num1 = 0, num2 = 0;
    for(int i = 0; i < n; i ++) {
        if(s1[i] == s[i]) {
            num1 ++;
        } else {
            break;
        }
    }
    for(int i = n - 1; i >= 0; i --) {
        if(s2[i] == s[i + 1]) {
            num2 ++;
        } else {
            break;
        }
    }

    cout << num1 + num2 - n << '\n';
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