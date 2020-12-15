利用快速排序算法将读入的 NN 个数从小到大排序后输出。
第 1 行为一个正整数 N，第 2 行包含 N 个空格隔开的正整数
5
4 2 4 5 1

//////
1 2 4 4 5

#include<bits/stdc++.h>//万能头（贼爽，但别把变量名设成其他关键字）
#define F(i,n,m) for(int i=n;i<=m;i++)//灵性define，减少码量（for打得我烦）
using namespace std;
int a[10000001];
int main()
{
    int n;
    cin>>n;
    F(i,1,n)
        cin>>a[i];//输入

    random_shuffle(a+1,a+n+1); //打乱它
    sort(a+1,a+n+1);//快排（终究我还是用了STL的sort）

    F(i,1,n)
        cout<<a[i]<<' ';//输出
    return 0;
}