#pragma GCC optimize(3)
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define rint register int

using namespace std;

const int N=105,dirx[]={0,0,1,-1},diry[]={1,-1,0,0};

int r,c,a[N][N],ans,s[N][N];

int dfs(int x,int y)
{
    if(s[x][y])
        return s[x][y];
    s[x][y]=1;
    for(rint i=0;i<4;++i)
    {
        int tx=x+dirx[i];
        int ty=y+diry[i];
        if(tx>0 && ty>0 && tx<=r && ty<=c && a[x][y]>a[tx][ty])
        {
            dfs(tx,ty);
            s[x][y]=max(s[x][y],s[tx][ty]+1);
        }
    }
    return s[x][y];
}

int main()
{
    scanf("%d%d",&r,&c);
    for(rint i=1;i<=r;++i)
        for(rint j=1;j<=c;++j)
            scanf("%d",&a[i][j]);
    for(rint i=1;i<=r;++i)
        for(rint j=1;j<=c;++j)
            if(dfs(i,j)>ans)
                ans=dfs(i,j);
    printf("%d\n",ans);
    return 0;
}