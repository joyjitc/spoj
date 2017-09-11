#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	int n, val;
	vector<int> a;

	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>val;
			a.push_back(val);
		}
		int maj_el= a[0],count=1;
		for(int i=1;i<a.size();i++){
			if(a[i]==maj_el) count++;
			else count--;
			if(count==0){
				maj_el = a[i];
				count=1;
			}
		}
		count = 0;
		for(auto x:a) if(x==maj_el) count++;
		if(count>n/2) cout<<"YES "<<maj_el<<"\n";
		else cout<<"NO\n";
		a.clear();
	}
}