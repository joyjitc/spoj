#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
typedef long long ll;

vector<vector<ll>> dp;
vector<int> limDigits;

ll sumOfDigitsHelper (int pos, int type, int limit){
	if(dp[pos][type]!=-1) return dp[pos][type];
	if(pos==0){
		if(type==0){
			dp[pos][type] = 45;
			return dp[pos][type];
		}
		else if(type==1){
			dp[pos][type] = (limDigits[0]*(limDigits[0]+1))/2;;
			return dp[pos][type];
		}
	}
	ll ans;
	if(type==0){
		ans = 10 * sumOfDigitsHelper(pos-1,0,limit);
		ans += 45 * pow(10,pos);
	}
	else if(type==1){
		ans = limDigits[pos] * sumOfDigitsHelper(pos-1,0,limit);
		// cout<<ans<<"\n";
		ans += ((limDigits[pos]-1)*limDigits[pos]/2) * pow(10,pos);
		// cout<<ans<<"\n";
		ans += sumOfDigitsHelper(pos-1,1,limit);
		// cout<<ans<<"\n";
		ans += limDigits[pos]*((limit%((int)pow(10,pos)))+1);
		// cout<<ans<<"\n";
		// cout<<limit<<"\n";
		// cout<<((limit%((int)pow(10,pos)))+1)<<"\n";
	}
	dp[pos][type] = ans;
	return dp[pos][type];
}

ll sumOfDigits (int limit){
	if(limit==0) return 0;
	int limitCopy = limit;
	limDigits.clear();
	while(limit){
		limDigits.push_back(limit%10);
		limit/=10;
	}
	int pos = limDigits.size()-1;
	dp.clear();
	dp.resize(pos+1,vector<ll>(2,-1));

	return sumOfDigitsHelper(pos,1,limitCopy);
}

int main(){
	ios::sync_with_stdio(0);
	int a,b;
	while(1){
		cin>>a>>b;
		if(a==-1&&b==-1) break;
		cout<<sumOfDigits(b)-sumOfDigits(a==0?0:a-1)<<"\n";
		// for(int i=dp.size()-1;i>=0;i--) cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";
	}
}