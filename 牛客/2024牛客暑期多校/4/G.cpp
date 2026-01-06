#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        i64 x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        double dist1 = sqrt((x2 + x1) * (x2 + x1) + (y2 - y1) * (y2 - y1));
        double dist2 = sqrt((x2 - x1) * (x2 - x1) + (y1 + y2) * (y1 + y2));
        printf("%.10lf\n", min(dist1, dist2));
    }

}
