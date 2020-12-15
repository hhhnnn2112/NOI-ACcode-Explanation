#include<iostream>
#include<cstdio>
using namespace std;
int n,ans1,ans2[10001][11],sum,a[11];
void trys(int t,int m)//t代表当前的尝试的调料。m代表当前美味程度
{
    if (t>10)
    {
        if (m==n) //如果美味程度与猪猪的要求相等
        {
            ans1++;//统计方案总数
            for (int i=1;i<=10;i++)
                ans2[ans1][i]=a[i];//存入答案的数组
        }
        return ;
    }
    for (int i=1;i<=3;i++)
    {
        if (m+i>n) break;//如果超过了要求，那么后面的就可以直接忽略
        a[t]=i;//储存答案
        trys(t+1,m+i);//查看下一种调料
        a[t]=0;//状态恢复
    }
}
int main()
{
    cin>>n;
    trys(1,0);//从第一种调料开始尝试，美味程度为0
    cout<<ans1<<endl;
    for (int i=1;i<=ans1;i++)
    {
        for (int j=1;j<=10;j++)
            cout<<ans2[i][j]<<" ";
        cout<<endl;
    }//输出结果
    return 0;
}
