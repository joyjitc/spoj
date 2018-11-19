#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > dp;
int lcs_h(vector<int>& a, vector<int>& b, int i, int j){
	if(i<0||j<0)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	if(a[i]==b[j])
		dp[i][j]=1+lcs_h(a,b,i-1,j-1);
	else
		dp[i][j] = max(lcs_h(a,b,i-1,j),lcs_h(a,b,i,j-1));
	return dp[i][j];
}
int lcs(vector<int>& a, vector<int>& b){
	int x= a.size()-1,y=b.size()-1;
	dp.resize(x+1,vector<int>(y+1,-1));
	int ans=lcs_h(a,b,x,y);
	dp.clear();
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	vector<vector<int> > route;
	int c;
	int max_val;
	while(t--){
		while(1){
			cin>>c;
			if(c==0)
				break;
			vector<int> temp;
			temp.push_back(c);
			while(1){
				cin>>c;
				if(c==0)
					break;
				temp.push_back(c);
			}
			route.push_back(temp);
		}
		max_val=0;
		for(int i=1;i<route.size();i++){
			max_val = max(max_val,lcs(route[0],route[i]));
		}
		cout<<max_val<<"\n";
		route.clear();
	}
}
