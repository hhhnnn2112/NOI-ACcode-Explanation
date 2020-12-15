#include<cstdio>

using namespace std;

int n;

int main()
{
    scanf("%d",&n);
    if(n<3 && n==5)
    {
        printf("-1\n");
        return 0;
    }
    for(int i=n/14;i>=0;--i)
        for(int j=i;j<=n/4;++j)
            for(int k=i;k<=n/3;++k)
                if(i*7+j*4+k*3 == n)
                {
                    printf("%d %d %d\n",i,j,k);
                    return 0;
                }
    printf("-1\n");
    return 0;
}