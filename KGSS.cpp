#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using pull=pair<ull,ull>;
vector<pull> t;
vector<ull> a;
pull combine(pull l, pull r){
	pull res;
	if(l.first>r.first){
		res.first = l.first;
		res.second = max(l.second,r.first);
	}
	else{
		res.first=r.first;
		res.second = max(r.second,l.first);
	}
	return res;
}
void build(int v, int tl, int tr){
	if(tl==tr)
		t[v] = pull(a[tl],0);
	else{
		int tm = tl+(tr-tl)/2;
		build(v*2,tl,tm);
		build(v*2+1,tm+1,tr);
		t[v] = combine(t[v*2],t[v*2+1]);
	}
}
void update(int v,int tl,int tr, int pos, ull val){
	if(tl==tr)
		t[v] = pull(val,0);
	else{
		int tm = tl+(tr-tl)/2;
		if(pos<=tm)
			update(v*2,tl,tm,pos,val);
		else
			update(v*2+1,tm+1,tr,pos,val);
		t[v]=combine(t[v*2],t[v*2+1]);
	}
}
pull get(int v,int tl,int tr, ull l,ull r){
	if(l>r)
		return pull(0,0);
	if(l==tl&&r==tr)
		return t[v];
	ull tm = tl+(tr-tl)/2;
	return combine(get(v*2,tl,tm,l,min(r,tm)),get(v*2+1,tm+1,tr,max(tm+1,l),r));
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	cin>>n;
	t.resize(n*4);
	a.reserve(n);
	ull temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		a.push_back(temp);
	}
	int Q;
	cin>>Q;
	char type;
	ull x,y;
	build(1,0,n-1);
	while(Q--){
		cin>>type>>x>>y;
		if(type=='Q'){
			pull result = get(1,0,n-1,x-1,y-1);
			cout<<result.first+result.second<<"\n";
		}
		else if(type=='U')
			update(1,0,n-1,x-1,y);
	}

		
}
