#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int n, k;
	vector<int> data;
	cin>>n;
	data.reserve(n);
	for(int i=0;i<n;i++) cin>>data[i];
	cin>>k;
	deque<int> q;
	for(int j=0;j<k;j++){
		while(!q.empty()&&q.back()<data[j]) q.pop_back();
		q.push_back(data[j]);
	}
	int i=0,j=k-1;
	while(1){
		cout<<q.front()<<" ";
		if(i==n-k) break;
		// cout<<" ";
		if(q.front()==data[i]) q.pop_front();
		i++; j++;
		while(!q.empty()&&q.back()<data[j]) q.pop_back();
		q.push_back(data[j]);
	}
	// cout<<"\n";
	return 0;
}