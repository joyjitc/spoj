#include<iostream>
#include<unordered_set>
#include<algorithm>
#include<vector>
using namespace std;

vector<edge> v;
vector<int> set;

struct edge
{
	int a,b,w;
	edge(int _a, int _b, int _w){
		a = _a;
		b = _b;
		w = _w;
	}
};
bool comp(edge& l, edge& r){
	return l.w<r.w;
}


int find(int n){
	if(set[n]==n)
		return n;
	else
		return find(set[n]);
}
void merge(int a, int b){
	int pa = find(a);
	int pb = find(b);
	set[pa] = pb;
}


int main(){
	ios::sync_with_stdio(0);

	int t,n,p,neigh,cost,ans;
	string city;

	cin>>t;

	while(t--){
		cin>>n;

		set.clear();
		set.resize(n+1);
		for(int i=0;i<=n+1;i++)
			set[i] = i;

		v.clear();
		for(int i=1;i<=n;i++){
			cin>>city;
			cin>>p;
			while(p--){
				cin>>neigh>>cost;
				v.push_back(edge(i,neigh,cost));
			}
		}
		sort(v.begin(),v.end(),comp);

		ans = 0;
		int i = 0;
		while(i<v.size()){
			if(find(v[i].a)==find(v[i].b)){
				i++;
				continue;
			}
			else{
				merge(v[i].a,v[i].b);
				ans+=v[i].w;
				i++;
			}
		}

		cout<<ans<<"\n";
	}
}