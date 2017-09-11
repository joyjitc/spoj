#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > dp,k;
int N,M;
int miser(int n, int m){
	if(m>M||m<1)
		return INT_MAX;
	if(n==1)
		return k[n][m];
	if(dp[n][m]!=-1)
		return dp[n][m];
	dp[n][m] = k[n][m]+min(miser(n-1,m),min(miser(n-1,m-1),miser(n-1,m+1)));
	return dp[n][m];
}

int main(){
	ios::sync_with_stdio(0);
	cin>>N>>M;
	dp.resize(N+1,vector<int>(M+1,-1));
	k.resize(N+1,vector<int>(M+1,-1));
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			cin>>k[i][j];

	int ans = INT_MAX;

	for(int j=1;j<=M;j++)
			ans = min(ans,miser(N,j));
	cout<<ans<<"\n";

}