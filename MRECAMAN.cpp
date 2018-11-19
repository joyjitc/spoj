#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int n;
	vector<int> rec(500001);
	rec[0]=0;
	unordered_set<int> s;
	s.insert(0);
	for(int i=1;i<=500000;i++){
		n = rec[i-1]-i;
		if(n<0||s.find(n)!=s.end())
			n=rec[i-1]+i;
		s.insert(n);
		rec[i]=n;	
	}
	while(1){
		cin>>n;
		if(n==-1)
			break;
		else
			cout<<rec[n]<<"\n";
	}
}
