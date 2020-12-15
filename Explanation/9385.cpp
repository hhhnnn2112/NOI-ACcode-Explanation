// By Guo Wei
#include <iostream>
using namespace std;
int main()
{
	int n,x,y;
	cin >> n >> x >> y;
	int k = y / x;
	if( y % x )
		++k;
	if( n >= k)
		cout << n - k;
	else
		cout << 0;

	return 0;
}

