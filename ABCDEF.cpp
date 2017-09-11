#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	cin>>n;
	int temp;
	vector<int> set;
	set.reserve(n);
	for(int i=0;i<n;i++){
		cin>>temp;
		set.push_back(temp);
	}
	unordered_map<int,int> LHS,RHS;	
	for(int a:set){
		for(int b:set){
			for(int c:set){
				temp=a*b+c;
				if(LHS.find(temp)==LHS.end())
					LHS[temp]=1;
				else
					LHS[temp]++;
			}
		}
	}
	for(int d:set){
		if(d!=0)
			for(int e:set){
				for(int f:set){
					temp=d*(e+f);
					if(RHS.find(temp)==RHS.end())
						RHS[temp]=1;
					else
						RHS[temp]++;
				}
			}
	}
	unsigned long long ans=0;
	for(auto x:LHS){
		if(RHS.find(x.first)!=RHS.end())
			ans+=LHS[x.first]*RHS[x.first];
	}
	cout<<ans<<"\n";

}
