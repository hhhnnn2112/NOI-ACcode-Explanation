#include<cstdio>

using namespace std;

int n,a,b,ans,f[9000][2];

inline int max(int a,int b) {
    return a>b?a:b;
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&f[i][1]);
    ans=f[1][1];
    for(int i=1;i<n;++i) {
        scanf("%d%d",&a,&b);
        f[b][1]+=f[a][0];
        f[b][0]+=max(f[a][0],f[a][1]);
        ans=max(ans,f[b][1]);
        ans=max(ans,f[b][0]);
    }
    printf("%d\n",ans);
    return 0;
}