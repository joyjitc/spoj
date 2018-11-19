#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int n;
	cin>>n;
	vector<vector<int>> rec,dp;
	rec.resize(n,vector<int>(2));
	dp.resize(n,vector<int>(2));
	for(int i=0;i<n;i++){
		cin>>rec[i][0]>>rec[i][1];
	}
	dp[0][0]=rec[0][0];
	dp[0][1]=rec[0][1];
	// int max_side;
	for(int i=1;i<n;i++){
		// if(dp[i-1][0]>dp[i-1][1])
		// 	max_side = 0;
		// else
		// 	max_side = 1;
		dp[i][0] = rec[i][0] + max(dp[i-1][0]+abs(rec[i][1]-rec[i-1][1]),dp[i-1][1]+abs(rec[i][1]-rec[i-1][0]));
		dp[i][1] = rec[i][1] + max(dp[i-1][0]+abs(rec[i][0]-rec[i-1][1]),dp[i-1][1]+abs(rec[i][0]-rec[i-1][0]));				
	}
	// for(int i=0;i<n;i++){
	// 	cout<<rec[i][0]<<" "<<rec[i][1]<<"\n";
	// }
	// for(int i=0;i<n;i++){
	// 	cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";
	// }
	int ans = max(dp[n-1][0],dp[n-1][1]);
	cout<<ans<<"\n";
}