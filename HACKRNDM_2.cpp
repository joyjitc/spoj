#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int num, sum,temp;
	cin>>num>>sum;
	vector<int> v;
	for(int i=0;i<num;i++){
		cin>>temp;
		v.push_back(temp);
	}
	int ans = 0;
	sort(v.begin(),v.end());
	for(auto x:v)
		if(binary_search(v.begin(),v.end(),x+sum))
			ans++;
	cout<<ans<<"\n";
}
