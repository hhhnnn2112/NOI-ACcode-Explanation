//By Guo Wei
#include <iostream>
#include <cstring>
using namespace std;
const int MX = 5;
int a[MX+10][MX+10]; 
int maxJ[MX+10]; //maxJ[i]是第i行的最大值的列号 
int minI[MX+10]; //minI[j]是第j列的最小值的行号 
int main()
{
	for(int i = 1;i <= MX; ++i) {
		cin >> a[i][1];
		maxJ[i] = 1;
		for(int j = 2; j <= MX; ++j) {
			cin >> a[i][j];
			if( a[i][j] > a[i][maxJ[i]])
				maxJ[i] = j;
		}
	}
	for(int j = 1;j <= MX; ++j) {
		minI[j] = 1;
		for(int i = 2;i <= MX; ++i)
			if( a[i][j] < a[minI[j]][j])
				minI[j] = i;
	}
	bool found = false;
	for(int i = 1;i <= MX; ++i) {
		if( minI[maxJ[i]] == i ) {//第i行最大值所在的列，其最小值所在的行正好是i，那么a[i][maxJ[i]]是鞍点  {
			cout << i << " " << maxJ[i] << " " << a[i][maxJ[i]] << endl;
			found = true;
		}
	}
	if( !found)
		cout << "not found" << endl;
	return 0;
}
