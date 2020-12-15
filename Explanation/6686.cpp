#include<cstdio>
typedef long long ll;

const int N=200005,MOD=998244353;

ll f[N],ans;
int n,m,k,l=1;

inline int max(int a,int b) {
    return a>b?a:b;
}

int main() {	
	scanf("%d",&n);
	for(register int i=1;i<=n;++i) {
        int t;
		scanf("%d",&t);
		++f[t];
        m=max(m,t);
	}
	for(register int i=1;i<=m;++i) {
		for(;l<i*2&&l<=m;++l)
			k+=f[l];
		ans+=(f[i]-1)*f[i]*(k-f[i])/2+(f[i]-2)*(f[i]-1)*f[i]/6;
	}
	printf("%lld\n",ans%998244353);
	return 0;
}