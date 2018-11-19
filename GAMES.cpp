#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	int num;
	string inp;
	bool point;
	int i,j,x;
	while(t--){
		cin>>inp;
		for(j=0;j<inp.size();j++)
			if(inp[j]=='.')
				break;
		num=0;
		for(i=j+1;i<inp.size();i++)
			num=num*10+inp[i]-'0';
		int lim=pow(10,inp.size()-1-j);
		for(x=1;x<=lim;x++)
			if((num*x)%lim==0)
				break;
		cout<<x<<"\n";
	}
}


