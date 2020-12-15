#include <iostream>
#include <cstdio>
using namespace std;
int main()  {
	long long N; //int »áÒç³ö 
	scanf("%lld",&N); 
	while( N  != 1) {
		long long t;		
		if( N % 2) {
			t = N * 3 + 1;
			printf("%lld*3+1=%lld\n",N,t);
		}
		else {
			t = N /2;
			printf("%lld/2=%lld\n",N,t);
		}
		N = t;
	}
	printf("End\n"); 
	return 0;
}
