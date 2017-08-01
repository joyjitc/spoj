#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n, k;
	vector<int> data;
	cin>>n;
	data.reserve(n);
	for(int i=0;i<n;i++) cin>>data[i];
	cin>>k;
	int max_val;
	for(int i=0;i<=n-k;i++){
		max_val = data[i];
		for(int j=i+1;j<i+k;j++) max_val = max(max_val,data[j]);
		cout<<max_val<<" ";
	}
	return 0;
}