#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    int A,B,C;
    cin>>A>>B>>C;
    stringstream ss;
    string str;
    int cnt=0;
    for(int i=123;i<=329;i++)
    {
        int j=i*B/A;
        int k=i*C/A;
        int he=0;
        int ji=1;
        ss<<i<<j<<k;
        ss>>str;
        ss.clear();
        for(int j=0;j<9;j++)
        {
            he+=str[j]-48;
            ji*=str[j]-48;
        }
        if(he==45 && ji==362880)
        {
            cout<<i<<" "<<j<<" "<<k<<endl;
            cnt++;
        }
    }
    if(cnt==0) cout<<"No!!!"<<endl;
    return 0;
}