#include <iostream>
#include <cstdio>
using namespace std;
#define PI 3.1415926
#define EPS 1e-8;
int main()
{
	int h,r;
	scanf("%d%d",&h,&r);
	double f = 20000.0/(h*PI*r*r);
	int n = f;
	n += (f - n) > EPS; //说不定有的编译器 true 不为1,那就不行了 
	printf("%d",n);
	return 0;
}
