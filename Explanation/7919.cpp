// By Guo Wei
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int r = 0;
	while ( n ) {
		r = r * 10 + ( n % 10);
		n /= 10;
	}
	cout << r;
	return 0;
}

