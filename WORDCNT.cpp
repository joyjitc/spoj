#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int t;cin>>t;
	string line,word;
	int prev_sz,cnt,max_cnt;
	getline(cin,line);
	while(t--){
		getline(cin,line);
		istringstream iss(line);
		prev_sz=0,cnt=0,max_cnt=0;
		while(iss>>word){
			if(word.size()==prev_sz){
				cnt++;
			}
			else{
				cnt=1;
				prev_sz=word.size();
			}
			max_cnt=max(max_cnt,cnt);
		}
		cout<<max_cnt<<"\n";
	}
}