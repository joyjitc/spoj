#include <bits/stdc++.h>
using namespace std;
struct Edge{
	int src,des,cost;
	Edge(int a, int b,int c):src(a),des(b),cost(c) {}
};

struct comp{
	bool operator()(const Edge& a, const Edge& b){
		return a.cost<b.cost;
	}
};

class DisjointSet{
	struct Element{
		int parent, rank;
		Element(int p):parent(p),rank(0){}
	};
	vector<Element> a;
public:
	DisjointSet(int n){
		a.reserve(n+1);
		for(int i=1;i<=n;i++)
			a[i] = Element(i);
	}
	int findSet(int x){
		if(a[x].parent==x)
			return x;
		else
			return findSet(a[x].parent);
	}
	void mergeSet(int x,int y){
		int root_x = findSet(x);
		int root_y = findSet(y);
		if(root_y == root_x)
			return;
		if(a[root_x].rank>a[root_y].rank)
			a[root_y].parent = root_x;
		else if(a[root_x].rank<a[root_y].rank)
			a[root_x].parent  = root_y;
		else{
			a[root_y].parent = root_x;
			a[root_x].rank++;
		}
	}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int t;
	cin>>t;
	int p,n,m;
	int a,b,c;
	vector<Edge> h;
	unordered_set<int> s;
	unsigned long long final_cost;
	while(t--){
		cin>>p;
		cin>>n;
		cin>>m;
		
		for(int i=0;i<m;i++){
			cin>>a>>b>>c;
			h.push_back(Edge(a,b,c));		
		}
		sort(h.begin(),h.end(),comp());
		final_cost=0;
		DisjointSet ds(n);
		for(int i=0;i<h.size();i++){
			if(ds.findSet(h[i].src)!=ds.findSet(h[i].des)){
				final_cost+=h[i].cost;
				ds.mergeSet(h[i].src,h[i].des);
			}
		}
		final_cost = final_cost*p;
		cout<<final_cost<<"\n";
		s.clear();
		h.clear();
	}
}
