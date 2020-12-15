# include <cstdio>
# include <cstring>
using namespace std;

char a[21][1000];
bool cmp(char x[],char y[])//比较2个数谁更适合当首位
{
    char a1[1000],a2[1000];
    strcpy(a1,x);
    strcpy(a2,y);
    strcat(a1,y);
    strcat(a2,x);
    if(strcmp(a1,a2) >= 0) return true;
    else return false;
}
void swap(int i,int j)//交换2个数组
{
    char temp[1000];
    strcpy(temp,a[i]);
    strcpy(a[i],a[j]);
    strcpy(a[j],temp);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) scanf("%s",a[i]);
    for(int i = 1;i <= n;i++)
        for(int j = i + 1;j <= n;j++)
        {
            if(cmp(a[i],a[j]) == false)  swap(i,j);
        }
    for(int i = 1;i <= n;i++) printf("%s",a[i]);
    return 0;
}