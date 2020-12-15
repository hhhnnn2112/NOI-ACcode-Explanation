#include<cstdio>
#include<algorithm>
#include<cctype>

using namespace std;

const int logn=25,maxn=2000005;

int f[maxn][logn],Logn[maxn];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch))
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
	while(isdigit(ch))
    {
        x=x*10+ch-48;
        ch=getchar();
    }
	return x*f;
}

void pre()
{
    Logn[1]=0;
    Logn[2]=1;
    for (int i=3;i<maxn;++i)
        Logn[i]=Logn[i/2]+1;
    return ;
}
int main()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)
        f[i][0]=read();
    pre();
    for(int j=1;j<=logn;++j)
        for(int i=1;i+(1<<j)-1<=n;++i)
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    for (int i=1;i<=m;++i)
    {
        int x=read(),y=read();
        int s=Logn[y-x+1];
        printf("%d\n",max(f[x][s],f[y-(1<<s)+1][s]));
    }
    return 0;
}