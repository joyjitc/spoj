#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int n,temp;
	unsigned long long ans;
	vector<unsigned long long> c,p;
	while(1){
		cin>>n;
		if(n==0)
			break;
		ans = 0;
		for(int i=0;i<n;i++){
			cin>>temp;
			c.push_back(temp);
		}
		for(int i=0;i<n;i++){
			cin>>temp;
			p.push_back(temp);
		}
		sort(c.begin(),c.end(),greater<int>());
		sort(p.begin(),p.end());
		for(int i=0;i<n;i++)
			ans+=c[i]*p[i];
		cout<<ans<<"\n";
		c.clear();
		p.clear();
	}
}
