//
// Created by 郑乃硕 on 2020/12/15.
//

#include<cstdio>
int n,a[21][21];//出 n(n≤20)
int main()
{
    scanf("%d",&n);//输入
    a[1][1]=1;//初始化
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            a[i][j]=a[i-1][j-1]+a[i-1][j];//进行计算
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)printf("%d ",a[i][j]);//输出
        printf("\n");//换行
    }
    return 0;
}