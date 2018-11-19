#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int n;
	string line;
	int dig;
	vector<int> num;
	long long ans;
	int exp;
	while(1){
		cin>>n;
		if(n==0)
			break;
		cin.ignore();
		while(n--){
			getline(cin,line);
			dig=0;
			for(char& x:line){
				switch(x){
					case '.':dig++;break;
					case '-':dig+=5;break;
				}
			}
			num.push_back(dig);
		}
		ans=0;
		reverse(num.begin(),num.end());
		exp=1;
		for(int i=0;i<num.size();i++){
			ans += exp*num[i];
			if(i==1) exp*=18;
			else exp*=20;
		}
		cout<<ans<<"\n";
		num.clear();
	}

}