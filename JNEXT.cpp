#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		vector<int> num;
		int dig;
		for(int i=0;i<n;i++){
			cin>>dig;
			num.push_back(dig);
		}
		bool imp = true;
		int i;
		for(i=n-1;i>0;i--){
			if(num[i-1]<num[i]){
				imp = false;
				break;
			}
		}
		if(imp){
			cout<<"-1\n";
			continue;
		}
		int j;
		sort(num.begin()+i,num.end());
		for(j=i;j<n;j++){
			if(num[j]>num[i-1])
				break;
		}
		int t=num[j];
		num[j]=num[i-1];
		num[i-1]=t;

		sort(num.begin()+i,num.end());
		for(int& x:num) cout<<x;
		cout<<"\n";
	}
}
