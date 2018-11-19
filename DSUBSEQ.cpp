#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int cal(string& inp){
	int sz=inp.size();
	vector<int> dp(sz+1);
	dp[0]=1;
	vector<int> prev(26,-1);
	for(int i=0;i<sz;i++){
		dp[i+1]=(2*dp[i])%MOD;
		if(prev[inp[i]-'A']>-1)
			dp[i+1]=(dp[i+1]-dp[prev[inp[i]-'A']]+MOD)%MOD;
		prev[inp[i]-'A']=i;
	}
	return dp[sz];
}

int main(){
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	string inp;
	while(t--){
		cin>>inp;
		cout<<cal(inp)<<"\n";
	}
}

