#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	int a,b;
	vector<int> A,B;
	int min_dif;
	vector<int>::iterator it;
	while(t--){
		min_dif = INT_MAX;
		cin>>a;
		A.resize(a);
		for(int i=0;i<a;i++) cin>>A[i];
		cin>>b;
		B.resize(b);
		for(int i=0;i<b;i++) cin>>B[i];
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		for(auto x:B){
			it = lower_bound(A.begin(),A.end(),x);
			if(it==A.begin()) min_dif = min(min_dif,abs(x-(*it)));
			else if(it==A.end()) min_dif = min(min_dif,abs(x-*(it-1)));
			else{
				min_dif = min(min_dif,abs(x-(*it)));
				min_dif = min(min_dif,abs(x-*(it-1)));
			}
			if(min_dif==0) break;
		}
		cout<<min_dif<<"\n";
	}
}