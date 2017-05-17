#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int status;
	unordered_set<int> edge;
	Node(){
		status=0;
	}
};
bool homo;
// void buglife(vector<Node>& graph,int node,int status){
// 	if(homo)
// 		return;
// 	if(graph[node].status==0){
// 		graph[node].status=status;
// 		for(int x:graph[node].edge){
// 			buglife(graph,x,(-1)*status);
// 		}
// 		return;
// 	}
// 	else{
// 		if(graph[node].status==status)
// 			return;
// 		else{
// 			homo = true;
// 			return;
// 		}
// 	}
// }
void buglife(vector<Node>& graph, int node){
	graph[node].status = 1;
	queue<int> q;
	q.push(node);
	int cur_node;
	while(!q.empty()&&!homo){
		cur_node=q.front();
		q.pop();
		for(int x:graph[cur_node].edge){
			if(graph[x].status==0){
				graph[x].status=(-1)*graph[cur_node].status;
				q.push(x);
			}
			else if(graph[x].status==graph[cur_node].status){
				homo=true;
				return;
			}
		}

	}

}
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	int nodes, edges;
	vector<Node> graph;
	int a,b;
	for(int scenario=1;scenario<=t;scenario++){
		homo=false;
		cin>>nodes>>edges;
		graph.resize(nodes+1);
		for(int i=1;i<=edges;i++){
			cin>>a>>b;
			graph[a].edge.insert(b);
			graph[b].edge.insert(a);
		}
		for(int j=1;j<=nodes;j++){
			if(homo)
				break;
			if(graph[j].status==0){
				// buglife(graph,j,1);	
				buglife(graph,j);		
			}
		}
		cout<<"Scenario #"<<scenario<<":"<<endl;
		if(homo)
			cout<<"Suspicious bugs found!"<<endl;
		else
			cout<<"No suspicious bugs found!"<<endl;

		graph.clear();
	}
	return 0;
}