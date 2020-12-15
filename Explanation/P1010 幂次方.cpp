#include<stdio.h>
int a[30];
int dfs(int n)
{
//幂为0、1、2则直接输出，>=3则递归求解。
    int i=0;
    if(n!=0)
    {
        while(n>=a[i]) i++; i--; //找到最大的幂
        n-=a[i];//下面12~20行是处理减去的这部分。
        printf("2");
        if(i!=1)printf("(");//注意1次幂是2而不是2(1)
        if( i==0 || i == 2 ) printf("%d)",i);//幂为0、1、2时可输出幂(幂1时无输出)
        //如果幂>=3，对幂递归，不输出幂。
        if(i>=3) {dfs(i);printf(")");}//递归求解，再添加右括号。
        if(n!=0) {printf("+");dfs(n);}//子问题与子问题之间用+连接;处理剩余的n(子问题)。
    }
    return;
}
int main(void)
{
    int i,n;
    a[0]=1;
    for(i=1;i<50;i++)
        a[i]=a[i-1]*2; //a：1 2 4 8 16 32……
    scanf("%d",&n);
    dfs(n);
    return 0;
}