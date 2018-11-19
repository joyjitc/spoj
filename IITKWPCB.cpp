#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	unsigned long long n;
	while(t--){
		cin>>n;
		if(n==2||n==1)
			cout<<"1\n";
		else if(n&1)
			cout<<(n>>1)<<"\n";
		else{
			n=n>>1;
			if(n&1)
				cout<<n-2<<"\n";
			else
				cout<<n-1<<"\n";
		}
	}

}
