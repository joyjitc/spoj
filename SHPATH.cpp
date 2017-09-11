#include <bits/stdc++.h>

using namespace std;

struct Edge{
	int destiny;
	int cost;
	Edge(int d,int c): destiny(d),cost(c){}
};
struct DjScore{
	int destiny;
	int score;

	DjScore(int d=0,int s=0): destiny(d),score(s){}
};

struct comp{
	bool operator()(const DjScore& a, const DjScore& b){
		return a.score>b.score;
	}
};


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	unordered_map<string, int> city_index;
	vector<list<Edge> > graph;
	int n;
	string city;
	vector<bool> visited;
	vector<int> dis;
	int no_of_neighbour,neighbour,cost;
	vector<pair<int,int> > query;
	int no_of_query;
	string src,des;
	priority_queue<DjScore, vector<DjScore>, comp> heap;
	DjScore cur;
	while(t--){
		cin>>n;
		graph.resize(n+1);
		for(int i=1;i<=n;i++){
			cin>>city;
			city_index[city]=i;
			cin>>no_of_neighbour;
			for(int j=0;j<no_of_neighbour;j++){
				cin>>neighbour>>cost;
				graph[i].push_back(Edge(neighbour,cost));
			}
		}

		cin>>no_of_query;
		for(int j=0;j<no_of_query;j++){
			cin>>src>>des;
			query.push_back(pair<int,int>(city_index[src],city_index[des]));
		}

		for(auto x:query){
			visited.resize(n+1,0);
			dis.resize(n+1,INT_MAX);

			heap.push(DjScore(x.first,0));
			while(!heap.empty()){
				cur = heap.top();
				heap.pop();
				if(!visited[cur.destiny]){
					visited[cur.destiny] = 1;
					dis[cur.destiny] = cur.score;
					for(Edge e:graph[cur.destiny]){
						if(!visited[e.destiny]){
							heap.push(DjScore(e.destiny,e.cost+cur.score));
						}
					}
				}
			}

			cout<<dis[x.second]<<"\n";
			visited.clear();
			dis.clear();
		}
		query.clear();
		graph.clear();
	}
}