#include <iostream>
#include <tr1/unordered_set>
#include <vector>

using namespace std;

typedef struct adjSet
{
	bool visited;
	tr1::unordered_set<int> edges;
	adjSet(){
		visited = false;
	}
}adjSet;

class uDuWGraph
{
	int N;
	int M;
	bool isCycle;
	vector<adjSet> node;
public:
	uDuWGraph(int N,int M)
	{
		this->N=N;
		this->M=M;
		isCycle = false;
		node.resize(N+1);
	}
	void createGraph()
	{
		int src,des;
		for(int i = 0; i<this->M; i++)
		{
			cin>>src>>des;
			this->addEdge(src,des);
		}
	}
	void addEdge(int src,int des)
	{
		node[src].edges.insert(des);
		node[des].edges.insert(src);
	}
	void isItTree()
	{
		dfs(0,1);
		if(this->isCycle==true)
			cout<<"NO"<<endl;
		else
		{
			for(int i=1; i<=this->N;i++)
			{
				if(this->node[i].visited==false)
				{
					cout<<"NO"<<endl;
					return;
				}
			}
			cout<<"YES"<<endl;
		}
	}
	void dfs(int comingFrom,int source)
	{
		if(this->node[source].visited==true)
		{
			this->isCycle = true;
			return;
		}
		else
		{
			this->node[source].visited=true;
			for(tr1::unordered_set<int>::iterator it = this->node[source].edges.begin(); it != this->node[source].edges.end(); ++it)
			{
				if((*it)!=comingFrom)
					dfs(source,(*it));
			}

		}
	}


};

int main()
{
	ios::sync_with_stdio(false);
	int N,M;
	cin>>N>>M;
	uDuWGraph g(N,M);
	g.createGraph();
	g.isItTree();
	return 0;
}


// #include <iostream>

// using namespace std;

// int main()
// {
// 	ios::sync_with_stdio(false);
// 	int N,M;
// 	int a,b;
// 	cin>>N>>M;
// 	for(int i = 0;i<M; i++)
// 		cin>>a>>b;
// 	if(N==M+1)
// 		cout<<"YES"<<endl;
// 	else 
// 		cout<<"NO"<<endl;
// 	return 0;
// }