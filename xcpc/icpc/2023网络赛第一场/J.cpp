#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

/*
注意：cin读入double比读入int要慢很多，当读入数据量大时需要考虑一下是否可以不必读double

注意到：两个圆相离，我们随意在圆C1中取一个点P，并得到它的对称点P`,
那么另外一个圆C2上的点Q到这两个点的平均曼哈顿距离，即Q到圆C1圆心的曼哈顿距离
扩展到所有点不难得出期望距离即Q到圆C1圆心的曼哈顿距离
现在，我们要让期望距离最小
注意到：圆A的圆心为答案的贡献是一个常量，要让期望距离最小，Q(x, y)提供贡献的向量为(正负1, 正负1)
注意到：曼哈顿距离最小的最优点，就是圆心沿着向量的反向走距离r后的点
我们只需要求这个期望最小值，所以直接用两点圆心的曼哈顿距离-C2的半径*根号2

Trick：圆上一点到圆外一点(曼哈顿)距离最小的最优点，就是圆心沿着向量的反向走距离r后的点
*/

double sq2;

void solve() {
	vector<int> a(8);
	for(int i = 0; i < 8; i ++) {
		cin >> a[i];
	}
	double x1 = (a[0] + a[2]) / 2.0;
	double y1 = (a[1] + a[3]) / 2.0;
	double x2 = (a[4] + a[6]) / 2.0;
	double y2 = (a[5] + a[7]) / 2.0;

	double base = fabs(x1 - x2) + fabs(y1 - y2);
	// hypot更慢，但可以防溢出，建议是不适使用hypot手写计算
	double r2 = hypot(a[4] - a[6], a[5] - a[7]) / 2;
	cout << fixed << setprecision(10);
	cout << base - r2 * sqrt(2) << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --) {
		solve();
	}
}