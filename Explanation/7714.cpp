#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define EPS 1e-7
int main()
{
	double a,b,c; //不要用 float,精度不够
	scanf("%lf%lf%lf",&a,&b,&c);
	double tmp = b*b - 4*a*c;
	if( tmp < EPS && tmp > - EPS)
		printf("x1=x2=%.5f",(-b)/(2*a)+EPS);  // + EPS是为了防止出现 -0.00000 
	else if( tmp > EPS) {
		double x1 = (-b+sqrt(tmp))/(2*a);
		double x2 = (-b-sqrt(tmp))/(2*a)+EPS;
		if( x1 - x2 > EPS)
			printf("x1=%.5f;x2=%.5f",x1+EPS,x2+EPS);
		else
			printf("x1=%.5f;x2=%.5f",x2+EPS,x1+EPS);
	}
	else {
		
		printf("x1=%.5f+%.5fi;x2=%.5f-%.5fi",(-b)/(2*a)+EPS,sqrt(-tmp)/(2*a)+EPS,(-b)/(2*a)+EPS,sqrt(-tmp)/(2*a)+EPS);
	}
	return 0;
}

