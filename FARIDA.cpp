#include <bits/stdc++.h>
using namespace std;

vector<long long> input;
vector<long long> memo;

long long farida(int n){
	if(memo[n]!=-1)
		return memo[n];
	else if(n==1){
		memo[n]=input[n];
		return memo[n];
	}
	else if(n==2){
		memo[n]=max(input[n],input[n-1]);
		return memo[n];
	}
	else{
		memo[n]=max(farida(n-1),input[n]+farida(n-2));
		return memo[n];
	}
}

int main(){
	ios::sync_with_stdio(false);
	// freopen("input.txt","r",stdin);
	int C;
	cin>>C;
	int N;
	long long ans;
	input.reserve(10001);
	memo.reserve(10001);
	for(int c=1;c<=C;c++){
		cin>>N;

		for(int i=1;i<=N;i++)
			cin>>input[i];
		for(int i=1;i<=N;i++)
			memo[i]=-1;

		if(N==0)
			ans=0;
		else
			ans=farida(N);		
		cout<<"Case "<<c<<": "<<ans<<"\n";
	}
}