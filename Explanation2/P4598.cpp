#include<bits/stdc++.h>
using namespace std;
const int mod = 1231238613;
int n,cnt1,cnt2,cnt;
int data[105],p1[10005],p2[10005];
struct node
{
    int a,b;
}ans[105];
bool cmp(node x,node y)
{
	return 1ll*x.a*y.b<1ll*y.a*x.b;
}
int gcd(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	return gcd(b,a%b);
}
bool judge(int x,int y)
{
	int temp[106];
	memset(temp,0,sizeof temp);
	int a=1,b=1,sum=0;
	for(int i=0;i<=n;i++)
    {
        temp[i] = (1ll*data[i]*a % mod + mod)%mod;
        a = 1ll*a*x%mod;
    }
    for(int i=n;i>=0;i--)
    {
        sum = (sum+1ll*temp[i]*b % mod+ mod)%mod;
        b = 1ll*b*y%mod;
    }
    return sum==0;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
        scanf("%d",&data[i]);
    int t = 0;
    while(data[t]==0)
        t++;
    //找到第一个非零位 
    for(int i=1;i*i<=abs(data[t]);i++)
    {
        if(abs(data[t])%i==0)
        {
            p1[++cnt1] = i;
            if(i*i!=abs(data[t])&&abs(data[t])/i!=0)
                p1[++cnt1] = abs(data[t])/i;
        }
    } 
    for(int i=1;i*i<=abs(data[n]);i++)
    {
        if(abs(data[n])%i==0)
        {
            p2[++cnt2] = i;
            if(abs(data[n])/i!=0&&i*i!=abs(data[n]))
                p2[++cnt2] = abs(data[n])/i ;
        }
    }
    //取出data[t]和data[n]的约数
    for(int i=1;i<=cnt1;i++)
    {
        for(int j=1;j<=cnt2;j++)
        {
            if(gcd(p1[i],p2[j])!=1)
                continue;
            //枚举各自约数，如果是互质再判断是不是解 
            if(judge(p1[i],p2[j]))
            {
                ans[++cnt].a = p1[i];
                ans[cnt].b   = p2[j];
            }
            if(judge(-p1[i],p2[j]))
            {
                ans[++cnt].a = -p1[i];
                ans[cnt].b   = p2[j];
            }
            //正负有理数解 
        }
    }
    if(judge(0,1))
    {
        ans[++cnt].a = 0;
        ans[cnt].b   = 1;
    }//特判0的情况 
    printf("%d\n",cnt);
    sort(ans+1,ans+1+cnt,cmp);//对答案排序 
    for(int i=1;i<=cnt;i++)
    {
        if(ans[i].b==1)
            printf("%d\n",ans[i].a);
        else
            printf("%d/%d\n",ans[i].a,ans[i].b);
    }
    return 0;
}
