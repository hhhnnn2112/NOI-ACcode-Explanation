/*
编写GetDoubleFromString函数，该函数可以不断从字符串中取出非负浮点数，再无浮点数可取，则返回值小于0 
	
输入样例
please 121a1 stand 0.7 9.2 1010.3983 0.00001 black stand what 1324.3
12.34 45 78ab78.34

输出样例
121.000000
1.000000
0.700000
9.200000
1010.398300
0.000010
1324.300000
12.340000
45.000000
78.000000
78.340000
*/	

#include <iostream>
#include <iomanip>
using namespace std;
double GetDoubleFromString(char * str)
{	
	//your code starts here
	static char * p;
	if( str ) 
		p = str;
	double num = 0;
	while( *p && !(*p >= '0' && *p <= '9'))
		++p;
	if( *p == 0)
		return -1;
	while( *p >= '0' && *p <= '9' ) {
		num = num * 10 + *p - '0';
		++p;
	}
	if( *p == '.') {
		++p;
		double i = 10;
		while( *p >= '0' && *p <= '9' ) {
			num += (*p-'0') / i;
			++p;
			i*=10;
		}
	}
	return num;
//your code ends here	
}

int main()
{
	char line[300];
	while(cin.getline(line,280)) {
		double n;
		n = GetDoubleFromString(line);
		while( n > 0) {
			cout << fixed << setprecision(6) << n << endl;
			n = GetDoubleFromString(NULL);
		}
	}
	return 0;
}
