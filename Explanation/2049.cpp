#include <cstdio>
#include <iostream>
#include <algorithm>
#define ri register int
using namespace std;
const int N=105;
int n,m,k,sum,a[N][N],ans[N*N];
bool v[N],u[N][N][N];
//v:答案桶；u：状态桶

inline int read () {
    int x=0,y=1; char ch='\000';
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') y=-1;
    for (;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch^'0');
    return x*y;
}

void dfs (int i,int j,int num) {
	u[i][j][num%k]=1;//状态已访问
	if (i==n&&j==m) {//边界
		if (!v[num%k]) {//答案不存在
			ans[++sum]=num%k;//则加入ans数组
			v[num%k]=1;//答案定义为已被访问
			return ;
		}
	}
    /*若下一状态为访问，则转移*/
	if (i<n&&(!u[i+1][j][(num*a[i+1][j])%k])) dfs (i+1,j,(num*a[i+1][j])%k);
	if (j<m&&(!u[i][j+1][(num*a[i][j+1])%k])) dfs (i,j+1,(num*a[i][j+1])%k); 
}

int main () {
	n=read(); m=read(); k=read();
	for (ri i=1;i<=n;i++) 
		for (ri j=1;j<=m;j++) 
			a[i][j]=read();
	dfs (1,1,a[1][1]);//a[1][1]为必乘数
	printf ("%d\n",sum);
	sort (ans+1,ans+1+sum);//从小到大
	for (ri i=1;i<=sum;i++) printf ("%d ",ans[i]);
	printf ("\n");
	return 0;
}
/*
#include<cstdio>
#include<queue>

using namespace std;

const int N=105,M=10005;

struct node
{
    int x,y,val;
}p,t;

queue <node> q;

int m,n,k,sum;
int a[N][N],ans[M];
bool vis[N][N][N],v[N];

void dfs(int x,int y,int num)
{
    vis[x][y][num%k]=true;
    if(x==n && y==m)
        if(!v[num%k])
        {
            ++sum;
            ans[sum]=num%k;
            v[num%k]=true;
            return ;
        }
    if(x<n && !vis[x+1][y][num*a[x+1][y]%k])
        dfs(x+1,y,num*a[x+1][y]%k);
    if(y<m && !vis[x][y+1][num*a[x][y+1]%k])
        dfs(x,y+1,num*a[x][y+1]%k);
}

int main()
{
    scanf("%d%d%d",&m,&n,&k);
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
        {
            scanf("%d",&a[i][j]);
            a[i][j]%=k;
        }
    dfs(1,1,a[1][1]);

    printf("%d\n",sum);
    return 0;
}
*/