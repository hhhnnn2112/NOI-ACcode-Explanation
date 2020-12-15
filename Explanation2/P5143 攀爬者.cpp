#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Node{
    double x,y,z;
    bool operator<(const Node &other)const{//重载小于运算符
        return z<other.z;
    }
} a[50050];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z);
    }
    sort(a,a+n);//每个点高度从小到大排序
    double ans=0;
    double cx=a[0].x,cy=a[0].y,cz=a[0].z;
    for(int i=1;i<n;i++){
        ans+=sqrt(abs(cx-a[i].x)*abs(cx-a[i].x)+abs(cy-a[i].y)*abs(cy-a[i].y)+abs(cz-a[i].z)*abs(cz-a[i].z));//两点的欧几里得距离
        cx=a[i].x;
        cy=a[i].y;
        cz=a[i].z;
    }
    printf("%.3lf\n",ans);//输出保留三位小数
    return 0;//华丽的结束
} 