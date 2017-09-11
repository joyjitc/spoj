#include <bits/stdc++.h>

using namespace std;

int block;
bool comp(pair<int,int>& x, pair<int,int>& y){
	if(x.first/block!=y.first/block)
		return x.first/block<y.first/block;
	return x.second<y.second;
}
struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};
vector<int> a,cx;

int answer=0;
void remove(int pos){
	cx[a[pos]]--;
	if(cx[a[pos]]==0) answer--;
}
void add(int pos){
	cx[a[pos]]++;
	if(cx[a[pos]]==1) answer++;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	cin>>n;
	
	a.reserve(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int q;
	cin>>q;
	vector<pair<int,int> > q1,q2;
	int L,R;
	for(int i=0;i<q;i++){
		cin>>L>>R;
		q1.push_back(pair<int,int>(L,R));
		q2.push_back(pair<int,int>(L,R));
	}
	unordered_map<pair<int,int>,int,pair_hash> ans;
	cx.resize(1000001,0);
	
	block = sqrt(n);
	sort(q2.begin(),q2.end(),comp);
	int cL=1,cR=0;
	for(auto x:q2){
		L = x.first, R = x.second;
		while(cR<R){
			cR++;
			add(cR);
		}
		while(cL>L){
			cL--;
			add(cL);
		}
		while(cL<L){
			remove(cL);
			cL++;
		}
		while(cR>R){
			remove(cR);
			cR--;
		}
		ans[x] = answer;
	}
	for(auto x:q1)
		cout<<ans[x]<<"\n";
}