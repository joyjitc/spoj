#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);

	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		if(n&1) cout<<n/2+1<<"\n";
		else cout<<n/2<<"\n";
	}
}