#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int des,cost;
	Edge(int d,int c):des(d),cost(c){}
};
struct DjikstraScore{
	int des, score;
	DjikstraScore(int d, int s):des(d),score(s){}
};
struct comp{
	bool operator()(const DjikstraScore& a, const DjikstraScore& b){
		return a.score>b.score;
	}
};
int main(){
	ios::sync_with_stdio(0);
	int N,E,T,M;
	cin>>N>>E>>T>>M;
	int a,b,c;
	vector<list<Edge> > graph;
	graph.resize(N+1);
	for(int i=0;i<M;i++){
		cin>>a>>b>>c;
		graph[b].push_back(Edge(a,c));
	}
	vector<int> dist(N+1,-1);
	priority_queue<DjikstraScore,vector<DjikstraScore>,comp> pq;
	pq.push(DjikstraScore(E,0));
	DjikstraScore top= DjikstraScore(0,0);
	while(!pq.empty()){
		top = pq.top();
		pq.pop();
		if(dist[top.des]==-1){
			dist[top.des]=top.score;
			for(Edge x:graph[top.des]){
				if(dist[x.des]==-1)
					pq.push(DjikstraScore(x.des,top.score+x.cost));
			}
		}
	}
	int ans = 0;
	for(int i=1;i<=N;i++){
		if(dist[i]<=T&&dist[i]!=-1)
			ans++;
	}
	cout<<ans<<"\n";	
}
