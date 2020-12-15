#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>

using namespace std;

const int N=20000005,MOD=1000000007;

int n,m,a[N],b[2],f[N];

inline int lowbit(int x) {
    return (x&(-x));
}

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;++i) scanf("%d",&a[1<<i]);
    scanf("%d",&m);
    for(int i=0;i<m;++i) scanf("%d",&b[i]);
    f[0]=1;
    for(int i=1;i<(1<<n);++i) {
        a[i]=a[lowbit(i)]+a[i^lowbit(i)];
        if(a[i]==b[0] || a[i]==b[1])
            continue;
        for(int j=i;j;j^=lowbit(j)) (f[i]+=f[i^lowbit(j)])%=MOD;
    }
    printf("%d\n",f[(1<<n)-1]);
    return 0;
}