#include<iostream>
using namespace std;
int a[101],b[101],n;
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)//读入每条鱼的可爱值
        cin>>a[i];
    for (int i=1;i<=n;i++)//枚举N条鱼
        for (int j=i;j>=1;j--)//从第I个位置倒着往前找
        {
            if (a[j]<a[i])
                b[i]++;//如果找到比第I条鱼丑的，统计数组b对应的b[i]+1
        }
    for (int i=1;i<=n;i++) cout<<b[i]<<" ";//输出
    return 0;
}