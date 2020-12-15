//
// Created by 郑乃硕 on 2020/12/15.
//

using namespace std;
int main()
{
    int k,h=0,p=0;
    cin>>k;
    for(int i=1;;i++)
        for(int j=1;j<=i;j++)
            if(p>=k)  {cout<<h;return 0;}
            else
                h+=i,p++;
    return 0;
}