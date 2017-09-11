#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	int a,b;
	int x;
	int i;
	int count;
	while(t--){
		cin>>a>>b;
		x=__gcd(a,b);
		count=0;
		for(i=1;i<=x;i++) if(a%i==0&&b%i==0) count++;
		cout<<count<<"\n";
	}
}