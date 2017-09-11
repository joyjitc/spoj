#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int t;
	cin>>t;
	string input;
	vector<string> v;
	string sub;
	int ans;
	while(t--){
		cin>>input;
		for(int i=0;i<input.size();i++){
			sub.clear();
			for(int j=i;j<input.size();j++){
				sub.push_back(input[j]);
			}
			v.push_back(sub);
		}
		sort(v.begin(),v.end());
		ans = 0;
		int y;
		int i;
		for(int x=0;x<v.size()-1;x++){
			y=x+1;
			i=0;
			while(i<v[x].size()&&i<v[y].size()){
				if(v[x][i]==v[y][i]) i++;
				else break;
			}
			ans+=v[x].size()-i;
		}
		ans+=v[v.size()-1].size();
		cout<<ans<<"\n";
		v.clear();
	}

}
