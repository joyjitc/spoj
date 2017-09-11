#include <bits/stdc++.h>

using namespace std;

struct task{
	int begin;
	int end;
	task(int a, int b):begin(a),end(b) {}
};
bool comp(task& first, task& second){
	return first.end<second.end;
}
int main(){
	ios::sync_with_stdio(0);
	int t,n;
	cin>>t;
	int a,b;
	int cur_last, count;
	while(t--){
		vector<task> v;
		cin>>n;
		while(n--){
			cin>>a>>b;
			v.push_back(task(a,b));
		}
		count = cur_last = 0;
		sort(v.begin(),v.end(),comp);
		for(auto x:v){
			if(x.begin>=cur_last){
				count++;
				cur_last = x.end;
			}
		}
		cout<<count<<"\n";
	}


}