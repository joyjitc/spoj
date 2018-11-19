#include<bits/stdc++.h>
using namespace std;
bool ans(unsigned long long x){
	//0-Male : 1-Female
	if(x==1)
		return 0;
	if(x==2)
		return 1;
	double log_val = log2(x);
	if(log_val-floor(log_val)==0)
		log_val=log_val-1;
	else
		log_val = floor(log_val);
	int log_int = log_val;
	return (ans(x-pow(2,log_int))+1)%2;
}
int main(){
	ios::sync_with_stdio(0);
	int t;
	unsigned long long n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		if(ans(k)==0) cout<<"Male\n";
		else cout<<"Female\n";
	}

}