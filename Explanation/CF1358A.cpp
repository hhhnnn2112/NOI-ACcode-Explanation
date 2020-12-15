#pragma GCC optimize(3)
#include<cstdio>

using namespace std;

int t,n,m;

int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&m);
		printf("%d\n",(n*m)/2+(n*m)%2);
	}
	return 0;
}