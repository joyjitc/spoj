#include<iostream>
#include<vector>
#include<climits>

using namespace std;

vector<vector<int> > dp;
vector<vector<int> > tree;
int vertexCover (int node, int coming_from, int type){
	if(dp[node][type]!=-1)
		return dp[node][type];
	if(tree[node].size()==1&&tree[node][0]==coming_from){
		if(type==0||type==2){
			dp[node][type] = 0;
			return dp[node][type];
		}
		else if(type==1){
			dp[node][type] = 1;
			return dp[node][type];
		}

	}
	int ans=0;
	int ans0 = 0, ans1 = 0;
	if(type==0){
		for(int i:tree[node]){
			if(i!=coming_from){
				ans+=vertexCover(i,node,1);
			}
		}
	}
	else if(type==1){
		for(int i:tree[node]){
			if(i!=coming_from){
					ans+=vertexCover(i,node,2);
			}
		}
		ans++;
	}
	else if(type==2){
		// ans = min(vertexCover(node,coming_from,0),vertexCover(node,coming_from,1));
		for(int i:tree[node]){
			if(i!=coming_from){
				ans0 += vertexCover(i,node,1);
				ans1 += vertexCover(i,node,2);	
			}
		}
		ans1++;
		ans = min(ans0,ans1);
	}

	dp[node][type] = ans;
	return dp[node][type];
}

int main(){
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	int a,b;
	tree.resize(t+1);
	dp.resize(t+1,vector<int>(3,-1));

	for(int i=1;i<t;i++){
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	cout<<vertexCover(1,0,2)<<"\n";
}