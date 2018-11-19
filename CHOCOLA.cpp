#include<bits/stdc++.h>
using namespace std;
vector<int> mv,nv;
vector<vector<int> > dp;
int cal(int i,int j){
	if(dp[i][j]!=-1)
		return dp[i][j];
	if(i==mv.size()&&j==nv.size())
		return 0;
	if(i==mv.size()){
		dp[i][j]=nv[j]*(i+1)+cal(i,j+1);
		return dp[i][j];
	}
	if(j==nv.size()){
		dp[i][j]=mv[i]*(j+1)+cal(i+1,j);
		return dp[i][j];
	}
	dp[i][j]=min(mv[i]*(j+1)+cal(i+1,j),nv[j]*(i+1)+cal(i,j+1));
	return dp[i][j];
}
int main(){
	ios::sync_with_stdio(0);
	int t;cin>>t;
	int temp;
	int m,n;
	while(t--){
		cin>>m>>n;
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
		dp.resize(m,vector<int>(n,-1));
		cout<<cal(0,0)<<"\n";
		dp.clear();
		mv.clear();nv.clear();
//		int mcut=1,ncut=1;
//		int mi=0,ni=0;
//		int ans=0;
//		while(mi<m-1&&ni<n-1){
//			if(mv[mi]*mcut>nv[ni]*ncut){
//				ans+=mv[mi]*mcut;
//				mi++;ncut++;
//			}
//			else if(mv[mi]*mcut<nv[ni]*ncut){
//				ans+=nv[ni]*ncut;
//				ni++;mcut++;
//			}
//			else if(mv[mi]*mcut==nv[ni]*ncut){
//				if(mv[mi]>nv[ni]){
//					ans+=mv[mi]*mcut;
//					mi++;ncut++;
//				}
//				else if(nv[ni]>mv[mi]){
//					ans+=nv[ni]*ncut;
//					ni++;mcut++;
//				}
//				else if(nv[ni]==mv[mi]){
//					if(n>m){
//						ans+=mv[mi]*mcut;
//						mi++;ncut++;
//					}
//					else{
//						ans+=nv[ni]*ncut;
//						ni++;mcut++;
//					}
//				}
//			}
//		}
//		if(mi==m-1)
//			while(ni<n-1){
//				ans+=nv[ni]*ncut;
//				ni++;
//			}
//		else
//			while(mi<m-1){
//				ans+=mv[mi]*mcut;
//				mi++;
//			}
//		cout<<ans<<"\n";
	}
}




