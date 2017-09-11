#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int n;
	while(1){
		cin>>n;
		if(n==0) break;
		cout<<(int)log2(n)<<"\n";
	}
}