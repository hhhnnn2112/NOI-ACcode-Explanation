#include <iostream>//c++标准库
using namespace std;
int main(){
    int a,n,t=0,i=0,b,s=0;//t判断有没有回车，i判断输出什么，s判断有没有输完
    cin>>n;
    while(s<n*n){
        cin>>a;//循环输入a；
        i++;
        for(b=a;b>=1;b--){
            if(t==n){cout<<endl;t=0;}//判断是否需要回车，回车后t要清零
            if(i%2==1)cout<<0;
            else cout<<1;//判断是否i不被2整除，输出0，否则输出1，注意不要回车
            t++;
            s++;//t与s加一
        }
    }
    cout<<endl;
    return 0;
}