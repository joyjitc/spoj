#include<bits/stdc++.h>
using namespace std;
struct hash{
	inline size_t operator()(const pair<int,int>& p)const{
		return p.first*31+p.second%19;
	}
};
struct dist{
	int d1,d2;
	dist():d1(-1),d2(-1){}
};

int C,R;
bool mode;
void cal(auto& m,int i,int j, int dis){
	if(i<0||i>=R||j<0||j>=C)
		return;
	if(m.find(pair<int,int>(i,j))==m.end())
		return;
	if(mode){
		if(m[make_pair(i,j)].d1!=-1)
			return;
		m[make_pair(i,j)].d1 = dis;
	}
	else{
		if(m[make_pair(i,j)].d2!=-1)
			return;
		m[make_pair(i,j)].d2 = dis;
	}
	
	cal(m,i+1,j,dis+1);
	cal(m,i+1,j-1,dis+1);
	cal(m,i+1,j+1,dis+1);
	cal(m,i,j+1,dis+1);
	cal(m,i,j-1,dis+1);
	cal(m,i-1,j,dis+1);
	cal(m,i-1,j-1,dis+1);
	cal(m,i-1,j+1,dis+1);
}
int main(){
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	char block;
	int max_dist;
	unordered_map<pair<int,int>, dist,hash> m;
	while(t--){
		cin>>C>>R;
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				cin>>block;
				if(block=='.'){
					m[make_pair(i,j)]=dist();
				}	
			}
		}
		mode = true;
		auto it = m.begin();
		cal(m,it->first.first, it->first.second,0);
		max_dist = -1;
		pair<int,int> max_node;
		for(auto x:m){
			if(x.second.d1>max_dist)
				max_node = x.first;
				max_dist = x.second.d1;
		}
		mode = false;
		max_dist = -1;
		cal(m,max_node.first,max_node.second,0);
		for(auto x:m){
			if(x.second.d2>max_dist)
				max_dist = x.second.d2;
		}
		cout<<"Maximum rope length is "<<max_dist<<".";
		m.clear();
	}
}
