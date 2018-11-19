#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,bool>& a, pair<int,bool>& b){
	return a.first<b.first;
}

int main(){
	ios::sync_with_stdio(0);
	int d,n;
	cin>>d;
	int a,b;
	vector<pair<int,bool> > t;
	int ans,cur;
	while(d--){
		ans= 0, cur =0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a>>b;
			t.push_back(pair<int,bool>(a,0));
			t.push_back(pair<int,bool>(b,1));
		}
		sort(t.begin(),t.end(),comp);
		for(auto x:t){
			if(x.second==0)
				cur++;
			else if(x.second==1)
				cur--;
			ans = max(ans,cur);
		}
		cout<<ans<<"\n";
		t.clear();
	}
}
