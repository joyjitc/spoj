#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int d,t;
	Edge(int _d,int _t):d(_d),t(_t){}
};
struct Djscore{
	int des,score;
	Djscore():des(0),score(0){}
	Djscore(int a,int b):des(a),score(b){}
};
struct comp{
	bool operator()(Djscore& l, Djscore& r){
		return l.score>r.score;
	}
};
int main(){
	ios::sync_with_stdio(0);
	int t;cin>>t;
	while(t--){
		int n,m,src,des;
		cin>>n>>m>>src>>des;
		vector<list<Edge>> g(n+1);
		int a,b,c;
		while(m--){
			cin>>a>>b>>c;
			g[a].push_back(Edge(b,c));
			g[b].push_back(Edge(a,c));
		}
		priority_queue<Djscore,vector<Djscore>,comp> q;
		vector<int> dist(n+1,INT_MAX);
		q.push(Djscore(src,0));
		Djscore cur;
		while(!q.empty()){
			cur=q.top();
			q.pop();
			if(dist[cur.des]==INT_MAX){
				dist[cur.des]=cur.score;
				for(auto& x:g[cur.des]){
					if(dist[x.d]==INT_MAX)
						q.push(Djscore(x.d,cur.score+x.t));
				}
			}
		}
		if(dist[des]==INT_MAX)
			cout<<"NONE\n";
		else
			cout<<dist[des]<<"\n";
	}
}