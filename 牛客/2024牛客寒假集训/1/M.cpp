#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;
const int inf = 2e9;
typedef pair<int, int> PII;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<PII> b;
    b.reserve(n);
    multiset<int> st;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        b.emplace_back(a[i], i);
        st.insert(a[i]);
    }

    sort(b.begin(), b.end());
    auto [x, pos] = b[0];
    st.extract(x);
    st.insert(x * 2);

    int l, r;
    l = r = pos;
    int ans = *st.rbegin() - *st.begin();
    for(auto [_,i] : b)
    {
        if(i >= l && i <= r) continue;
        for(int j = l - 1; j >= i; j --)
        {
            st.extract(a[j]);
            st.insert(a[j] * 2);
            ans = min(ans, *st.rbegin() - *st.begin());
        }
        l = min(l, i);
        for(int j = r + 1; j <= i; j ++)
        {
            st.extract(a[j]);
            st.insert(a[j] * 2);
            ans = min(ans, *st.rbegin() - *st.begin());
        }
        r = max(r, i);
    }
    cout << ans << '\n';
    return 0;
}