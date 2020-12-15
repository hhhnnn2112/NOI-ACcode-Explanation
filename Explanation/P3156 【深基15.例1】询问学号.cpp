#include<cstdio>
int a[2000001];//2*10^6
int main()
{
    int n,m,sum;//注意不要把数组开在主函数里
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&sum);//询问学号
        printf("%d\n",a[sum]);
    }
}