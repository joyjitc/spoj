#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	long long n,n_i;
	double a;
	bool flag;
	while(t--){
		flag = false;
		cin>>n;
		for(long long i = 0;i*i<n;i++){
			n_i = n-i*i;
			a = sqrt(n_i);
			if(floor(a)==a){
				flag = 1;
				break;
			}
		}
		if(flag) cout<<"Yes\n";
		else cout<<"No\n";
	}
}