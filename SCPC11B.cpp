#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int temp;
	int n;
	while(1){
		cin>>n;
		if(n==0)
			break;
		vector<int> v;
		for(int i=0;i<n;i++){
			cin>>temp;
			v.push_back(temp);
		}
		sort(v.begin(),v.end());
		bool flag = 1;
		for(int i=1;i<n;i++){
			if(v[i]-v[i-1]>200){
				flag=0;
				break;
			}
		}
		if(1422-v[n-1]>100)
			flag=0;
		if(flag)
			cout<<"POSSIBLE\n";
		else
			cout<<"IMPOSSIBLE\n";
	}
}

