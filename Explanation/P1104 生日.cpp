#include<bits/stdc++.h>
using namespace std;
struct birth{
    string name;
    int year,mon,day;
    bool operator <(birth tmp)const{
        if(year!=tmp.year) return year<tmp.year;
        if(mon!=tmp.mon) return mon<tmp.mon;
        if(day!=tmp.day) return day<tmp.day;
    }
    //重载运算符
};
birth per[105];
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        char c=getchar();
        //过滤行末换行
        string N;
        int y,m,d;
        cin>>N>>y>>m>>d;
        per[i]=(birth){N,y,m,d};
    }
    stable_sort(per+1,per+n+1);
    //STL自带的稳定排序
    for(int i=1;i<=n;i++) cout<<per[i].name<<endl;
    return 0;
}
