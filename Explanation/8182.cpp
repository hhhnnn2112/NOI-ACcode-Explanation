// By Guo Wei
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n,x,minV,maxV;
	cin >> n >> x;
	minV = maxV = x;
	while(--n) {
		cin >> x;
		if( x < minV)
			minV = x;
		if( x > maxV)
			maxV = x;				
	}
	cout << maxV - minV;
	return 0;
}

