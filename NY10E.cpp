#include<bits/stdc++.h>
using namespace std;
unsigned long long dp[65][11];
int main(){
	ios::sync_with_stdio(0);
	int t,a,n;
	cin>>t;
	for(int j=1;j<=10;j++)
		dp[0][j]=1;
	for(int i=1;i<=64;i++)
		for(int j=1;j<=10;j++)
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
	while(t--){
		cin>>a>>n;
		cout<<a<<" "<<dp[n][10]<<"\n";
	}
}
