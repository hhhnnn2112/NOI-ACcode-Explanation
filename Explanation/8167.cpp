// By Guo Wei
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;
const int MX = 110;
short a[MX][MX];
short b[MX][MX];
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n; ++i)
		for(int j = 1; j <= m; ++j )  {
			cin >> a[i][j];
			b[i][j] = a[i][j];
		}
	for(int i = 1;i <= n; ++i)
		for(int j = 1; j <= m; ++j ) {
			if( i > 1 && i < n && j > 1 && j < m) {
				int sum = a[i][j] + a[i-1][j] + a[i+1][j]+a[i][j-1]+a[i][j+1];
				int v = sum / 5;
				double f = (double)sum / 5;
				if( f - v - 0.5 > 1e-6)
					++v;
				b[i][j] = v;
			}
		}
	for(int i = 1;i <= n; ++i) {
		for(int j = 1; j <= m; ++j ) 
			cout << b[i][j] << " ";
		cout << endl;
	}
	return 0;
}

