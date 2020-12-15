#include<cstdio>
#include<iostream>
#include<map>
#include<string>

using namespace std;

const int N=20005,M=1000005;

map <string,int> p;
int n,m,k;
int FatherOf[N],ancx,ancy;
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
    for(int i=1;i<=n;++i)
    {
        cin>>s;
        p[s]=i;
    }
    for(int i=1;i<=n;++i)
        FatherOf[i]=i;
    for(int i=1;i<=m;++i)
    {
        string a,b;
        cin>>a>>b;
        int ancx=GetA(p[a]),ancy=GetA(p[b]);
        if(ancx!=ancy)
            FatherOf[ancx]=ancy;
    }
    scanf("%d",&k);
    for(int i=1;i<=k;++i)
    {
        string a,b;
        cin>>a>>b;
        int ancx=GetA(p[a]),ancy=GetA(p[b]);
        if(ancx==ancy)
            printf("Yes.\n");
        else
            printf("No.\n");
        //printf("Ancestor x:%d ;Ancestor y:%d\n",ancx,ancy);
    }
    return 0;
}