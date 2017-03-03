#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	int n,k;
	vector<int> hgt;
	hgt.reserve(20000);
	int min_dif, dif;
	while(t--){
		cin>>n>>k;
		for(int i=0;i<n;i++)
			cin>>hgt[i];
		if(k==1){
			cout<<"0"<<"\n";
			continue;
		}
		auto endit = hgt.begin();
		advance(endit,n);
		sort(hgt.begin(),endit);
		// for(int i=0;i<n;i++)
		// 	cout<<hgt[i]<<" ";
		min_dif = INT_MAX;
		for(int i=0;i<=n-k;i++){
			dif = hgt[i+k-1] - hgt[i];
			if(dif<min_dif)
				min_dif = dif;
		}
		cout<<min_dif<<"\n";
	}

}
