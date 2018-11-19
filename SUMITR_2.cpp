//Too Long
//Formatted
//Memoized - DP
#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > a, dp;
int cal(int i, int j){
	if(i<1||j<1||j>i)
		return INT_MIN;
	if(i==1&&j==1)
		return a[1][1];
	if(dp[i][j]!=-1)
		return dp[i][j];
	dp[i][j]=a[i][j]+max(cal(i-1,j),cal(i-1,j-1));
	return dp[i][j];
}
int main(){
	ios::sync_with_stdio(0);
	int t,n,ans;
	cin>>t;
	while(t--){
		cin>>n;
		a.resize(n+1,vector<int>(n+1));
		dp.resize(n+1,vector<int>(n+1,-1));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				cin>>a[i][j];
			}
		}
		ans=0;
		for(int j=1;j<=n;j++){
			ans=max(ans,cal(n,j));
		}
		cout<<ans<<"\n";
		a.clear();dp.clear();
	}
}
