#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>

typedef long long ll;

using namespace std;

const int N=100005;

queue <int> q1,q2,q3;

ll n,m,lenadd,u,v,t,totadd;
double p;

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&lenadd,&u,&v,&t);
    p=1.0*u/v;
    int input[N];
    for(int i=1;i<=n;++i)
        scanf("%d",&input[i]);
    sort(input+1,input+n+1,cmp);
    for(int i=1;i<=n;++i)
        q1.push(input[i]);
    for(int i=1;i<=m;++i)
    {
        ll val1,val2,val3;
        val1=val2=val3=-1;
        if(!q1.empty())
            val1=q1.front();
        if(!q2.empty())
            val2=q2.front();
        if(!q3.empty())
            val3=q3.front();
        ll len;
        if(val1 >= val2 && val1 >= val3)
            len=val1,q1.pop();
        else if(val2 >= val1 && val2 >= val3)
            len=val2,q2.pop();
        else
            len=val3,q3.pop();

        len+=lenadd*(i-1); //当前这只蚯蚓的长度
        
        ll after1=ll(1.0*p*len);
        ll after2=len-after1;

        after1-=lenadd*i;
        after2-=lenadd*i;

        if(after1>=after2)
        {
            q2.push(after1);
            q3.push(after2);
        }
        else
        {
            q2.push(after2);
            q3.push(after1);
        }
        totadd+=lenadd;
        if(i%t==0)
            printf("%lld ",len);
    }
    printf("\n");
    while(!q1.empty() || !q2.empty() || !q3.empty())
    {
        ll big=0,pos=0;
        if(!q1.empty())
        {
            ll now=q1.front();
            if(now>big)
                big=now,pos=1;
        }
        if(!q2.empty())
        {
            ll now=q2.front();
            if(now>big)
                big=now,pos=2;
        }
        if(!q3.empty())
        {
            ll now=q3.front();
            if(now>big)
                big=now,pos=3;
        }
        printf("%lld\n>",big);
        cout<<q1.size()<<' '<<q2.size()<<' '<<q3.size()<<endl;
        system("pause");
        if(pos==1)
            q1.pop();
        else if(pos==2)
            q2.pop();
        else if(pos==3)
            q3.pop();
    }
    printf("\n");
    return 0;
}