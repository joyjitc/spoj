#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int a,b;
		vector<pair<int,int>> v;
		v.push_back(pair<int,int>(0,0));
		while(n--){
			cin>>a>>b;
			v.push_back(pair<int,int>(a,b));
		}
		int max_pos,max_value=0,max_count;
		for(int i=1;i<v.size();i++){
			if(v[i].first>max_value){
				max_pos = i;
				max_value = v[i].first;
				max_count = 1;
			}
			else if(v[i].first==max_value)
				max_count++;
		}
		if(max_count>1){
			cout<<"-1\n";
			continue;
		}
		bool res = true;
		for(int i=1;i<v.size();i++){
			if(i!=max_pos){
				if(v[i].second>=max_value){
					res = false;
					break;
				}
			}
		}
		if(res)
			cout<<max_pos<<"\n";
		else 
			cout<<"-1\n";
	}
}