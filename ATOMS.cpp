#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	long double N,n,k,m,ans;
	while(t--){
		cin>>N>>k>>m;
		ans = 0;
		n=N;
		if(n>=m){
			cout<<"0\n";
			continue;
		}
		while(1){
			n*=k;
			if(n<=m&&n>0&&n>=N)
				ans++;
			else break;
		}
		cout<<ans<<"\n";
	}
}



