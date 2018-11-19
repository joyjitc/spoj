#include<bits/stdc++.h>
using namespace std;
vector<int> dp;
int main(){
	ios::sync_with_stdio(0);
	dp.resize(1001);
	dp[1]=5;
	for(int i=2;i<=1000;i++)
		dp[i]=dp[i-1]+(i-1)*3+4;
	int n;
	while(1){
		cin>>n;
		if(n==0)
			break;
		cout<<dp[n]<<"\n";
	}
}

