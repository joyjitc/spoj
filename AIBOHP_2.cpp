#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > memo;
int min_ins(string s);
int min_insert(string& s,int i,int j);

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	string s;

	while(t--){
		cin>>s;
		// cout<<s.size()<<endl;
		cout<<min_ins(s)<<endl;
		memo.clear();
	}
}
int min_ins(string s){
	memo.resize(s.size(),vector<int>(s.size(),-1));
	return min_insert(s,0,s.size()-1);
}
int min_insert(string& s,int i,int j){
	if(j<i)
		return 0;
	else if(memo[i][j]!=-1)
		return memo[i][j];
	else{
		if(s[i]==s[j]){
			memo[i][j]=min_insert(s,i+1,j-1);
		}
		else{
			memo[i][j]=1+min(min_insert(s,i+1,j),min_insert(s,i,j-1));
		}
		return memo[i][j];
	}
}
