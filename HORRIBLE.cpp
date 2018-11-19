#include<bits/stdc++.h>
using namespace std;

//Lazy Propagation has been used. 
//lz denotes the tree nodes
//t denoted the lazy nodes
//Just continued a mistake
using ull=unsigned long long;
vector<ull> t,lz;
void push(int v,int x){
	if(t[v]!=0){
		t[v*2]+=t[v];
		t[v*2+1]+=t[v];
		lz[v]+= t[v]*x;
		t[v]=0;
	}
}
void update(int v,int tl,int tr, int l,int r,ull val){
	if(l>r)
		return;
	if(l==tl&&r==tr)
		t[v]+=val;
	else{
		lz[v]+=val*(r-l+1);
		push(v,tr-tl+1);
		int tm=tl+(tr-tl)/2;
		update(v*2,tl,tm,l,min(r,tm),val);
		update(v*2+1,tm+1,tr,max(l,tm+1),r,val);
	}
}
ull get(int v,int tl,int tr,int l,int r){
	if(l>r)
		return 0;
	if(l==tl&&r==tr)
		return lz[v]+ t[v]*(r-l+1);
	push(v,tr-tl+1);
	int tm = tl+(tr-tl)/2;
	return get(v*2,tl,tm,l,min(r,tm))+get(v*2+1,tm+1,tr,max(l,tm+1),r);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int te,n,c;
	cin>>te;
	int type,p,q;
	ull v;
	while(te--){
		cin>>n>>c;
		t.resize(n*5,0);
		lz.resize(n*5,0);
		while(c--){
			cin>>type;
			if(type==1){
				cin>>p>>q;
				cout<<get(1,0,n-1,p-1,q-1)<<"\n";
			//	cout<<"x:lazy:node \n";
			//	for(int x=0;x<t.size();x++){
			//		cout<<x<<" : "<<t[x]<<" : "<<lz[x]<<"\n";
			//	}
			}
			else{
				cin>>p>>q>>v;
				update(1,0,n-1,p-1,q-1,v);
			//	cout<<"x:lazy:node \n";
			//	for(int x=0;x<t.size();x++){
			//		cout<<x<<" : "<<t[x]<<" : "<<lz[x]<<"\n";
			//	}
			}
		}
		t.clear();
		lz.clear();
	}
	
}
