#include<bits/stdc++.h>
typedef unsigned long long ull;
#define MOD 10000007
using namespace std;
ull modMul(ull a, ull b){
	return((a%MOD)*(b%MOD))%MOD;
}
ull fastExp(ull val,int exp){
	if(exp==0)
		return 1;
	if(exp==1)
		return val%MOD;
	if(!(exp&1))
		return modMul(fastExp(val,exp>>1),fastExp(val,exp>>1))%MOD;
	else
		return modMul(fastExp(val,exp-1),val)%MOD;
}
int main(){
	ios::sync_with_stdio(0);
	ull n,k,ans;
	while(1){
		cin>>n>>k;
		if(n==0&&k==0)
			break;
		ans=((2*fastExp(n-1,k))%MOD+fastExp(n,k)+(2*fastExp(n-1,n-1))%MOD+fastExp(n,n))%MOD;
		cout<<ans<<"\n";
	}

}
