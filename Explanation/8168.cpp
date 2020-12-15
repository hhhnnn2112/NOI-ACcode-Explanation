// By Guo Wei
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a,n;
	cin >> a >> n;
	int v = a;
	for(int i = 0 ;i < n - 1; ++i)
		v *= a;
	cout << v;
	return 0;
}

