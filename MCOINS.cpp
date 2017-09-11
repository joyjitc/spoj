#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int k,l,m;
	// vector<int> n;
	vector<int> dp(1000100,-1);
	cin>>k>>l>>m;
	dp[k]=dp[l]=dp[1]=1;
	for(int i=1;i<=1000000;i++){
		if(dp[i]==0)
			dp[i+1]=dp[i+k]=dp[i+l]=1;
		else if(dp[i]==1){
			if(dp[i+1]==-1) dp[i+1]=0;
			if(dp[i+k]==-1) dp[i+k]=0;
			if(dp[i+l]==-1) dp[i+l]=0;
		}
	}
	int temp;
	for(int i=0;i<m;i++){
		cin>>temp;
		if(dp[temp]==1) cout<<"A";
		else if(dp[temp]==0) cout<<"B";
	}
	cout<<"\n";
}