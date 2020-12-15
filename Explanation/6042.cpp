// By Guo Wei
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int M,N,X;
	cin >> M >> N >> X;
	while(X > 0) {
		int t = M / N;
		if( M % N)
			++t;
		if( X < t )
			break;
		X -= t;
		t = M / N;
		N += t;
	}
	cout << N;
	return 0;
}

