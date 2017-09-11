#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int a,b;
	vector<int> A,B;
	int max_sum;
	int sum_a,sum_b;
	while(1){
	
		cin>>a;
		if(a==0) break;

		A.resize(a);
		for(int i=0;i<a;i++) cin>>A[i];

		cin>>b;
		B.resize(b);
		for(int i=0;i<b;i++) cin>>B[i];

		auto end_it = A.end();
		max_sum = sum_b =sum_a= 0;

		for(int x=b-1;x>=0;x--){
			sum_b+=B[x];
			if(!binary_search(A.begin(),end_it,B[x])) continue;
			else{
				auto found = lower_bound(A.begin(), end_it, B[x]);
				for(auto it = end_it-1;it!=found-1;it--) sum_a+=(*it);
				max_sum+= max(sum_a,sum_b);
				sum_a=sum_b=0;
				end_it = found;
			}				
		}
		// auto it = end_it;
		// do{
		// 	it--;
		// 	sum_a+=(*it);			
		// }while(it!=A.begin());
		for(auto it = end_it-1;it>=A.begin();it--) sum_a+=(*it);
		max_sum+= max(sum_a,sum_b);
		cout<<max_sum<<"\n";
	}
}