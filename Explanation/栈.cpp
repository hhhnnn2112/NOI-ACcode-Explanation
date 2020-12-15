#include<iostream>
using namespace std;
long n,f[20][20];//f数组记录方案
long dfs(int x,int y)//x是操作队列里元素的个数，y是栈里的个数
{
    if(f[x][y]!=0) return f[x][y];//记忆化，走过的方案直接调用
    if(x==0) return 1;//当操作队列里没有了，就只有一种方案了
    if(y>0) f[x][y]+=dfs(x,y-1);//栈里不为空的时候才可以把栈里的元素推出
    f[x][y]+=dfs(x-1,y+1);//操作队列里元素减一，栈里元素加一
    return f[x][y];//返回方案值
}
int main()
{
    cin>>n;
    cout<<dfs(n,0)<<endl;
    return 0;
}