#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
//	cin.tie(0);
	int t,x,y;
	cin>>t;
	int temp,div,ans;
	bool flag;
	int g;
	while(t--){
		cin>>x>>y;
		if(x==y){
			cout<<"0\n";
			continue;
		}
		if(x==0||y==0){
			cout<<"1\n";
			continue;
		}
		if(x<0&&y<0){
			x*=-1;
			y*=-1;
		}
		flag=false;
		if(x<0){
			flag=true;
			x*=-1;
		}
		if(y<0){
			flag=true;
			y*=-1;
		}
		if(x==y){
			cout<<"2\n";
			continue;
		}
		g=__gcd(x,y);
		x/=g;y/=g;
		if(x<y){
			temp=x;x=y;y=temp;
		}
		ans=0;
		temp=x;
		while(1){
			ans+=temp/y;
			div=temp%y;
			temp=(div==0?0:x-y+div);
			if(flag)
				ans+=2;
			if(temp==0)
				break;
		}
		cout<<ans-1<<"\n";
	}
}
