#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
int main(){
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	ull n;
	string x;
	ull dig;
	while(t--){
		cin>>n;
		dig=ceil(log2(n/2.0+1));
		n=(n+1)-pow(2,dig);
		while(dig--){
			if(n&1)
				x.push_back('6');
			else
				x.push_back('5');
			n>>=1;
		}
		reverse(x.begin(),x.end());
		cout<<x<<"\n";
		x.clear();
	}
}



