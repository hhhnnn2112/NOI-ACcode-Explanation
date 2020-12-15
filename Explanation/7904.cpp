// By Guo Wei
#include <iostream>
#include <cstdio>
using namespace std;
int a[11];
int main()
{
	for(int i = 0;i < 10; ++i)
		cin >> a[i];
	int h;
	cin >> h;
	int total = 0;
	for(int i = 0;i < 10; ++i)
		if( h + 30 >= a[i])
			++ total;
	cout << total;
	return 0;
}

