#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	unsigned long long N,K,T,F;
	while(t--){
		cin>>N>>K>>T>>F;
		cout<<(((F-N)/(K-1))*K)+N<<"\n";
	}
}
