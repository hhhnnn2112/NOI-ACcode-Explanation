#include<bits/stdc++.h>
using namespace std;
int r,a[100],n;
void dfs(int k){//搜索第k个数
    int i;
    if(k>r){
        for(i=1;i<=r;i++){
            cout<<setw(3)<<a[i];//输出，场宽为三
        }
        cout<<endl;
        return ;//回到前一层
    }
    for(i=a[k-1]+1;i<=n;i++){
        a[k]=i;
        dfs(k+1);//直接进行下一次调用
    }
}
int main()
{
    cin>>n>>r;
    dfs(1);
    return 0;
}  