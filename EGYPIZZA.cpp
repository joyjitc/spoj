#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int half=0,quat=0,third=0;
	int n;
	cin>>n;
	string inp;
	for(int i=0;i<n;i++){
		cin>>inp;
		if(inp[0]=='3')
			third++;
		else if(inp[2]=='2')
			half++;
		else
			quat++;
	}
	// cout<<quat<<" "<<half<<" "<<third<<endl;
	int ans = 1;
	ans+=half/2;
	// if(half%2==0)
	// 	half=0;
	// else
	// 	half=1;
	half=half%2;

	if(third>quat){
		ans+=quat;
		third-=quat;
		// quat=0;
		ans += third+half;
	}
	else if(third==quat){
		ans+=third+half;
	}
	else if(third<quat){
		ans+=third;
		quat-=third;
		// third=0;
		ans+=quat/4;
		quat=quat%4;
		if(quat==3){
			ans++;
			ans+=half;
		}
		else if(quat==2||quat==1)
			ans++;
		else
			ans+=half;
	}
	cout<<ans<<"\n";
}