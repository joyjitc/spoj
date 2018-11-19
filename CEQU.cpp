#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int t;cin>>t;
	int a,b,c;
	int index =1;
	int x;
	while(t--){
		cin>>a>>b>>c;
		cout<<"Case "<<index++<<": ";
		x = __gcd(a,b);
		if(__gcd(x,c)==x)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}