#include<cstdio>
#include<iostream>
#include<algorithm>//sort必备头文件
#include<cmath>
using namespace std;
int a[1005],c[1005];//定义
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);//读入
    }
    for(int i=1;i<n;i++){
        c[i]=abs(a[i]-a[i+1]);//处理差
    }
    sort(c+1,c+n);
    for(int i=1;i<n;i++){
        if(c[i]!=i){printf("Not jolly\n");return 0;}//判断输出
    }
    printf("Jolly\n");//如果未能输出，则为正确答案
    return 0;//过程结束
}