#include<iostream>
#include<vector>

using namespace std;



unsigned powerOfTwo (int exp){
	unsigned num = 1;
	while(exp--){
		num = num<<1;
	}
	return num;
}

int count_one (unsigned mask){
	int ones = 0;
	while(mask){
		if((mask&1)==1)
			ones++;
		mask = mask>>1;
	}
	return ones;
}

int main(){
	ios::sync_with_stdio(0);
	int t,n;
	long long ans;
	cin>>t;
	while(t--){
		cin>>n;
		vector<vector<int> > pref;
		pref.resize(n,vector<int>(n,0));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>pref[i][j];
			}
		}

		unsigned num = powerOfTwo(n);

		int x;
		vector<long long> dp(num,0);
		dp[0] = 1;
		for(unsigned mask=0;mask<num;mask++){
			x = count_one(mask);
			// cout<<"mask is :"<<mask<<" count_one is :"<<x<<"\n";
			for(int j=0;j<n;j++){
				if(((mask&(1<<j))==0)&&pref[x][j]==1){
					dp[mask|(1<<j)] += dp[mask];
				}
			}
		}
		// for(int i=0;i<num;i++){
		// 	cout<<"dp["<<i<<"] = "<<dp[i]<<" ";
		// }
		ans = dp[num-1];
		cout<<ans<<"\n";
	}
}