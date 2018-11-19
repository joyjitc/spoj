#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int n,k;
	int x;
	long long ans;
	int case_id=1;
	int exp;
	while(1){
		cin>>n;
		if(n==-1)
			break;
		cout<<"Case "<<case_id<<":\n";
		case_id++;
		vector<int> c;
		c.resize(n+1);
		for(int i=n;i>=0;i--)
			cin>>c[i];
		cin>>k;
		while(k--){
			ans=0;
			exp=1;
			cin>>x;
			for(int i=0;i<=n;i++){
				ans+=c[i]*exp;
				exp*=x;
			}
			cout<<ans<<"\n";
		}

	}

}