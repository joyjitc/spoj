#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int n;
	unordered_set<int> fof,f;
	cin>>n;
	int cur_f,cur_fof;
	int n_of_fof;
	while(n--){
		cin>>cur_f;
		f.insert(cur_f);
		cin>>n_of_fof;
		while(n_of_fof--){
			cin>>cur_fof;
			fof.insert(cur_fof);
		}
	}
	for(auto x:f) fof.erase(x);
	cout<<fof.size()<<"\n";
}