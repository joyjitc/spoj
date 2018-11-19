#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	// freopen ("myfile.txt","w",stdout);
	int t;cin>>t;
	while(t--){
		int k,m;
		cin>>k>>m;
		vector<pair<int,int>> item;
		item.push_back(pair<int,int>(0,0));
		int a,b;
		for(int i=0;i<m;i++){
			cin>>a>>b;
			item.push_back(pair<int,int>(a,b));
		}
		vector<vector<int>> dp;
		dp.resize(m+1,vector<int>(k+1,0));
		for(int i=1;i<=m;i++)
			for(int j=1;j<=k;j++){
				if(j<item[i].first)
					dp[i][j]=dp[i-1][j];
				else
					dp[i][j]=max(dp[i-1][j],dp[i-1][j-item[i].first]+item[i].second);
			}

		cout<<"Hey stupid robber, you can get "<<dp[m][k]<<".\n";
		// //debug

		// for(int i=0;i<=m;i++){
		// 	for(int j=0;j<=k;j++)
		// 		cout<<dp[i][j]<<" ";
		// 	cout<<"\n";
		// }
	}
}