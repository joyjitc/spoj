#include <iostream>
using namespace std;
//Solution using Greedy Paradigm
int main(){
	ios::sync_with_stdio(0);
	int t,ans,h,a;
	cin>>t;
	while(t--){
		cin>>h>>a;
		ans=1;
		h+=3,a+=2;
		while(1){
			if(h>20&&a<=10) h-=17,a+=7,ans+=2;
			else if(h>5&&a>10) h-=2,a-=8,ans+=2;
			else break;
		}
		cout<<ans<<"\n";
	}	
}