// By Guo Wei
#include <iostream>
#include <cstdio>
using namespace std;
#define eps 1e-6
int main()
{
	int n;
	int total,valid;
	scanf("%d",&n);
	scanf("%d%d",&total,&valid);
	double x = (double)valid/total;
	while(--n) {
		scanf("%d%d",&total,&valid);
		double y = (double)valid/total;
		if( y - x - 0.05 > eps )
			printf("better\n");
		else if( x - y - 0.05 > eps)
			printf("worse\n");
		else
			printf("same\n");
	}
	return 0;
}

