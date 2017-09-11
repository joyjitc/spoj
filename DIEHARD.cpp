#include <bits/stdc++.h>
using namespace std;
vector<vector<vector<int> > > dp;
//Solution using dp
// int dp[1001][1001][3] = {-1};

int dieHard(int h, int a, int x){
	// cout<<h<<" "<<a<<" "<<x<<"\n";
	if(dp[h][a][x]!=-1){
		// cout<<"You're Fucked!\n";
		return dp[h][a][x];
	}
	// cout<<"Here!\n";
	int H=h,A=a;
	if(x==0){
		h+=3,a+=2;
		// cout<<h<<" "<<a<<" "<<x<<"\n";
	}
	else if(x==1){
		h-=5,a-=10;
		// cout<<h<<" "<<a<<" "<<x<<"\n";
	}
	else{
		h-=20,a+=5;
		// cout<<h<<" "<<a<<" "<<x<<"\n";
	}

	if(h<=0||a<=0)
		dp[H][A][x]=0;
	else
		dp[H][A][x]=1+max(dieHard(h,a,(x+1)%3),dieHard(h,a,(x+2)%3));

	return dp[H][A][x];
}

int main(){
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	int ans;
	int h,a;
	dp.resize(1500,vector<vector<int> >(1500,vector<int>(3,-1)));
	while(t--){
		cin>>h>>a;
		ans = max(max(dieHard(h,a,0),dieHard(h,a,1)),dieHard(h,a,2));
		cout<<ans<<"\n";
	}
	
}