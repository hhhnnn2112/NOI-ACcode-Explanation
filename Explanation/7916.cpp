// By Guo Wei
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int L,R;
	int total = 0;
	cin >> L >> R; 

	for(int i = L; i <= R; ++i) {
		int n = i;
		while(n) {
			if( n % 10 == 2)
				++ total;
			n /= 10;				
		}
	}
	cout << total ;
	return 0;
}

