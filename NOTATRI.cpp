#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int n;
	vector<int> a;
	int temp,ans;
	while(1){
		cin>>n;
		if(n==0) break;
		for(int i=0;i<n;i++){
			cin>>temp;
			a.push_back(temp);
		}
		ans=0;
		sort(a.begin(),a.end());
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				ans+=a.end()-upper_bound(a.begin(),a.end(),a[i]+a[j]);
		cout<<ans<<"\n";
		a.clear();
	}
}
