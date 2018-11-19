#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	vector<int> sieve(3001,-1);
	for(int i=2;i<=1500;i++){
		if(sieve[i]==-1)
			for(int j=2;i*j<=3000;j++)
				sieve[i*j]=0;
	}
	for(int i=2;i<=1500;i++){
		if(sieve[i]==-1)
			for(int j=2;i*j<=3000;j++)
				sieve[i*j]++;
	}
	vector<int> a;
	for(int i=2;i<=3000;i++)
		if(sieve[i]>=3)
			a.push_back(i);
	int t;
	cin>>t;
	int n;
	while(t--){
		cin>>n;
		cout<<a[n-1]<<"\n";
	}

}
