#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int t;cin>>t;
	int temp;
	int m,n;
	while(t--){
		cin>>m>>n;
		vector<int> mv,nv;
		for(int i=0;i<m-1;i++){
			cin>>temp;
			mv.push_back(temp);
		}
		for(int i=0;i<n-1;i++){
			cin>>temp;
			nv.push_back(temp);
		}
		sort(mv.begin(),mv.end(),greater<int>());
		sort(nv.begin(),nv.end(),greater<int>());
		int mcut=1,ncut=1;
		int mi=0,ni=0;
		int ans=0;
		while(mi<m-1&&ni<n-1){
			if(mv[mi]>nv[ni]){
				ans+=mv[mi]*mcut;
				mi++;ncut++;
			}
			else{
				ans+=nv[ni]*ncut;
				ni++;mcut++;
			}
		}
		if(mi==m-1)
			while(ni<n-1){
				ans+=nv[ni]*ncut;
				ni++;
			}
		else
			while(mi<m-1){
				ans+=mv[mi]*mcut;
				mi++;
			}
		cout<<ans<<"\n";
	}
}




