#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	string input,sub,temp;
	unordered_set<string> Set;
	bool magic;
	while(t--){
		cin>>input;
		magic = true;
		for(int i=0;i<input.size();i++){
			sub = "";
			for(int j=i;j<input.size();j++){
				sub.push_back(input[j]);
				Set.insert(sub);
			}
		}
		for(auto x:Set){
			temp = x;
			reverse(temp.begin(),temp.end());
			if(Set.find(temp)==Set.end()){
				magic = false;
				break;
			}
		}
		Set.clear();

		if(!magic) cout<<"NO\n";
		else cout<<"YES\n";
	}
}