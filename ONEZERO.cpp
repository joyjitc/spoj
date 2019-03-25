#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
unordered_set<int> uSet;
int t,n;
string ans;
void bfs(){
	uSet.clear();
	list<pair<string,int> > q;
	q.push_back(pair<string,int>("1",1));
	string fir;
	int sec;
	while(!q.empty()){
		fir = q.front().first;
		sec = q.front().second;
		sec = sec%n;
		if(uSet.count(sec)!=0){
			q.pop_front();
			continue;
		}
		if(sec==0){
			ans = fir;
			return;
		}
		uSet.insert(sec);
		q.pop_front();
		q.push_back(pair<string,int>(fir + "0",sec*10));
		q.push_back(pair<string,int>(fir + "1",sec*10+1));
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		bfs();
		cout<<ans<<"\n";
	}
}