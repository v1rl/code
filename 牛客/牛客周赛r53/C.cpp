#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < n; i ++)
    {
        if(s[i] == '0') cnt ++;
        else if(s[i] == '1' && cnt) ans ++, cnt --;
    }
    cout << min(ans, b) << '\n';
    return 0;
}