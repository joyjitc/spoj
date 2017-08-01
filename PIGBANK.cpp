#include <bits/stdc++.h>

using namespace std;

// int dp[501][10001];
// int val_wt[501][2];


int min_val(int a, int b){
	//
	// printf("a = %d b = %d\n",a,b);
	if(a<0&&b<0) return INT_MIN;
	if(a<0) return b;
	else if(b<0) return a;
	if(a<b) return a;
	else return b;
}
bool compare (pair<int,int>& a, pair<int,int>& b){
	return a.second<b.second;
}

int main(){
	int t, E, F, N, total_wt;
	int val,wt;
	vector<pair<int,int> > val_wt;
	vector<int> dp;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&E,&F);
		total_wt = F-E;
		scanf("%d", &N);
		val_wt.reserve(N);

		for(int i=1;i<=N;i++){
			scanf("%d %d",&val, &wt);
			val_wt.push_back(pair<int,int>(val,wt));
		}
		dp.resize(total_wt+1,INT_MIN);
		dp[0] = 0;
		sort(val_wt.begin(),val_wt.end(),compare);
		// for(auto j:val_wt) printf("val = %d wt = %d\n",j.first,j.second);
		for(int i=1;i<=total_wt;i++){
			for(auto j:val_wt){
				// printf("i = %d val = %d wt = %d\n",i,j.first,j.second);
				if(i<j.second) break;
				else dp[i] = min_val(j.first+dp[i-j.second],dp[i]);
				// printf("dp[%d] = %d\n",i,dp[i]);
			}
		}
		if(dp[total_wt]<0) printf("This is impossible.\n");
		else printf("The minimum amount of money in the piggy-bank is %d.\n",dp[total_wt]);
		// for(auto x:dp) printf("%d ",x);
		dp.clear();
		val_wt.clear();
	}
}