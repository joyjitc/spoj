#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	int N,C;
	vector<int> inp;
	int mid;
	while(t--){
		cin>>N>>C;
		inp.resize(N+1);
		inp[0] = -1;
		for(int i=1;i<=N;i++)
			cin>>inp[i];
		sort(inp.begin(), inp.end());
		int hi = inp[N]-inp[1];
		int lo = 1000000001;
		for(int i=2;i<=N;i++)
			lo = min(lo,inp[i]-inp[i-1]);
		// cout<<"DEBUG:"<<hi<<" "<<lo<<endl;
		while(lo<hi){
			mid = lo + (hi-lo+1)/2;
			// cout<<"mid:"<<mid<<endl;
			int max_cow = 0;
			int last_loc = inp[1];
			max_cow++;
			for(int i=2;i<=N;i++){
				if(inp[i]-last_loc>=mid){
					max_cow++;
					last_loc = inp[i];
				}
			}
			if(max_cow>=C)
				lo = mid;
			else
				hi = mid-1;
		}
		cout<<lo<<"\n";
	}
}