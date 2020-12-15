#include<cstdio>
#include<cmath>

using namespace std;

const int N=25;

int n,k;
int a[N];
int ans;

int choose[N];

int prime(int n)
{
    if(n==1||n==0)
        return false;
    int m=2;
    while(m<=int(sqrt(n)))
    {
        if(n%m==0)
            return false;
        else
            ++m;
    }
    return true;
}

void dfs(int sum,int num,int nowpos)
{
    //printf("# sum: %d num: %d #\n",sum,num);
    if(num==k)
    {
        //printf("* %d *\n",sum);
        if(prime(sum))
        {
            ++ans;
            /*for(int i=0;i<=num-1;++i)
                printf("%d ",choose[i]);
            printf("\n");*/
        }
        return ;
    }
    for(int i=nowpos;i<=n;++i)
    {
        //choose[num]=a[i];
        dfs(sum+a[i],num+1,i+1);
    }

}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    dfs(0,0,1);
    printf("%d\n",ans);
    return 0;
}