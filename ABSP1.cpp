#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int t,n,temp;
	vector<int> v;
	cin>>t;
	unsigned long long ans,diff;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>temp;
			v.push_back(temp);
		}
		diff=0;
		for(int i=1;i<n;i++)
			diff+=v[i]-v[0];
		ans = diff;
		for(int i=1;i<n;i++){
			diff-=(n-i)*(v[i]-v[i-1]);
			ans+=diff;
		}
		cout<<ans<<"\n";
		v.clear();
	}
}
