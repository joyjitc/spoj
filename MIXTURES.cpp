#include <bits/stdc++.h>
using namespace std;
class Mix{
public: 
	int val;
	int smoke;
	Mix(){
		val=-1;
		smoke=0;
	}
	Mix(int val_,int smoke_){
		val = val_;
		smoke = smoke_;
	}
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	vector<int> mix;
	mix.reserve(100);
	vector<vector<Mix> > memo;
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>mix[i];
		}
		memo.resize(n,vector<Mix>(n));

		memo.clear();
	}
}