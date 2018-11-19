#include<bits/stdc++.h>
using namespace std;
int main(){
		ios::sync_with_stdio(0);
		int n,x;
		cin>>n;
		vector<int> v;
		for(int i=0;i<n;i++){
			cin>>x;
			v.push_back(x);
		}
		sort(v.begin(),v.end());
		vector<int> diff;
		for(int i=1;i<n;i++)
			diff.push_back(v[i]-v[i-1]);
		int hcf = diff[0];
		for(int i=1;i<diff.size();i++)
			hcf=__gcd(hcf,diff[i]);
		int ans=0;
		for(int x:diff)
			ans+=x/hcf-1;
		cout<<ans<<"\n";
}


        	
