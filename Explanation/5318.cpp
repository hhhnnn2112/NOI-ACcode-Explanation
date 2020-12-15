#include<bits/stdc++.h>

using namespace std;  

struct edge {
	int u,v;
};

vector<int> e[100001];
vector<edge> s;

bool vis1[100001],vis2[100001];

inline bool cmp(edge x,edge y) {
	if(x.v==y.v)
	    return x.u<y.u;
	return x.v<y.v;
}
inline void dfs(int x) {
	vis1[x]=1;
	cout<<x<<" ";
	for(int i=0;i<e[x].size();++i) {
		int point=s[e[x][i]].v;
		if(!vis1[point])
			dfs(point);
	}
    return ;
}
inline void bfs(int x) {
	queue <int> q;
	q.push(x);
	cout<<x<<" ";
	vis2[x]=1;
	while(!q.empty()) {
		int fro=q.front();
		for(int i=0;i<e[fro].size();++i) {
			int point=s[e[fro][i]].v;
			if(!vis2[point]){
				q.push(point); 
				cout<<point<<" ";
				vis2[point]=1;
			}
		}
		q.pop();
	}
    return ;
}
int main() {
	int n,m;
	cin>>n>>m; 
	for(int i=0;i<m;++i) {
		int uu,vv;
		cin>>uu>>vv;
		s.push_back((edge){uu,vv});   
	}
	sort(s.begin(),s.end(),cmp);
	for(int i=0;i<m;++i)   
		e[s[i].u].push_back(i); 
	dfs(1);
	cout<<"\n";
	bfs(1);
    cout<<"\n";
}