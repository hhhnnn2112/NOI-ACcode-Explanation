#include<cstdio>

using namespace std;

const int N=150005;

int n,k,FatherOf[N];
int p,x,y;
int cnt;
int ancu1,ancu2,ancu3,ancv1,ancv2,ancv3;

int GetA(int x)//寻找祖先节点
{
    if(x==FatherOf[x])
        return x;
    else
        return FatherOf[x]=GetA(FatherOf[x]);
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=3*n;++i)
        FatherOf[i]=i;
    for(int i=1;i<=k;++i)
    {
        scanf("%d%d%d",&p,&x,&y);
        if(x>n || y>n || (p==2 && x==y))//如果不用依赖其他条件就已经假话
        {
            ++cnt;//假话+1
            continue;//不再往后做
        }
        if(p==1 && x==y)//已经是自己和自己同类
            continue;//不再往后做
        
        //寻找每一层x,y各自的祖先
        ancu1=GetA(x);
        ancv1=GetA(y);

        ancu2=GetA(x+n);
        ancv2=GetA(y+n);

        ancu3=GetA(x+2*n);
        ancv3=GetA(y+2*n);

        if(p==1)//xy同类
            if(ancu2==ancv1 || ancu1==ancv2)//如果已经在一个集合里，即异面同祖
            {
                ++cnt;
                continue;
            }
            else//如果还不在同一个集合
            {
                FatherOf[ancu1]=ancv1;//同行，同类
                FatherOf[ancu2]=ancv2;
                FatherOf[ancu3]=ancv3;
            }
        else
        {
            if(ancu1==ancv1/*如果是同类*/ || ancu1==ancv2/*不能反吃*/)//ancu1==ancv2是因为如果a已经能吃b，b是不能反吃的
            {
                ++cnt;
                continue;
            }
            else
            {
                FatherOf[ancu2]=ancv1;//b <- a
                FatherOf[ancu3]=ancv2;//c <- b
                FatherOf[ancu1]=ancv3;//a <- c
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}