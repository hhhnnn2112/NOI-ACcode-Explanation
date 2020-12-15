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
		}
	for(int i = 1;i <= n; ++i)
		for(int j = 1; j <= m; ++j ) {
			b[j][i] = a[i][j];
		}
	for(int i = 1;i <= m; ++i) {
		for(int j = 1; j <= n; ++j ) 
			cout << b[i][j] << " ";
		cout << endl;
	}
	return 0;
}

