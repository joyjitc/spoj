#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
pii def = pii(-1,-1);
vector<int> v;
vector<vector<pii> > dp;
pii cal(bool state,int i,int j){
	if(i==j)
		return pii(0,v[i]);
	if(dp[i][j]!=def)
		return dp[i][j];
	if(state==1){
		if(v[j]>v[i]){
			pii res=cal(0,i,j-1);
			res.second+=v[j];
			dp[i][j]=res;
		}
		else{
			pii res=cal(0,i+1,j);
			res.second+=v[i];
			dp[i][j]=res;
		}
		return dp[i][j];
	}
	else if(state==0){
		pii left = cal(1,i+1,j);
		left.first+=v[i];
		pii right = cal(1,i,j-1);
		right.first+=v[j];
		if(left.first-left.second>=right.first-right.second)
			dp[i][j]=left;
		else
			dp[i][j]=right;
		return dp[i][j];
	}
}
int main(){
	ios::sync_with_stdio(0);
	int n;
	int t=1;
	while(1){
		cin>>n;
		if(n==0)
			break;

		int temp;
		for(int i=0;i<n;i++){
			cin>>temp;
			v.push_back(temp);
		}
		dp.resize(n,vector<pii>(n,def));
		pii ans = cal(0,0,n-1);
		cout<<"In game "<<t<<", the greedy strategy might lose by as many as "<<ans.first-ans.second<<"  points.\n";
		dp.clear();
		v.clear();
		t++;
	}
}
