#include<bits/stdc++.h>
using namespace std;
vector<list<int>> g;
vector<bool> visited;
void dfs(int i){
	visited[i]=1;
	for(int x:g[i]){
		if(!visited[x])
			dfs(x);
	}
}
int main(){
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		g.resize(n);
		int e;
		cin>>e;
		int a,b;
		while(e--){
			cin>>a>>b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		int ans=0;
		visited.resize(n,0);
		for(int i=0;i<n;i++){
			if(!visited[i]){
				ans++;
				dfs(i);
			}
		}
		cout<<ans<<"\n";
		visited.clear();
		g.clear();
	}	
}