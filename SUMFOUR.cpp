#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	cin>>n;
	int a[n][4];
	for(int i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];
	}
	vector<int> a_plus_b,c_plus_d;
	a_plus_b.reserve(n*n);
	c_plus_d.reserve(n*n);
	int apb,cpd;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			apb=a[i][0]+a[j][1];
			cpd=a[i][2]+a[j][3];
			a_plus_b.push_back(apb);
			c_plus_d.push_back(cpd);
		}
	}
	unsigned long long ans=0;
	sort(a_plus_b.begin(),a_plus_b.end());
	sort(c_plus_d.begin(),c_plus_d.end());
	pair<vector<int>::iterator,vector<int>::iterator> lhs,rhs;
	vector<int>::iterator it = a_plus_b.begin();
	while(it!=a_plus_b.end()){
		lhs = equal_range(a_plus_b.begin(),a_plus_b.end(),*it);
		rhs = equal_range(c_plus_d.begin(),c_plus_d.end(),-1*(*it));
		ans += (lhs.second-lhs.first)*(rhs.second-rhs.first);
		it = lhs.second;
	}
	cout<<ans<<"\n";
}
