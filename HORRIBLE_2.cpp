#include<bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll> b1,b2;
ll N;
void update(vector<ll>& bit,ll idx,ll val){
	while(idx<=N){
		bit[idx]+=val;
		idx+=idx&-idx;
	}
}
ll query(vector<ll>& bit, ll idx){
	ll val=0;
	while(idx>0){
		val+=bit[idx];
		idx-=idx&-idx;
	}
	return val;
}
ll query(vector<ll>& b1,vector<ll>& b2,ll x){
	return query(b1,x)*x-query(b2,x);
}
ll query(vector<ll>& b1, vector<ll>& b2,ll l, ll r){
	return query(b1,b2,r)-query(b1,b2,l-1);
}
ll update(vector<ll>& b1, vector<ll>& b2, ll l, ll r,ll val){
	update(b1,l,val);
	update(b1,r+1,-1*val);
	update(b2,l,(l-1)*val);
	update(b2,r+1,-1*r*val);
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	ll t;cin>>t;
	ll c,type,p,q,v;
	while(t--){
		cin>>N>>c;
		b1.resize(N+1,0);
		b2.resize(N+1,0);
		while(c--){
			cin>>type;
			if(type==0){
				cin>>p>>q>>v;
				update(b1,b2,p,q,v);
			}
			else{
				cin>>p>>q;
				cout<<query(b1,b2,p,q)<<"\n";
			}
		}
		b1.clear();b2.clear();
	}
}

