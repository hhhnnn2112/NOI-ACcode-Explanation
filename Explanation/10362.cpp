/*
程序填空，使其输出结果是：

1,2,3,4,
10,12,14,16,
18,20,11,12,

 
*/
#include <iostream>
using namespace std;

void Double(int * p, int n)
{
	for(int i = 0;i < n; ++i)
		p[i] *= 2;
}


int main()
{
	int a[3][4] = { { 1,2,3,4},{5,6,7,8},
					{ 9,10,11,12 } };
	
	Double(
	//your code starts here
	
		a[1],6
	//your code ends here				
	);
	for(int i = 0;i < 3; ++i) {
		for(int j = 0; j < 4; ++j)
			cout << a[i][j] << ",";
		cout << endl; 
	}
	
	return 0;
}

