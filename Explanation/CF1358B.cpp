#pragma GCC optimize(3)
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=100005;

int n,people,a[N];

int main() {
    scanf("%d",&people);
	for(int t=1;t<=people;++t) {
        scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		int ans=0;
		for(int i=1;i<=n;++i)
			if(i>=a[i])
				ans=i;
		printf("%d\n",ans+1); //+1: Add yourself.
	}
	return 0;
}