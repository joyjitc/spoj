#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int t,n;
	cin>>t;
	int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43};
	vector<unsigned long long> a;
	int set_bit,pos,num;
	unsigned long long val;
	for(int x=0;x<2048;x++){
		val = 1;
		set_bit=0;
		pos = 0;
		num = x;
		while(num!=0){
			if(num&1){
				val=val*prime[pos];
				set_bit++;
			}
			num=num>>1;
			pos++;			
		}
		if(set_bit>=3)
			a.push_back(val);

	}
	sort(a.begin(),a.end());
	while(t--){
		cin>>n;
		cout<<a[n-1]<<"\n";	
	}
}
