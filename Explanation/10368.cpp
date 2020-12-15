/*
程序填空使得输出结果是：
10
20
30
 
*/
#include <iostream>
using namespace std;
int main()
{
	int x,y,z;
	x = 10;
	y = 20;
	z = 30;
	
	int * a[3]  = { &x, &y,&z};
	for( 
//your code starts here	
	int ** p = a; 
//your code ends here	
		p < a + 3; ++p) 
			cout<< * (*p) << endl;
	return 0;
	
}
