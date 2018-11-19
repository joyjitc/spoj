#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	unsigned long long N,n,k,m,ans;
	while(t--){
		cin>>n>>k>>m;
	//	scanf("%llu%llu%llu",&n,&k,&m);
		ans = 0;
		if(n>=m){
			cout<<"0\n";
			continue;
		}
		while(1){
			N=n*k;
			if(N<=m&&N/k==n){
				ans++;
				n=N;
			}
			else break;
		}
		cout<<ans<<"\n";
	//	printf("%llu\n",ans);
	}
}
