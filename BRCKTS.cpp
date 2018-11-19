#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
vector<pii> tree;
string input;
pii combine(pii l, pii r){
	int del = min(l.first,r.second);
	l.first-=del;
	r.second-=del;
	pii res;
	res.first=l.first+r.first;
	res.second=l.second+r.second;
	return res;
}
void build(int v,int tl,int tr){
	if(tl==tr)
		tree[v]=(input[tl]=='('?pii(1,0):pii(0,1));
	else{
		int tm=tl+(tr-tl)/2;
		build(v*2,tl,tm);
		build(v*2+1,tm+1,tr);
		tree[v]=combine(tree[v*2],tree[v*2+1]);
	}
}
void update(int v,int tl,int tr,int pos){
	if(tl==tr)
		tree[v]=(tree[v].first==1?pii(0,1):pii(1,0));
	else{
		int tm=tl+(tr-tl)/2;
		if(pos<=tm)
			update(v*2,tl,tm,pos);
		else
			update(v*2+1,tm+1,tr,pos);
		tree[v]=combine(tree[v*2],tree[v*2+1]);
	}
}
main(){
	ios::sync_with_stdio(0);
	int n,m,type;
	for(int i=1;i<=10;i++){
		cin>>n>>input>>m;
		tree.resize(n*4);
		build(1,0,n-1);
		cout<<"Test "<<i<<":\n";
		while(m--){
			cin>>type;
			if(type==0){
				if(tree[1].first==0&&tree[1].second==0)
					cout<<"YES\n";
				else
					cout<<"NO\n";
			}
			else
				update(1,0,n-1,type-1);
		}
		tree.clear();
	}
}
