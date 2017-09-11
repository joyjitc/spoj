#include <bits/stdc++.h>
using namespace std;
unsigned long long max_ll(unsigned long long a, unsigned long long b){
	if(a>b) return a;
	else return b;
}
int main(){
	ios::sync_with_stdio(0);
	int n;
	vector<unsigned long long> h;
	unsigned long long max_area;
	unsigned long long val;
	unsigned long long cur_val;
	while(1){
		cin>>n;
		if(n==0) break;
		for(int i=0;i<n;i++){
			cin>>val;
			h.push_back(val);
		}
		stack<int> s;
		h.push_back(0);
		s.push(0);
		max_area=0;
		for(int i=1;i<h.size();i++){
			if(s.empty()||h[i]>=h[s.top()])
				s.push(i);
			else{
				while(!s.empty()&&h[s.top()]>h[i]){
					cur_val = h[s.top()];
					s.pop();
					max_area = max_ll(max_area,cur_val*(s.empty()?i:i-1-s.top()));
				}
				s.push(i);
			}
		}
		cout<<max_area<<"\n";
		h.clear();
	}
}