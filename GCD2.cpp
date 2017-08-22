#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

int main(){
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	int a;
	string b;
	int rem;
	int i;
	while(t--){
		cin>>a>>b;
		if(a==0){
			cout<<b<<"\n";
			continue;
		}
		if(b.size()==1&&b[0]=='0'){
			cout<<a<<"\n";
			continue;
		}
		rem = 0, i = 0;
		while(i<b.size()){
			if(rem<a){ 
				rem = rem*10 + (b[i]-'0');
				i++;
			}
			else rem = rem%a;
			
		}
		cout<<gcd(max(rem,a),min(rem,a))<<"\n";
	}

}