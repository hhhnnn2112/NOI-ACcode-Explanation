#include <iostream>
#include <cstdio>
using namespace std;
#define PI 3.14
int main()
{
	double r;
	scanf("%lf",&r); 
	printf("%.2f",4/3.0*PI*r*r*r);  //不要写成4/3，因4/3 = 1 
	return 0;
}
