#include <iostream>
#include <utility>
#include <queue>
#include <unordered_set>
#include <list>
#include <iomanip>

struct DjNode{
	int dest;
	double prob;
	DjNode(int a,double b):dest(a),prob(b){}
};

struct comp{
	bool operator() (DjNode& l, DjNode& r){
		return l.prob<r.prob;
	}
};

using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int n,m;
	while(1){
		cin>>n;
		if(n==0)
			break;
		cin>>m;
		vector<list<pair<int,int> > > g(n+1);
		int a,b,p;
		for(int i=0;i<m;i++){
			cin>>a>>b>>p;
			g[a].push_back(make_pair(b,p));
			g[b].push_back(make_pair(a,p));
		}
		unordered_set<int> visited;
		priority_queue<DjNode,vector<DjNode>,comp> q;
		q.push(DjNode(1,1));
		DjNode cur(0,0);
		double ans;
		while(!q.empty()){
			cur = q.top();
			q.pop();
			if(cur.dest == n){
				ans = cur.prob;
				break;
			}
			if(visited.count(cur.dest)>0)
				continue;
			else
				visited.insert(cur.dest);

			for(auto& x:g[cur.dest]){
				q.push(DjNode(x.first,cur.prob*x.second/100));
			}
		}
		cout<<fixed<<setprecision(6)<<ans*100<<" percent\n";

	}
}