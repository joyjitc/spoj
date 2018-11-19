#include<bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> t;
void build(int v,int tl, int tr){
	if(tl==tr)
		t[v]=a[tl];
	else{
		int tm=tl+(tr-tl)/2;
		build(v*2,tl,tm);
		build(v*2+1,tm+1,tr);
		t[v]=min(t[v*2],t[v*2+1]);
	}
}
int query(int v,int tl,int tr,int l,int r){
	if(l>r)
		return INT_MAX;
	if(l==tl&&r==tr)
		return t[v];
	int tm=tl+(tr-tl)/2;
	return min(query(v*2,tl,tm,l,min(r,tm)),query(v*2+1,tm+1,tr,max(tm+1,l),r));
}
int main(){
	ios::sync_with_stdio(0);
	int te;cin>>te;
	for(int scn=1;scn<=te;scn++){
		int n,q;
		cin>>n>>q;
		int val;
		for(int i=0;i<n;i++){
			cin>>val;
			a.push_back(val);
		}
		t.resize(4*n);
		build(1,0,n-1);
		int x,y;
		cout<<"Scenario #"<<scn<<":\n";
		while(q--){
			cin>>x>>y;
			cout<<query(1,0,n-1,x-1,y-1)<<"\n";
		}
		t.clear();
		a.clear();
	}
}