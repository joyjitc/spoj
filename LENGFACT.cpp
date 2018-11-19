#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	unsigned long long n;
	double ans;
	while(t--){
		cin>>n;
		if(n==0){
			cout<<"1\n";
			continue;
		}
		ans= (n*log10(n/M_E)+log10(2*M_PI*n)/2.0);
		n=ans;
		n++;
		cout<<n<<"\n";
	}
}

