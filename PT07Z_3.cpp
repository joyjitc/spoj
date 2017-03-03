#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Node{
public:
	int dist;
	bool explored;
	list<int> edge;
	Node(){
		explored = false;
	}
};

class Tree{
	int N;
	vector<Node> nodes;
public:
	Tree(int n){
		this->N = n;
		nodes.resize(n+1);
	}
	void addEdge(int src, int des){
		nodes[src].edge.push_back(des);
		nodes[des].edge.push_back(src);
	}
	void bfs_shortest_path(int source){
		nodes[source].dist = 0;
		nodes[source].explored = true;
		
		queue<int> Q;
		Q.push(source);

		int curr;

		while(!Q.empty()){
			curr = Q.front();
			for(list<int>::iterator it = nodes[curr].edge.begin();it!= nodes[curr].edge.end();++it){
				if(!nodes[*it].explored){
					nodes[*it].explored = true;
					nodes[*it].dist = nodes[curr].dist + 1;
					Q.push(*it);
				}
			}
			Q.pop();
		}

	}
	void reset_explored(){
		for(int i = 0;i<=N;i++)
			nodes[i].explored = false;
	}
	int return_longest_path(){
		// for(int i =1;i<=this->N;i++){
		// 	cout<<i<<"-> ";
		// 	for(auto it = nodes[i].edge.begin(); it!= nodes[i].edge.end();++it)
		// 		cout<<(*it)<<" - ";
		// 	cout<<endl;
		// }
		bfs_shortest_path(1);
		int index, max_dist=0;
		for(int i =1;i<=N;i++){
			// cout<<"Debug :: "<<nodes[i].dist<<endl;
			if(nodes[i].dist>max_dist){
				max_dist = nodes[i].dist;
				index = i;
			}
		}
		// cout<<"Index = "<<index<<endl;
		reset_explored();
		bfs_shortest_path(index);
		// for(int i =1;i<=N;i++){
		// 	cout<<"Debug :: "<<nodes[i].dist<<endl;
		// }

		max_dist = 0;
		for(int i =1;i<=N;i++){
			max_dist = max(max_dist,nodes[i].dist);
		}
		return max_dist;
	}
};

int main(){
	ios::sync_with_stdio(false);
	int N;
	cin>>N;
	Tree t(N);
	N--;
	int u,v;
	while(N--){
		cin>>u>>v;
		t.addEdge(u,v);
	}
	cout<<t.return_longest_path()<<endl;
	return 0;
}