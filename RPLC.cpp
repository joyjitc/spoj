#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int t,temp,n;
	unsigned long long ans;
	vector<int> v;
	cin>>t;
	int index = 1;
	while(t--){
		ans=1;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>temp;
			v.push_back(temp);
		}
		temp=1;
		for(int i=0;i<n;i++){
			temp+=v[i];
			if(temp<=0){
				ans+=1-temp;
				temp=1;
			}
		}
		cout<<"Scenario #"<<index++<<": "<<ans<<"\n";
		v.clear();
	}
}
