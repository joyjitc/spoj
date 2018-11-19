#include<bits/stdc++.h>
using namespace std;
int compare(int a,int b){
	if(a==-1) return b;
	if(b==-1) return a;
	if(a<b) return a;
	else return b;
}
int combine(int a,int b){
	if(a==-1||b==-1) return -1;
	else return a+b;
}
int main(){
	ios::sync_with_stdio(0);
	int t;cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<int> v;
		v.push_back(0);
		for(int i=1;i<=k;i++){
			v.push_back(0);
			cin>>v[i];
		}
		vector<vector<int>> dp;
		dp.resize(k+1,vector<int>(n+1,-1));
		for(int j=0;j<=n;j++) dp[0][j]=0;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				for(int x=1;x<=i;x++){
					// cout<<"i = "<<i<<" j = "<<j<<" x = "<<x<<endl;
					dp[i][j]=compare(dp[i][j],combine(v[x],dp[i-x][j-1]));
				}
			}
			// for(int j=i+1;j<=n;j++)
			// 	dp[i][j]=dp[i][i];
		}

		cout<<dp[k][n]<<"\n";
	}
}