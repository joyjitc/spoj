#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > dp;
vector<vector<int> > trigraph;
int sp(int row,int col){
	if(dp[row][col]!=INT_MIN) return dp[row][col];
	if(row==0){
		if(col==0){
			dp[row][col] = INT_MAX;
			return dp[row][col];
		}
		if(col==1){
			dp[row][col] = trigraph[row][col];
			return dp[row][col];
		}
		if(col==2){
			dp[row][col] = trigraph[row][col] + trigraph[row][col-1];
			return dp[row][col];
		}
	}
	if(col==0){
		dp[row][col] = trigraph[row][col] + min(sp(row-1,col),sp(row-1,col+1));
		return dp[row][col];
	}
	if(col==1){
		dp[row][col] = trigraph[row][col] + min(min(sp(row-1,col),sp(row-1,col+1)),min(sp(row-1,col-1),sp(row,col-1)));
		return dp[row][col];
	}
	if(col==2){
		dp[row][col] = trigraph[row][col] + min(sp(row-1,col),min(sp(row-1,col-1),sp(row,col-1)));
		return dp[row][col];
	}
}

int main(){
	ios::sync_with_stdio(0);
	int n;
	int index = 1;
	while(1){
		cin>>n;
		if(n==0) break;
		trigraph.resize(n,vector<int>(3));
		for(int i=0;i<n;i++)
			cin>>trigraph[i][0]>>trigraph[i][1]>>trigraph[i][2];
		dp.resize(n,vector<int>(3,INT_MIN));
		cout<<index<<". "<<sp(n-1,1)<<"\n";
		trigraph.clear();
		dp.clear();
		index++;
	}
}