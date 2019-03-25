#include<iostream>
#include<vector>
#include<climits>
int t,o,n,c;

using namespace std;
vector<vector<int> > cylinder;
vector<vector<vector<int> > > dp;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>o>>n;
		cin>>c;
		cylinder.clear();
		cylinder.resize(c+1,vector<int>(3));
		dp.clear();
		dp.resize(c+1,vector<vector<int> >(o+1,vector<int>(n+1,0)));
		for(int i=1;i<=c;i++){
			cin>>cylinder[i][0]>>cylinder[i][1]>>cylinder[i][2];
		}

		for(int j=0;j<=o;j++)
			for(int k=0;k<=n;k++)
				dp[0][j][k] = INT_MAX;

		dp[0][0][0] = 0;

		for(int i=1;i<=c;i++)
			for(int j=0;j<=o;j++)
				for(int k=0;k<=n;k++){
					if(dp[i-1][(j-cylinder[i][0]<0)?0:j-cylinder[i][0]][(k-cylinder[i][1]<0)?0:k-cylinder[i][1]]==INT_MAX)
					dp[i][j][k] = dp[i-1][j][k];
				else
					dp[i][j][k] = min(dp[i-1][j][k],
						cylinder[i][2]+dp[i-1][(j-cylinder[i][0]<0)?0:j-cylinder[i][0]][(k-cylinder[i][1]<0)?0:k-cylinder[i][1]]);
				}
	
		cout<<dp[c][o][n]<<"\n";
	}
}