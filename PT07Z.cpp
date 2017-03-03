#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Node{
public:
	int longest_path;
	bool explored;
	list<int> edge;
	Node(){
		explored = false;
		longest_path = 0;
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
	int dfs_lp(int index){
		// cout<<"Index = "<<index<<endl;
		// cout<<"explored = "<<nodes[index].explored<<endl;
		this->nodes[index].explored = true;
		// cout<<"explored = "<<nodes[index].explored<<endl;		

		int higher = -1, highest = -1;
		for(list<int>::iterator it = nodes[index].edge.begin(); it!= nodes[index].edge.end();++it){
			if(!this->nodes[(*it)].explored){
				int val = dfs_lp(*it);
				// cout<<*it<<" "<<val<<endl;
				if(val>higher)
					higher = val;
				if(higher>highest){
					// swap(higher,highest);
					int t = higher;
					higher = highest;
					highest = t;
				}
			}
		}
		nodes[index].longest_path = higher+highest+2;
		// cout<<"Index = "<<index<<" lp = "<<nodes[index].longest_path<<" "<<higher<<" "<<highest<<endl;
		return (highest+1);
	}
	int return_longest_path(){
		// cout<<N<<endl;
		// for(int i =1;i<=this->N;i++){
		// 	cout<<i<<"-> ";
		// 	for(auto it = nodes[i].edge.begin(); it!= nodes[i].edge.end();++it)
		// 		cout<<(*it)<<" - ";
		// 	cout<<endl;
		// }
		int a = dfs_lp(1);

		int lp = -1;
		for(int i=1;i<=this->N;i++){
			// cout<<"i = "<<i<<" "<<nodes[i].longest_path<<"explored = "<<nodes[i].explored<<endl;
			lp = max(lp,nodes[i].longest_path);
		}
		return lp;
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