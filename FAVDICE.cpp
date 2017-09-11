#include <bits/stdc++.h>
using namespace std;

double favdice(int n){
	double ans=0;
	for(double i=1;i<=n;i++)
		ans+=(1.0/i);
	ans*=n;
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	int t,n;
	double ans;
	cin>>t;
	cout<<fixed;
	cout.precision(2);
	while(t--){
		cin>>n;
		ans = favdice(n);
		cout<<ans<<"\n";
	}
}


