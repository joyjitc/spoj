#include<iostream>
#include<algorithm>
#include<vector>
typedef unsigned long long ull;
using namespace std;
int n,b;
vector<int> p;
bool bCheck(int pPerBallot){
	ull ballotsRequired = 0;
	for(int x:p){
		ballotsRequired+=x/pPerBallot;
		if(x%pPerBallot!=0) ballotsRequired++;
	}
	if(ballotsRequired<=b) return 1;
	else return 0;
}
int main(){
	ios::sync_with_stdio(0);
	
	while(1){
		cin>>n>>b;
		if(n==-1&&b==-1) break;
		p.resize(n);
		for(int i=0;i<n;i++) cin>>p[i];
		sort(p.begin(),p.end());
		int l = 1, r = p.back();
		int mid;
		while(l<r){
			mid = l + (r-l)/2;
			if(bCheck(mid)==0) l=mid+1;
			else r=mid;
		}
		cout<<l<<"\n";
	}
}