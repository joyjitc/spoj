#include<bits/stdc++.h>
using namespace std;
int N;
vector<int> bit;
void update(int x,int val){
	for(;x<=N;x+=x&-x) bit[x]+=val;
}
void update(int l,int r,int val){
	update(l,val);
	update(r+1,-1*val);
}
int query(int x){
	int val=0;
	for(;x>0;x-=x&-x)val+=bit[x];
	return val;
}

int main(){
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	int u,x,y,val;
	while(t--){
		cin>>N;
		bit.resize(N+1,0);
		cin>>u;
		for(int i=0;i<u;i++){
			cin>>x>>y>>val;
			update(x+1,y+1,val);
		}
		cin>>u;
		for(int i=0;i<u;i++){
			cin>>x;
			cout<<query(x+1)<<"\n";
		}
		bit.clear();
	}
}




