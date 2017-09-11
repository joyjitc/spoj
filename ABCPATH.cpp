#include <bits/stdc++.h>

using namespace std;

int h,w;
vector<vector<char> > a;
vector<vector<int> > dp;

int calPath(int i, int j, char x){
	if(i<0||i>=h||j<0||j>=w)
		return INT_MIN;
	if(a[i][j]!=x)
		return INT_MIN;
	if(dp[i][j]!=-1)
		return dp[i][j];
	
	if(x=='Z')
		return 1;
	int max_path = 0;
	max_path = max(max_path,calPath(i+1,j,x+1));
	max_path = max(max_path,calPath(i+1,j+1,x+1));
	max_path = max(max_path,calPath(i+1,j-1,x+1));
	max_path = max(max_path,calPath(i-1,j,x+1));
	max_path = max(max_path,calPath(i-1,j+1,x+1));
	max_path = max(max_path,calPath(i-1,j-1,x+1));
	max_path = max(max_path,calPath(i,j+1,x+1));
	max_path = max(max_path,calPath(i,j-1,x+1));
	dp[i][j] = max_path+1;
	return dp[i][j];
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int ans, cas = 1;
	vector<pair<int,int> > index;
	while(1){
		ans = 0;
		cin>>h>>w;
		if(h==0&&w==0)
			break;
		a.resize(h,vector<char>(w));
		dp.resize(h,vector<int>(w,-1));
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				cin>>a[i][j];
				if(a[i][j]=='A')
					index.push_back(pair<int,int>(i,j));
			}
		}
		for(auto x:index){
			ans = max(ans,calPath(x.first,x.second,'A'));
			if(ans==26) break;
		}
		cout<<"Case "<<cas<<": "<<ans<<"\n";
		cas++;
		index.clear();
		a.clear();
		dp.clear();
	}
}