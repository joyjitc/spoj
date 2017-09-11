#include <bits/stdc++.h>
using namespace std;

// int gcd(int a, int b){
// 	if(b==0) return a;
// 	else return gcd(b,a%b);
// }

int main(){
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	int A,B;
	int x;
	while(t--){
		cin>>A>>B;
		// cout<<A<<" "<<B;
		x = __gcd(A,B);
		// cout<<x<<endl;
		A=A/x;B=B/x;
		// while(1){
		// 	gcd==__gcd(A,B);
		// 	if(gcd==1) break;
		// 	A/=gcd;
		// 	B/=gcd;
		// }
		cout<<B<<" "<<A<<"\n";
	}
}