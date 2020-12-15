#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=a;i<=b;i++)
#define pre(i,a,b) for(register int i=a;i>=b;i--)
#define N 1000005
#define E puts("dldsgay!!1")
typedef long long ll;

using namespace std;

int n,a[2][N],u[N<<1];
bool v[N<<1];
int c[N],f[N];

inline void add(int x)
{
    for(;x<=n;x+=x&-x)
        c[x]++;
}
inline int ask(int x)
{
    register int sum=0;
    for(;x;x-=x&-x)
        sum+=c[x];
    return sum;
}
char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<21],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read()
{
    int x=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return x;
}
int main(){
    n=read();
    rep(op,0,1)
        rep(i,1,n)
            a[op][i]=read();
    register int x,y;
    rep(op,0,1)
        rep(i,1,n)
            x=read(),u[x]=i,v[x]=op;
    rep(op,0,1)
        rep(i,1,n)
        {
            x=v[a[op][i]],y=u[a[op][i]];
            if(op^x&&((i&1)==(y&1)))
            {
                E;
                return 0;
            }
            if(op==x&&((i&1)!=(y&1)))
            {
                E;
                return 0;
            }
            if(op==0)
                f[i]=y;
        }
    register ll ans=0;
    rep(i,1,n)
        ans+=ask(n)-ask(f[i]),add(f[i]);
    printf("%lld\n",ans);
    return 0;
}