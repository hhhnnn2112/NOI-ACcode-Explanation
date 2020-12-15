// By Guo Wei
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int sum = 0;
	for(int i = 0; i < n; ++i) {
		int x ;
		scanf("%d",&x);
		sum += x;
	}
	printf("%d %.5f",sum,(double)sum / n);
	return 0;
}

