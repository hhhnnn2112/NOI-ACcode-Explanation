#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

const int N=205;

int g[N],FatherOf[N];//0~n, n+1~2n+1
int ancu1,ancv1,ancu2,ancv2;
int n,m;
int u,v;
string s;

int GetA(int x)
{
    if(x==FatherOf[x])
        return x;
    else
        return FatherOf[x]=GetA(FatherOf[x]);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=2*n+1;++i)
        FatherOf[i]=i;
    for(int i=1;i<=m;++i)
    {
        cin>>u>>v>>s;
        --u;
        ancu1=GetA(u);
        ancv1=GetA(v);
        ancu2=GetA(n+u+1);
        ancv2=GetA(n+v+1);
        if(s[0]=='o')// 奇数个1
        {
            if(ancv1==ancu1)
            {
                printf("%d\n",i-1);
                return 0;
            }
            FatherOf[ancu2]=ancv1;
            FatherOf[ancv2]=ancu1;
        }
        else
        {
            if(ancu1==ancv2)
            {
                printf("%d\n",i-1);
                return 0;
            }
            FatherOf[ancv1]=ancu1;
            FatherOf[ancv2]=ancu2;
        }
    }
    printf("%d\n",m);
    return 0;
}
//偶数判断意面，链接同面，等于==有问题
//奇数判同面，连意面