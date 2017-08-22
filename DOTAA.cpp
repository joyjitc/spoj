#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t,n,m,D;
	vector<int> health;
	health.reserve(500);
	cin>>t;
	int h;
	while(t--){
		cin>>n>>m>>D;
		for(int i=0;i<n;i++){
			cin>>h;
			health.push_back(h);
		}
		sort(health.begin(),health.end(),greater<int>());
		int i=0,j=0;
		while(i<m&&j<n){
			if(health[j]>D){
				health[j]-=D;
				i++;
			}
			else
				j++;
			
		}
		if(i<m) cout<<"NO\n";
		else cout<<"YES\n";

		health.clear();
	}
}