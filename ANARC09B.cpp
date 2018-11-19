#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	unsigned long long a,b,g;
	while(1){
		cin>>a>>b;
		if(a==0&&b==0)
				break;
		g = __gcd(a,b);
		a/=g;b/=g;
		cout<<a*b<<"\n";
	}
}


